#include <Synthesis/TraceBuilder.h>
#include <IR/TraceBuilderVisitor.h>

namespace Synthesis {

std::shared_ptr<std::vector<CTrace>> CTraceBuilder::buildTraces(std::shared_ptr<std::vector<std::shared_ptr<IR::CStatementList>>> programBlocks)
{

	for (int i = 0; i < programBlocks->size(); i++) {
		blocks.insert(programBlocks->at(i));
	}
	
	process();
	return traces;
}

void CTraceBuilder::process()
{
	traces = std::make_shared<std::vector<CTrace>>();
	traces->push_back(CTrace());
	CTrace& currentTrace = traces->back();


	while (!blocks.empty()) {
		if (currentTrace.size() == 0) {
			CBlock currentBlock = getFirstUnused();
			currentTrace.push_back(currentBlock);
		}

		CBlock currentBlock = currentTrace.back();
		IR::CTraceBuilderVisitor visitor;
		currentBlock->Accept(&visitor);
		const std::string nextBlockLabel = visitor.isConditional() ? visitor.getFalseTarget() : visitor.getTrueTarget();
		CBlock nextBlock = findBlock(nextBlockLabel);
		
		if (nextBlock) {
			currentTrace.push_back(nextBlock);
		} else {
			traces->push_back(CTrace());
			CTrace& currentTrace = traces->back();
		}

	}
	
}

CBlock CTraceBuilder::findBlock(const std::string& startLabel)
{
	std::set<CBlock>::iterator it;
	for (it = blocks.begin(); it != blocks.end(); it++) {
		IR::CTraceBuilderVisitor visitor;
		(*it)->Accept(&visitor);
		if (visitor.getLabel() == startLabel) {
			CBlock block = *it;
			blocks.erase(block);
			return block;
		}
	}

	return nullptr;
}

CBlock CTraceBuilder::getFirstUnused()
{
	CBlock block = *blocks.begin();
	blocks.erase(block);
	return block;
}

} // namespace Synthesis