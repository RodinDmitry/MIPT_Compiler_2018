#include <SymbolTable.h>
#include <assert.h>

std::map<const std::string, std::unique_ptr<CSymbolTable> > CSymbolTable::tables;

void CSymbolTable::CreateClass(const std::string& name, const std::string& extends)
{
	if (extends == "") {
		classes.emplace_back(std::make_unique<CClassInfo>(tableName, CSymbol::GetSymbol(name)));
	}
	else {
		classes.emplace_back(std::make_unique<CClassInfo>(tableName, CSymbol::GetSymbol(name), CSymbol::GetSymbol(extends)));
	}
	currentClass = classes.back().get();
}

void CSymbolTable::AddFunctionBlock(CFunctionInfo * function)
{
	functionInfo = function;
	currentClass->AddMethod(function);
}

void CSymbolTable::AddArgument(const CVariableInfo * argument)
{
	functionInfo->AddArgument(std::unique_ptr<const CVariableInfo>(argument));
}

void CSymbolTable::AddMember(const CVariableInfo * variable)
{
	currentClass->AddMember(variable);
}

void CSymbolTable::AddLocal(const CVariableInfo * variable)
{
	functionInfo->AddLocalVar(std::unique_ptr<const CVariableInfo>(variable));
}

const CClassInfo * CSymbolTable::GetThis() const
{
	return currentClass;
}

const CClassInfo * CSymbolTable::FindClass(const CSymbol * id) const
{
	for (int i = 0; i < classes.size(); ++i) {
		if (classes[i]->String() == id) {
			return classes[i].get();
		}
	}
	return nullptr;
}

const CFunctionInfo * CSymbolTable::FindMethod(const CSymbol * id) const
{
	return currentClass->FindMethod(id);
}

const CVariableInfo * CSymbolTable::FindMember(const CSymbol* id) const
{
	return currentClass->FindMember(id);
}

const CVariableInfo* CSymbolTable::FindLocalVariable(const std::string& id, const std::string& className, const std::string& func, int cntEnter, int cntLeave) const
{
	const CClassInfo* cl = FindClass(CSymbol::GetSymbol(className));
	if (cl == nullptr) {
		return nullptr;
	}
	const CFunctionInfo* funcInfo = cl->FindMethod(CSymbol::GetSymbol(func));
	if (funcInfo == nullptr) {
		return nullptr;
	}
	/*
	const CNamespaceBlock* currBlockPtr = switchToOffset(funcInfo->GetParent(), cntEnter, cntLeave);
	if (currBlockPtr == nullptr) {
		return nullptr;
	}*/
	return funcInfo->GetVariable(CSymbol::GetSymbol(id));
}

const CNamespaceBlock * CSymbolTable::switchToOffset(const CNamespaceBlock * block, int cntEnter, int cntLeave) const
{
	/*int currBlock = -1;
	for (int i = 0; i < blocks.size(); ++i) {
		if (blocks[i].get() == block) {
			currBlock = i;
			break;
		}
	}
	if (currBlock == -1) {
		return nullptr;
	}
	const CNamespaceBlock* currBlockPtr = blocks[currBlock].get();
	for (int i = 0; i < cntEnter + cntLeave; ++i) {
		if (++currBlock < blocks.size()) {
			if (currBlockPtr == blocks[currBlock]->GetParent()) {
				currBlockPtr = blocks[currBlock].get();
			}
			else {
				currBlockPtr = blocks[currBlock]->GetParent();
				if (currBlockPtr == nullptr) {
					currBlockPtr = blocks.front().get();
				}
			}
		}
		else {
			currBlockPtr = currentBlock->GetParent();
			if (currBlockPtr == nullptr) {
				currBlockPtr = blocks.front().get();
			}
		}
	}
	return currBlockPtr;*/
	return nullptr;
}

bool CSymbolTable::IsDerived(const std::string& derived, const std::string& base) const
{
	const CClassInfo* cl = FindClass(CSymbol::GetSymbol(derived));
	assert(cl != nullptr);
	const CSymbol* ext = cl->GetBase();
	const CSymbol* baseSymbol = CSymbol::GetSymbol(base);
	while (ext != nullptr) {
		if (baseSymbol == ext) {
			return true;
		}
		cl = FindClass(ext);
		assert(cl != nullptr);
		ext = cl->GetBase();
	}
	return false;
}

void CSymbolTable::CreateTable(const std::string & tableName)
{
	tables.emplace(tableName, new CSymbolTable(tableName));
}

void CSymbolTable::AddBlock(const std::string & tableName)
{
	assert(tables.find(tableName) != tables.end());
	tables[tableName]->AddBlock();
}

void CSymbolTable::LeaveBlock(const std::string & tableName)
{
	assert(tables.find(tableName) != tables.end());
	tables[tableName]->LeaveBlock();
}

void CSymbolTable::CreateClass(const std::string & tableName, const std::string & name, const std::string & extends)
{
	assert(tables.find(tableName) != tables.end());
	tables[tableName]->CreateClass(name, extends);
}

void CSymbolTable::AddFunctionBlock(const std::string & tableName, CFunctionInfo * function)
{
	assert(tables.find(tableName) != tables.end());
	tables[tableName]->AddFunctionBlock(function);
}

void CSymbolTable::AddArgument(const std::string & tableName, const CVariableInfo * argument)
{
	assert(tables.find(tableName) != tables.end());
	tables[tableName]->AddArgument(argument);
}

void CSymbolTable::AddMember(const std::string & tableName, const CVariableInfo * variable)
{
	assert(tables.find(tableName) != tables.end());
	tables[tableName]->AddMember(variable);
}

void CSymbolTable::AddLocal(const std::string & tableName, const CVariableInfo * variable)
{
	assert(tables.find(tableName) != tables.end());
	return tables[tableName]->AddLocal(variable);
}

const CClassInfo* CSymbolTable::GetThis(const std::string& tableName)
{
	assert(tables.find(tableName) != tables.end());
	return tables[tableName]->GetThis();
}

const CClassInfo * CSymbolTable::FindClass(const std::string & tableName, const CSymbol * id)
{
	assert(tables.find(tableName) != tables.end());
	return tables[tableName]->FindClass(id);
}

const CFunctionInfo * CSymbolTable::FindMethod(const std::string & tableName, const CSymbol * id)
{
	assert(tables.find(tableName) != tables.end());
	return tables[tableName]->FindMethod(id);
}

const CVariableInfo * CSymbolTable::FindMember(const std::string & tableName, const CSymbol * id)
{
	assert(tables.find(tableName) != tables.end());
	return tables[tableName]->FindMember(id);
}

const CVariableInfo * CSymbolTable::FindLocalVariable(const std::string & tableName, const std::string& id,
	const std::string& className, const std::string& func, int cntEnter, int cntLeave)
{
	assert(tables.find(tableName) != tables.end());
	return tables[tableName]->FindLocalVariable(id, className, func, cntEnter, cntLeave);
}

bool CSymbolTable::IsDerived(const std::string& tableName, const std::string& derived, const std::string& base)
{
	assert(tables.find(tableName) != tables.end());
	return tables[tableName]->IsDerived(derived, base);
}

CSymbolTable::CSymbolTable(const std::string& _name) : tableName(_name) {}

void CSymbolTable::AddBlock()
{
	functionInfo->EnterBlock();
}

void CSymbolTable::LeaveBlock()
{
	functionInfo->LeaveBlock();
}
