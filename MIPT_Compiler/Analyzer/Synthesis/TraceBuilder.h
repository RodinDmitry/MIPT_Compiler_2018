#pragma once

#include <cassert>
#include <memory>
#include <vector>
#include <IR/IRStatement.h>
#include <set>


namespace Synthesis {

using CBlock = std::shared_ptr<IR::CStatementList>;
using CTrace = std::vector<CBlock>;

class CTraceBuilder
{
public:
	std::shared_ptr<std::vector<CTrace>> buildTraces(std::shared_ptr<std::vector<std::shared_ptr<IR::CStatementList>>> programBlocks);


private:

	void process();
	CBlock findBlock(const std::string& startLabel);
	CBlock getFirstUnused();

	std::set<CBlock> blocks;
	
	std::shared_ptr<std::vector<CTrace>> traces;
};


} // namespace Synthesis