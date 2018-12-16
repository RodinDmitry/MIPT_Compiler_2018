#include "NamespaceBlock.h"
#include <InvalidDefinitionException.h>
#include <UndefinedTypeException.h>

CNamespaceBlock::CNamespaceBlock() : parent(nullptr)
{}

CNamespaceBlock::CNamespaceBlock(CNamespaceBlock * _parent) : parent(_parent)
{}

CNamespaceBlock* CNamespaceBlock::GetParent()
{
	return parent;
}

void CNamespaceBlock::AddLocal(std::unique_ptr<const CVariableInfo> variable)
{
	locals.push_back(std::move(variable));
}

const CVariableInfo * CNamespaceBlock::FindLocal(const CSymbol * id) const
{
	for (int i = 0; i < locals.size(); ++i) {
		if (locals[i]->String() == id) {
			return locals[i].get();
		}
	}
	if (parent != nullptr) {
		return parent->FindLocal(id);
	}
	return nullptr;
}

