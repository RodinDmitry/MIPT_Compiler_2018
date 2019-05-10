#include <IR/TraceBuilderVisitor.h>

namespace IR {

void CTraceBuilderVisitor::visit(const CJumpStatement* node)
{
	isConditional = false;
	trueTargetLabel = &node->Target();
}

void CTraceBuilderVisitor::visit(const CJumpConditionalStatement* node)
{
	isConditional = true;
	trueTargetLabel = &node->TrueLabel();
	falseTragetLabel = &node->FalseLabel();
}

void CTraceBuilderVisitor::visit(const CLabelStatement* node)
{
	startLabel = &node->Label();
}

void CTraceBuilderVisitor::visit(const CStatementList* node)
{
	node->Get().front()->Accept(this);
	node->Get().back()->Accept(this);
}

} // namespace IR