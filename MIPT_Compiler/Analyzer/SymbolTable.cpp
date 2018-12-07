#include "SymbolTable.h"
#include <assert.h>

std::map<const std::string, std::unique_ptr<CSymbolTable> > CSymbolTable::tables;

void CSymbolTable::CreateClass(const std::string& name, const std::string& extends)
{
	assert(currentBlock != nullptr);
	CClassInfo* clDecl;
	if (extends == "") {
		clDecl = new CClassInfo(CSymbol::GetSymbol(name));
	} else {
		clDecl = new CClassInfo(tableName, CSymbol::GetSymbol(name), CSymbol::GetSymbol(extends));
	}
	blocks.emplace_back(new CClassNamespaceBlock(currentBlock, clDecl));
	currentBlock->AddClass(clDecl);
	currentBlock = blocks.back().get();
	assert(currentBlock != nullptr);
}

void CSymbolTable::AddFunctionBlock(CFunctionInfo * function)
{
	assert(currentBlock != nullptr);
	blocks.emplace_back(new CFunctionNamespaceBlock(currentBlock, function));
	currentBlock->AddMethod(function);
	currentBlock = blocks.back().get();
	assert(currentBlock != nullptr);
}

void CSymbolTable::AddArgument(const CVariableInfo * argument)
{
	currentBlock->AddArgument(argument);
}

void CSymbolTable::AddMember(const CVariableInfo * variable)
{
	currentBlock->AddMember(variable);
}

const CClassInfo * CSymbolTable::GetThis() const
{
	return currentBlock->GetThis();
}

const CClassInfo * CSymbolTable::FindClass(const CSymbol * id) const
{
	return currentBlock->FindClass( id );
}

const CFunctionInfo * CSymbolTable::FindMethod(const CSymbol * id) const
{
	return currentBlock->FindMethod( id );
}

const CVariableInfo * CSymbolTable::FindMember(const CSymbol * id) const
{
	return currentBlock->FindMember( id );
}

void CSymbolTable::CreateTable(const std::string & tableName)
{
	tables.emplace(tableName, new CSymbolTable(tableName));
	tables[tableName]->AddBlock();
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

CSymbolTable::CSymbolTable(const std::string & _name): tableName(_name) {}

void CSymbolTable::AddBlock()
{
	blocks.emplace_back(new CNamespaceBlock(currentBlock));
	currentBlock = blocks.back().get();
	assert(currentBlock != nullptr);
}

void CSymbolTable::LeaveBlock()
{
	const CNamespaceBlock* block = currentBlock->GetParent();
	if (block == nullptr) {
		blocks.emplace_back(new CNamespaceBlock());
	}
	currentBlock = const_cast<CNamespaceBlock*>(block);
	assert(currentBlock != nullptr);
}