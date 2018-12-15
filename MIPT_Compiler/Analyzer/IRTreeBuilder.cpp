#include <IRTreeBuilder.h>

void CIRTreeBuilder::visit(ITree *)
{
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

void CIRTreeBuilder::visit(IExpression *)
{
}

void CIRTreeBuilder::visit(CExpressionList *)
{
}

void CIRTreeBuilder::visit(CLValueExpression *)
{
}

void CIRTreeBuilder::visit(CBinaryExpression *)
{
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

void CIRTreeBuilder::visit(IStatement *)
{
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

void CIRTreeBuilder::updateSubtree(IR::ITreeWrapper* tree)
{
	updateSubtree(std::shared_ptr<IR::ITreeWrapper>(tree));
}

void CIRTreeBuilder::updateSubtree(std::shared_ptr<IR::ITreeWrapper> tree)
{
	subtree = tree;
}
