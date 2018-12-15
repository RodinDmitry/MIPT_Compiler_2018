#include <FunctionInfo.h>
#include <SymbolTable.h>
#include <Type.h>
#include <UndefinedTypeException.h>

CFunctionInfo::CFunctionInfo(const CSymbol* _name, std::shared_ptr<CType> _dataType, const CClassInfo* _classInfo,
		TVisabilityModifierType _modifierType)
	:name(_name), classInfo(_classInfo), dataType(_dataType), modifierType(_modifierType) {}

void CFunctionInfo::AddArgument(std::unique_ptr<const CVariableInfo> argument)
{
	arguments.push_back(std::move(argument));
}

void CFunctionInfo::AddLocalVar(std::unique_ptr<const CVariableInfo> local)
{
	localsBlocks.emplace_back(local.get(), GetCurrentBlock());
	GetCurrentBlock()->AddLocal(std::move(local));
}

const std::vector<std::unique_ptr<const CVariableInfo>>& CFunctionInfo::GetArguments() const
{
	return arguments;
}

const std::vector<const CVariableInfo*>& CFunctionInfo::GetLocals() const
{
	std::vector<const CVariableInfo*> vars;
	for (int i = 0; i < localsBlocks.size(); ++i) {
		vars.push_back(localsBlocks[i].first);
	}
	return vars;
}


const CVariableInfo * CFunctionInfo::GetVariable(const CSymbol * name) const
{
	for (int i = 0; i < arguments.size(); ++i) {
		if (arguments[i]->String() == name) {
			return arguments[i].get();
		}
	}
	for (int i = 0; i < localsBlocks.size(); ++i) {
		if (localsBlocks[i].first->String() == name) {
			return localsBlocks[i].first;
		}
	}
	return classInfo->FindMember(name);
}

const CVariableInfo * CFunctionInfo::FindVariable(const CSymbol * name)
{
	GetCurrentBlock()->FindLocal(name);
}

const CSymbol * CFunctionInfo::String() const
{
	return name;
}

std::shared_ptr<CType> CFunctionInfo::GetType() const
{
	return dataType;
}

void CFunctionInfo::EnterBlock()
{
	if (blocks.back().get() == currentBlock) {
		blocks.emplace_back(currentBlock);
		currentBlock = blocks.back().get();
	}
	else {
		for (int i = 0; i < blocks.size() - 1; ++i) {
			if (blocks[i].get() == currentBlock) {
				currentBlock = blocks[i + 1].get();
				break;
			}
		}
	}
}

void CFunctionInfo::LeaveBlock()
{
	assert(currentBlock != nullptr);
	currentBlock = currentBlock->GetParent();
	if (currentBlock == this) {
		currentBlock = nullptr;
	}
}

CNamespaceBlock * CFunctionInfo::GetCurrentBlock()
{
	if (currentBlock == nullptr) {
		return this;
	}
	else {
		return currentBlock;
	}
}
