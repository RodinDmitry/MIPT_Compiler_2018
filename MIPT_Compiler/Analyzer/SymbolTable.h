#pragma once
#include <NamespaceBlock.h>
#include <UndefinedTypeException.h>

class CSymbolTable {
public:
	static void CreateTable(const std::string& name);
	static void SwitchCurrentTable(const std::string& name);

	static void AddBlockToCurrent();
	static void LeaveBlockInCurrent();

	static void CreateClassInCurrent(const std::string& name, const std::string& extends);
	static void AddFunctionBlockToCurrent(CFunctionInfo* function);


	static void AddClassToCurrent(const CClassInfo* classDecl);
	static void AddMemberToCurrent(const CVariableInfo* variable);
	
	static const CClassInfo* FindClassInCurrent(const CSymbol* id);
	static const CFunctionInfo* FindMethodInCurrent(const CSymbol* id);
	static const CVariableInfo* FindMemberInCurrent(const CSymbol* id);
private:
	void AddBlock();
	void LeaveBlock();
	
	void CreateClass(const std::string& name, const std::string& extends);
	void CreateMethod(CFunctionInfo* method);

	void AddClass(const CClassInfo* classDecl);
	void AddMember(const CVariableInfo* variable);

	const CClassInfo* FindClass(const CSymbol* id) const;
	const CFunctionInfo* FindMethod(const CSymbol* id) const;
	const CVariableInfo* FindMember(const CSymbol* id) const;

	NamespaceBlock* currentBlock;
	std::vector<std::shared_ptr<NamespaceBlock> > blocks;
	static std::unordered_map<std::string, std::unique_ptr<CSymbolTable> > tables;
	static CSymbolTable* currentTable;
};