#include <IRTreeBuilder.h>
#include <SymbolTable.h>
#include <FunctionInfo.h>
#include <ClassInfo.h>
#include <IR/IRStatement.h>

std::shared_ptr<std::map<const CSymbol*, std::shared_ptr<IR::ITreeWrapper>>> CIRTreeBuilder::BuildIRTree(ITree * tree, const std::string& _symbolTableName)
{
	symbolTableName = _symbolTableName;
	methods.reset(new std::map<const CSymbol*, std::shared_ptr<IR::ITreeWrapper>>());
	tree->Accept(this);
	return methods;
}

void CIRTreeBuilder::visit(ITree*)
{
	assert(false);
}

void CIRTreeBuilder::visit(CArgumentList*)
{
	assert(false);
}

void CIRTreeBuilder::visit(CClassDeclaration* node)
{
	assert(false);
}

void CIRTreeBuilder::visit(CClassInternals* node)
{
	if (node->function != nullptr) {
		node->function->Accept(this);
	}
}

void CIRTreeBuilder::visit(CClassInternalsList* node)
{
	const std::vector<std::shared_ptr<CClassInternals>>& internals = node->internals;
	
	for (int i = static_cast<int>(internals.size()) - 1; i >= 0; i--) {
		internals[i]->Accept(this);
		if (internals[i]->function != nullptr) {
			std::string methodName = makeMethodName(currentClassName, currentFrame->GetFunctionName());
			(*methods)[CSymbol::GetSymbol(methodName)] = subtree;
		}
	}
}

void CIRTreeBuilder::visit(CClass* node)
{
	currentClassName = node->declaration->name->name;
	node->internals->Accept(this);
}

void CIRTreeBuilder::visit(CClassList* node)
{
	for (int i = static_cast<int>(node->classes.size()) - 1; i >= 0; i--) {
		node->classes[i]->Accept(this);
	}
}

void CIRTreeBuilder::visit(IExpression*)
{
	assert(false);
}

void CIRTreeBuilder::visit(CExpressionList*)
{
	assert(false);
}

void CIRTreeBuilder::visit(CLValueExpression*)
{
	assert(false);
}

void CIRTreeBuilder::visit(CBinaryExpression* node)
{
	node->left->Accept(this);
	std::shared_ptr<IR::ITreeWrapper> left = subtree;
	node->right->Accept(this);
	std::shared_ptr<IR::ITreeWrapper> right = subtree;

	switch (node->operation)
	{
	case CBinaryExpression::O_And: 
	{
		updateSubtree(new IR::CAndConditionalWrapper(left, right));
		break;
	}
	case CBinaryExpression::O_Or: 
	{
		updateSubtree(new IR::COrConditionalWrapper(left, right));
		break;
	}
	case CBinaryExpression::O_Less:
	case CBinaryExpression::O_More:
	{
		updateSubtree(new IR::CRelativeConditionalWrapper(convertOperatorLogic(node->operation),
			left->ToExpression(), right->ToExpression()));
		break;
	}
	default: 
	{
		updateSubtree(new IR::CExpressionWrapper(new IR::CBinaryExpression(convertOperator(node->operation),
			left->ToExpression(), right->ToExpression())));
		break;
	}
	}
}

void CIRTreeBuilder::visit(CArrayExpression* node)
{
	node->caller->Accept(this);
	std::shared_ptr<const IR::IExpression> arrayStart = subtree->ToExpression();
	node->index->Accept(this);
	std::shared_ptr<const IR::IExpression> offset = subtree->ToExpression();
	std::shared_ptr<const IR::IExpression> offsetExpr(new IR::CBinaryExpression(
		IR::TOperator::O_Multiplication, offset, currentFrame->GetWordSize()));
	updateSubtree(new IR::CExpressionWrapper(new IR::CBinaryExpression(IR::O_Plus, arrayStart, offset)));
}

