#include <Synthesis/Tiling.h>

namespace Synthesis {
void CTilingVisitor::visit(const IR::ITree* node)
{
	assert(false);
}
void CTilingVisitor::visit(const IR::IExpression* node)
{
	assert(false);
}
void CTilingVisitor::visit(const IR::CExpressionList* node)
{
	const std::vector<std::shared_ptr<const IR::IExpression>>& expressions = node->Get();
	for (int i = 0; i < expressions.size(); i++) {
		expressions[i]->Accept(this);
	}
	ApplyPatterns(node);
}
void CTilingVisitor::visit(const IR::CConstExpression* node)
{
	ApplyPatterns(node);
}
void CTilingVisitor::visit(const IR::CNameExpression* node)
{
	ApplyPatterns(node);
}
void CTilingVisitor::visit(const IR::CTempExpression* node)
{
	ApplyPatterns(node);
}
void CTilingVisitor::visit(const IR::CBinaryExpression* node)
{
	node->LeftOperand()->Accept(this);
	node->RightOperand()->Accept(this);
	ApplyPatterns(node);
}
void CTilingVisitor::visit(const IR::CMemExpression* node)
{
	node->Get()->Accept(this);
	ApplyPatterns(node);
}
void CTilingVisitor::visit(const IR::CCallExpression* node)
{
	node->Arguments()->Accept(this);
	node->Function()->Accept(this);
	ApplyPatterns(node);
}
void CTilingVisitor::visit(const IR::CEseqExpression* node)
{
	assert(false);
}
void CTilingVisitor::visit(const IR::IStatement* node)
{
	assert(false);
}
void CTilingVisitor::visit(const IR::CMoveStatement* node)
{
	node->Destination()->Accept(this);
	node->Source()->Accept(this);
	ApplyPatterns(node);
}
void CTilingVisitor::visit(const IR::CExpStatement* node)
{
	node->Expression()->Accept(this);
	ApplyPatterns(node);
}
void CTilingVisitor::visit(const IR::CJumpStatement* node)
{
	ApplyPatterns(node);
}
void CTilingVisitor::visit(const IR::CJumpConditionalStatement* node)
{
	node->Left()->Accept(this);
	node->Right()->Accept(this);
	ApplyPatterns(node);
}
void CTilingVisitor::visit(const IR::CSeqStatement* node)
{
	assert(false);
}
void CTilingVisitor::visit(const IR::CLabelStatement* node)
{
	ApplyPatterns(node);
}
void CTilingVisitor::visit(const IR::CStatementList* node)
{
	assert(false);
}
} // namespace Synthesis