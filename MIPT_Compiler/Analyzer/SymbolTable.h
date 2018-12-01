#pragma once
#include <NamespaceBlock.h>
#include <UndefinedTypeException.h>

class CSymbolTable {
public:
	static void CreateTable(const std::string& tableName);
	//static void SwitchCurrentTable(const std::string& name);

	// Для вложенных областей видемости
	static void AddBlock(const std::string& tableName);
	static void LeaveBlock(const std::string& tableName);

	static void CreateClass(const std::string& tableName, const std::string& name, const std::string& extends);
	static void AddFunctionBlock(const std::string& tableName, CFunctionInfo* function);


	//static void AddClass(const std::string& tableName, const CClassInfo* classDecl);
	static void AddArgument(const std::string& tableName, const CVariableInfo* argument);
	static void AddMember(const std::string& tableName, const CVariableInfo* variable);
	
	static const CClassInfo* FindClass(const std::string& tableName, const CSymbol* id);
	static const CFunctionInfo* FindMethod(const std::string& tableName, const CSymbol* id);
	static const CVariableInfo* FindMember(const std::string& tableName, const CSymbol* id);
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