void CIRTreeBuilder::visit(CCallExpression* node)
{
	node->caller->Accept(this);
	std::string methodCaller = callerClassName;
	
	IR::CExpressionList* expressionList = new IR::CExpressionList();
	expressionList->Add(subtree->ToExpression());

	const std::vector<std::shared_ptr<IExpression>>& expressions = node->list->expressions;

	for (int i = static_cast<int>(expressions.size()) - 1; i >= 0; i--) {
		expressions[i]->Accept(this);
		expressionList->Add(subtree->ToExpression());
	}

	updateSubtree(new IR::CExpressionWrapper(new IR::CCallExpression(
		new IR::CNameExpression(IR::CLabel(makeMethodName(methodCaller, node->function->name))), expressionList)));

	const CClassInfo* info = CSymbolTable::FindClass(symbolTableName, CSymbol::GetSymbol(methodCaller));
	const CFunctionInfo* functionInfo = info->FindMethod(CSymbol::GetSymbol(node->function->name));
	std::shared_ptr<const CType> type = std::make_shared< const CType>(*(functionInfo->GetType()));
	if (type->type == TDataType::DT_Instance) {
		callerClassName = type->instance;
	}
}

void CIRTreeBuilder::visit(CValueExpression* node)
{
	node->value->Accept(this);
}

void CIRTreeBuilder::visit(CNewArrayExpression* node)
{
	node->expression->Accept(this);

	std::shared_ptr<const IR::IExpression> expressionLength = subtree->ToExpression();


	IR::IExpression* total_size = new IR::CBinaryExpression(IR::TOperator::O_Multiplication, 
		std::shared_ptr<const IR::IExpression>(new IR::CBinaryExpression(IR::TOperator::O_Plus,
		std::shared_ptr<const IR::IExpression>(new IR::CConstExpression(1)), expressionLength)), currentFrame->GetWordSize());

	updateSubtree(new IR::CExpressionWrapper(currentFrame->ExternalCall("malloc", std::shared_ptr<const IR::CExpressionList>(
		new IR::CExpressionList(total_size)))));

}

void CIRTreeBuilder::visit(CNewExpression* node)
{
	const CClassInfo* info = CSymbolTable::FindClass(symbolTableName, CSymbol::GetSymbol(node->id->name));
	int classSize = info->GetSize();

	IR::IExpression* total_size = new IR::CBinaryExpression(IR::TOperator::O_Multiplication, 
		std::shared_ptr<const IR::IExpression>(new IR::CConstExpression(classSize)), currentFrame->GetWordSize());
	//TODO
	updateSubtree(new IR::CExpressionWrapper(currentFrame->ExternalCall("malloc", std::shared_ptr<const IR::CExpressionList>(
		new IR::CExpressionList(total_size)))));

	callerClassName = node->id->name;

}

void CIRTreeBuilder::visit(CIdExpression* node)
{
	const IAccess* address = currentFrame->FindFormalorLocal(CSymbol::GetSymbol(node->id->name));
	updateSubtree(new IR::CExpressionWrapper(address->GetExp(currentFrame->GetFramePtr())));
}

void CIRTreeBuilder::visit(CThisExpression *)
{
	updateSubtree(new IR::CExpressionWrapper(currentFrame->GetThis()->GetExp(currentFrame->GetFramePtr())));
	callerClassName = currentClassName;
}

void CIRTreeBuilder::visit(CNotExpression* node)
{
	node->expression->Accept(this);
	updateSubtree(new IR::CNegateConditionalWrapper(subtree));
}

void CIRTreeBuilder::visit(CBracketsExpression* node)
{
	node->expression->Accept(this);
	updateSubtree(new IR::CExpressionWrapper(subtree->ToExpression()));
}

void CIRTreeBuilder::visit(CReturnExpression* node)
{
	node->expression->Accept(this);
}

void CIRTreeBuilder::visit(CFunction* node)
{
	currentFrame = node->GetFrame();
	std::string methodFullName = makeMethodName(currentClassName, node->name->name);
	node->body->Accept(this);
	std::shared_ptr<IR::ITreeWrapper> functionBody = subtree;

	node->returnExpression->Accept(this);
	std::shared_ptr<const IR::IExpression> returnExpression = subtree->ToExpression();

	updateSubtree(new IR::CStatementWrapper(new IR::CSeqStatement(new IR::CLabelStatement(IR::CLabel(methodFullName)),
		new IR::CSeqStatement(functionBody->ToStatement(), std::shared_ptr<const IR::IStatement>(
			new IR::CMoveStatement(currentFrame->GetReturn()->GetExp(currentFrame->GetFramePtr()), returnExpression))))));
}

