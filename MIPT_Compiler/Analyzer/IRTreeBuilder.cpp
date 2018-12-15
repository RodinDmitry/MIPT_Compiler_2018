#include <IRTreeBuilder.h>

void CIRTreeBuilder::visit(ITree*)
{
	assert(false);
}

void CIRTreeBuilder::visit(CArgumentList *)
{
}

void CIRTreeBuilder::visit(CClassDeclaration *)
{
}

void CIRTreeBuilder::visit(CClassInternals *)
{
}

void CIRTreeBuilder::visit(CClassInternalsList *)
{
}

void CIRTreeBuilder::visit(CClass *)
{
}

void CIRTreeBuilder::visit(CClassList *)
{
}

void CIRTreeBuilder::visit(IExpression*)
{
	assert(false);
}

void CIRTreeBuilder::visit(CExpressionList *)
{
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

void CIRTreeBuilder::visit(CCallExpression *)
{
}

void CIRTreeBuilder::visit(CValueExpression *)
{
}

void CIRTreeBuilder::visit(CNewArrayExpression *)
{
}

void CIRTreeBuilder::visit(CNewExpression *)
{
}

void CIRTreeBuilder::visit(CIdExpression *)
{
}

void CIRTreeBuilder::visit(CThisExpression *)
{
}

void CIRTreeBuilder::visit(CNotExpression *)
{
}

void CIRTreeBuilder::visit(CBracketsExpression *)
{
}

void CIRTreeBuilder::visit(CReturnExpression *)
{
}

void CIRTreeBuilder::visit(CFunction *)
{
}

void CIRTreeBuilder::visit(CId *)
{
}

void CIRTreeBuilder::visit(CMainArgument *)
{
}

void CIRTreeBuilder::visit(CMainFunction *)
{
}

void CIRTreeBuilder::visit(CMain *)
{
}

void CIRTreeBuilder::visit(CModifier *)
{
}

void CIRTreeBuilder::visit(CProgram *)
{
}

void CIRTreeBuilder::visit(IStatement*)
{
	assert(false);
}

void CIRTreeBuilder::visit(CStatementList *)
{
}

void CIRTreeBuilder::visit(CVisibilityStatement *)
{
}

void CIRTreeBuilder::visit(CIfStatement *)
{
}

void CIRTreeBuilder::visit(CWhileStatement *)
{
}

void CIRTreeBuilder::visit(CPrintStatement *)
{
}

void CIRTreeBuilder::visit(CAssignStatement* node)
{
	node->left->Accept(this);
	std::shared_ptr<IR::ITreeWrapper> leftTree = subtree;
	node->right->Accept(this);
	std::shared_ptr<IR::ITreeWrapper> rightTree = subtree;

	updateSubtree(new IR::CStatementWrapper(new IR::CMoveStatement(leftTree->ToExpression(),rightTree->ToExpression())));
}

void CIRTreeBuilder::visit(CVariableStatement*)
{
}

void CIRTreeBuilder::visit(CType*)
{
}

void CIRTreeBuilder::visit(IValue*)
{
}

void CIRTreeBuilder::visit(CValue *)
{
}

void CIRTreeBuilder::visit(CVariable *)
{
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

void CIRTreeBuilder::updateSubtree(IR::ITreeWrapper* tree)
{
	updateSubtree(std::shared_ptr<IR::ITreeWrapper>(tree));
}

void CIRTreeBuilder::updateSubtree(std::shared_ptr<IR::ITreeWrapper> tree)
{
	subtree = tree;
}
