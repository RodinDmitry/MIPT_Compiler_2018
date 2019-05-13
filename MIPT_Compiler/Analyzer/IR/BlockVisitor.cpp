#include <IR/BlockVisitor.h>

namespace IR {

void CBlockVisitor::visit(const CLabelStatement* node)
{
	lastVisitedLabel = node->Label();
	lastVisitedNodeType = TNodeType::LABEL;
}

void CBlockVisitor::visit(const CStatementList* node)
{
	std::shared_ptr<CStatementList> block;
	TNodeType prevNodeType = TNodeType::JUMP;

	const std::vector<std::shared_ptr<const IStatement>>& statementList = node->Get();
	for (int i = 0; i < statementList.size(); i++) {
		statementList[i]->Accept(this);
		if (lastVisitedNodeType == TNodeType::LABEL || prevNodeType == TNodeType::JUMP) {
			if (block) {
				saveBlock(block, prevNodeType, false);
			}
			block = newBlock();
		}
		block->Add(statementList[i]);
	}
	if (block) {
		saveBlock(block, prevNodeType, true);
	}

}

void CBlockVisitor::saveBlock(std::shared_ptr<CStatementList> block, TNodeType previousNodeType, bool isLastBlock)
{
	CLabel jumpLabel = isLastBlock ? CLabel("EndLabel") : lastVisitedLabel;
	if (previousNodeType != TNodeType::JUMP) {
		block->Add(new CJumpStatement(jumpLabel));
	}
	blocks->push_back(block);
}

std::shared_ptr<CStatementList> CBlockVisitor::newBlock()
{
	std::shared_ptr<CStatementList> block = std::make_shared<CStatementList>();
	if (lastVisitedNodeType != TNodeType::LABEL) {
		block->Add(new CLabelStatement(CLabel()));
	}
	return block;
}

} // namespace IR