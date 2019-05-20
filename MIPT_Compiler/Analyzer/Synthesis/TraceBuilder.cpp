#include <Synthesis/TraceBuilder.h>
#include <IR/TraceBuilderVisitor.h>

namespace Synthesis {

std::shared_ptr<std::vector<CTrace>> CTraceBuilder::buildTraces(std::shared_ptr<std::vector<std::shared_ptr<IR::CStatementList>>> programBlocks)
{

	blocks = programBlocks;
	isUsed.resize(blocks->size());
	for (int i = 0; i < programBlocks->size(); i++) {
		isUsed[i] = false;
	}
	
	process();
	return traces;
}

void CTraceBuilder::process()
{
	traces = std::make_shared<std::vector<CTrace>>();
	traces->push_back(CTrace());


	for(int i = 0; i < blocks->size(); i++) {
		if (isUsed[i]) {
			continue;
		}
		if (traces->at(traces->size() - 1).size() == 0) {
			CBlock currentBlock = blocks->at(i);
			isUsed[i] = true;
			traces->at(traces->size() - 1).push_back(currentBlock);
		}

		CBlock currentBlock = traces->at(traces->size() - 1).back();
		IR::CTraceBuilderVisitor visitor;
		currentBlock->Accept(&visitor);
		const std::string nextBlockLabel = visitor.isConditional() ? visitor.getFalseTarget() : visitor.getTrueTarget();
		CBlock nextBlock = findBlock(nextBlockLabel);
		
		if (nextBlock) {
			traces->at(traces->size() - 1).push_back(nextBlock);
		} else {
			traces->emplace_back();
		}

	}
	
}

CBlock CTraceBuilder::findBlock(const std::string& startLabel)
{

	for (int i = 0; i < blocks->size(); i++) {
		if (isUsed[i]) {
			continue;
		}
		IR::CTraceBuilderVisitor visitor;
		blocks->at(i)->Accept(&visitor);
		if (visitor.getLabel() == startLabel) {
			isUsed[i] = true;
			return blocks->at(i);
		}
	}

	return nullptr;
}

CBlock CTraceBuilder::getFirstUnused()
{
	for (int i = 0; i < blocks->size(); i++) {
		if (isUsed[i]) {
			continue;
		}
		isUsed[i] = true;
		return blocks->at(i);
	}
}

} // namespace Synthesis