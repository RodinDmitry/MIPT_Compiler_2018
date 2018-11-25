#pragma once
#include <NamespaceBlock.h>

class CSymbolTable {
	static void CreateTable(const std::string& name);
	static void SwitchCurrentTable(const std::string& name);

	static void AddBlockToCurrent();
	static void AddNestedBlockToCurrent();
	static void AddFunctionBlockToCurrent(CFunctionInfo* function);
	static void LeaveBlockToCurrent();
	static void AddVariableToCurrent(CVariableInfo* variable);
	static void AddClassToCurrent(CClassInfo* classDecl);
	static void AddMethodToCurrent(CFunctionInfo* function);
	static void AddMemberToCurrent(CVariableInfo* variable);
	static void CreateClassToCurrent(const std::string& name, const std::string& extends);

	CSymbol* FindSymbol() const;
private:
	void AddBlock();
	void AddNestedBlock();
	void AddFunctionBlock(CFunctionInfo* function);
	void LeaveBlock();
	void AddVariable(CVariableInfo* variable);
	void AddClass(CClassInfo* classDecl);
	void AddMethod(CFunctionInfo* function);
	void AddMember(CVariableInfo* variable);
	void CreateClass(const std::string& name, const std::string& extends);

	std::vector<std::unique_ptr<NamespaceBlock*> > blocks;
	static std::unordered_map<std::string, std::unique_ptr<CSymbolTable*> > tables;
	static CSymbolTable* currentTable;
};