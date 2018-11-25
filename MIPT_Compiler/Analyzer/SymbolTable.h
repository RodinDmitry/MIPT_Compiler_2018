#pragma once
#include <NamespaceBlock.h>

class CSymbolTable {
public:
	static void CreateTable(const std::string& name);
	static void SwitchCurrentTable(const std::string& name);

	static void AddBlockToCurrent();
	static void AddNestedBlockToCurrent();
	static void AddFunctionBlockToCurrent(CFunctionInfo* function);
	static void LeaveBlockInCurrent();
	static void AddVariableToCurrent(CVariableInfo* variable);
	static void AddClassToCurrent(CClassInfo* classDecl);
	static void AddMethodToCurrent(CFunctionInfo* function);
	static void AddMemberToCurrent(CVariableInfo* variable);
	static void CreateClassInCurrent(const std::string& name, const std::string& extends);
	
	static bool FindSymbolInCurrent(const CSymbol* id);
	static bool FindFunctionInCurrent(const CSymbol* id);
	static bool FindClassInCurrent(const CSymbol* id);
	static bool FindVarInCurrent(const CSymbol* id);
	
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

	bool FindSymbol(const CSymbol* id) const;

	std::vector<std::shared_ptr<NamespaceBlock> > blocks;
	static std::unordered_map<std::string, std::unique_ptr<CSymbolTable> > tables;
	static CSymbolTable* currentTable;
};