#include <IR/TraceBuilderVisitor.h>

namespace IR {

void CTraceBuilderVisitor::visit(const CJumpStatement* node)
{
	isJumpConditional = false;
	trueTargetLabel = node->Target().GetLabel();
}

void CTraceBuilderVisitor::visit(const CJumpConditionalStatement* node)
{
	isJumpConditional = true;
	trueTargetLabel = node->TrueLabel().GetLabel();
	falseTragetLabel = node->FalseLabel().GetLabel();
}

void CTraceBuilderVisitor::visit(const CLabelStatement* node)
{
	startLabel = node->Label().GetLabel();
}

void CTraceBuilderVisitor::visit(const CStatementList* node)
{
	node->Get().front()->Accept(this);
	node->Get().back()->Accept(this);
}

} // namespace IR