void CIRTreeBuilder::visit(CId *)
{
	assert(false);
}

void CIRTreeBuilder::visit(CMainArgument *)
{
	assert(false);
}

void CIRTreeBuilder::visit(CMainFunction* node)
{
	currentFrame = node->GetFrame();
	node->body->Accept(this);
}

void CIRTreeBuilder::visit(CMain* node)
{
	node->mainFunction->Accept(this);
	currentClassName = node->name->name;
	std::string methodFullName = makeMethodName(currentClassName, currentFrame->GetFunctionName());
	std::shared_ptr<IR::ITreeWrapper> mainFunction = subtree;
	updateSubtree(new IR::CStatementWrapper(new IR::CSeqStatement(std::shared_ptr<const IR::IStatement>(
				new IR::CLabelStatement(IR::CLabel(methodFullName))), mainFunction->ToStatement())));

	(*methods)[CSymbol::GetSymbol(methodFullName)] = subtree;
}

void CIRTreeBuilder::visit(CModifier*)
{
	assert(false);
}

void CIRTreeBuilder::visit(CProgram* node)
{
	node->main->Accept(this);
	node->classes->Accept(this);
}

void CIRTreeBuilder::visit(IStatement*)
{
	assert(false);
}

void CIRTreeBuilder::visit(CStatementList* node)
{
	std::vector<std::shared_ptr<IStatement>> statements = node->statements;
	
	std::shared_ptr<IR::ITreeWrapper> suffix = nullptr;

	for (int i = 0; i < statements.size(); i++) {
		statements[i]->Accept(this);
		if (suffix == nullptr) {
			suffix = subtree;
		}
		else {
			suffix = std::shared_ptr<IR::ITreeWrapper>(new IR::CStatementWrapper(new IR::CSeqStatement(
				subtree->ToStatement(), suffix->ToStatement())));
		}
	}

	updateSubtree(suffix);
}

void CIRTreeBuilder::visit(CVisibilityStatement* node)
{
	node->statement->Accept(this);
}

void CIRTreeBuilder::visit(CIfStatement* node)
{
	node->condition->Accept(this);
	std::shared_ptr<IR::ITreeWrapper> condition = subtree;
	node->thenStatement->Accept(this);
	std::shared_ptr<IR::ITreeWrapper> conditionTrue = subtree;
	

	IR::CLabel labelTrue;
	IR::CLabel labelFalse;
	IR::CLabel labelJoin;

	IR::CLabel* resultLabelFalse = &labelJoin;

	std::shared_ptr<const IR::IStatement> suffix(new IR::CLabelStatement(labelJoin));

	if (node->elseStatement != nullptr) {
		resultLabelFalse = &labelFalse;
		node->elseStatement->Accept(this);
		std::shared_ptr<IR::ITreeWrapper> conditionFalse = subtree;

		suffix = std::shared_ptr<IR::IStatement>(new IR::CSeqStatement(new IR::CLabelStatement(labelFalse),
			new IR::CSeqStatement(conditionFalse->ToStatement(), suffix)));
		suffix = std::shared_ptr<IR::IStatement>(new IR::CSeqStatement(
			std::shared_ptr<IR::IStatement>(new IR::CJumpStatement(labelJoin)), suffix));
	}

	suffix = std::shared_ptr<IR::IStatement>(new IR::CSeqStatement(new IR::CLabelStatement(labelTrue), new IR::CSeqStatement(
		conditionTrue->ToStatement(), suffix)));

	updateSubtree(new IR::CStatementWrapper(new IR::CSeqStatement(condition->ToConditional(labelTrue, *resultLabelFalse),
		suffix)));
}

void CIRTreeBuilder::visit(CWhileStatement* node)
{
	node->condition->Accept(this);
	std::shared_ptr<IR::ITreeWrapper> condition = subtree;
	node->statement->Accept(this);
	std::shared_ptr<IR::ITreeWrapper> statement = subtree;

	IR::CLabel loop;
	IR::CLabel body;
	IR::CLabel done;

	std::shared_ptr<const IR::IStatement> suffix(new IR::CSeqStatement(new IR::CJumpStatement(loop), new IR::CLabelStatement(done)));


	suffix = std::shared_ptr <const IR::IStatement>(new IR::CSeqStatement(statement->ToStatement(), suffix));

	updateSubtree(new IR::CStatementWrapper(new IR::CSeqStatement(new IR::CLabelStatement(loop), new IR::CSeqStatement(
		condition->ToConditional(body, done), std::shared_ptr<const IR::IStatement>(
			new IR::CSeqStatement(std::shared_ptr<const IR::IStatement>(new IR::CLabelStatement(body)), suffix))))));
	
}

void CIRTreeBuilder::visit(CPrintStatement* node)
{
	node->expression->Accept(this);
	std::shared_ptr<IR::ITreeWrapper> wrapper = subtree;
	std::shared_ptr<IR::CExpressionList> arguments(new IR::CExpressionList(wrapper->ToExpression()));
	updateSubtree(new IR::CExpressionWrapper(currentFrame->ExternalCall("print", arguments)));
	
}

void CIRTreeBuilder::visit(CAssignStatement* node)
{
	node->left->Accept(this);
	std::shared_ptr<IR::ITreeWrapper> leftTree = subtree;
	node->right->Accept(this);
	std::shared_ptr<IR::ITreeWrapper> rightTree = subtree;

	updateSubtree(new IR::CStatementWrapper(new IR::CMoveStatement(leftTree->ToExpression(),rightTree->ToExpression())));
}

void CIRTreeBuilder::visit(CVariableStatement* node)
{
}

void CIRTreeBuilder::visit(CType*)
{
	assert(false);
}

void CIRTreeBuilder::visit(IValue*)
{
	assert(false);
}

void CIRTreeBuilder::visit(CValue* node)
{
	updateSubtree(new IR::CExpressionWrapper(new IR::CConstExpression(node->value)));
}

void CIRTreeBuilder::visit(CVariable*)
{
	assert(false);
}

void CIRTreeBuilder::visit(CCallLengthExpression* node)
{
	std::shared_ptr<IR::CExpressionList> arguments(new IR::CExpressionList());
	updateSubtree(new IR::CExpressionWrapper(currentFrame->ExternalCall("length", arguments)));
}

IR::TLogicOperatorType CIRTreeBuilder::convertOperatorLogic(CBinaryExpression::TOperator op)
{
	switch (op)
	{
	case CBinaryExpression::O_Less:
		return IR::TLogicOperatorType::LOT_LT;
	case CBinaryExpression::O_More:
		return IR::TLogicOperatorType::LOT_GT;
	default:
		assert(false);
		return IR::TLogicOperatorType();
	}
}

IR::TOperator CIRTreeBuilder::convertOperator(CBinaryExpression::TOperator op)
{
	switch (op)
	{
	case CBinaryExpression::O_Plus:
		return IR::TOperator::O_Plus;
	case CBinaryExpression::O_Minus:
		return IR::TOperator::O_Minus;
	case CBinaryExpression::O_Division:
		return IR::TOperator::O_Division;
	case CBinaryExpression::O_IntegerDivision:
		return IR::TOperator::O_IntegerDivision;
	case CBinaryExpression::O_Multiplication:
		return IR::TOperator::O_Multiplication;
	default:
		assert(false);
		return IR::TOperator();
	}
	
}

std::string CIRTreeBuilder::makeMethodName(const std::string & className, const std::string & methodName)
{
	return className + "@" + methodName;
}

void CIRTreeBuilder::updateSubtree(IR::ITreeWrapper* tree)
{
	updateSubtree(std::shared_ptr<IR::ITreeWrapper>(tree));
}

void CIRTreeBuilder::updateSubtree(std::shared_ptr<IR::ITreeWrapper> tree)
{
	subtree = tree;
}
