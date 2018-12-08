#pragma once
#include <NamespaceBlock.h>
#include <UndefinedTypeException.h>
#include <map>

class CSymbolTable {
public:
	static void CreateTable(const std::string& tableName);
	//static void SwitchCurrentTable(const std::string& name);

	// ��� ��������� �������� ���������
	static void AddBlock(const std::string& tableName);
	static void LeaveBlock(const std::string& tableName);

	static void CreateClass(const std::string& tableName, const std::string& name, const std::string& extends);
	static void AddFunctionBlock(const std::string& tableName, CFunctionInfo* function);


	//static void AddClass(const std::string& tableName, const CClassInfo* classDecl);
	static void AddArgument(const std::string& tableName, const CVariableInfo* argument);
	static void AddMember(const std::string& tableName, const CVariableInfo* variable);
	
	static const CClassInfo* GetThis(const std::string& tableName);
	static const CClassInfo* FindClass(const std::string& tableName, const CSymbol* id);
	static const CFunctionInfo* FindMethod(const std::string& tableName, const CSymbol* id);
	static const CVariableInfo* FindMember(const std::string& tableName, const CSymbol* id);

	static const CVariableInfo* FindLocalVariable(const std::string& tableName, const std::string& id,
		const std::string& className, const std::string& func, int cntEnter, int cntLeave);

private:
	explicit CSymbolTable(const std::string& name);

	void AddBlock();
	void LeaveBlock();
	
	void CreateClass(const std::string& name, const std::string& extends);
	void AddFunctionBlock(CFunctionInfo* function);

	void AddArgument(const CVariableInfo* argument);
	void AddMember(const CVariableInfo* variable);

	const CClassInfo* GetThis() const;

	const CClassInfo* FindClass(const CSymbol* id) const;
	const CFunctionInfo* FindMethod(const CSymbol* id) const;
	const CVariableInfo* FindMember(const CSymbol* id) const;

	const CVariableInfo* FindLocalVariable(const std::string& id, const std::string& className, const std::string& func, int cntEnter, int cntLeave) const;
	const CNamespaceBlock* switchToOffset(const CNamespaceBlock* block, int cntEnter, int cntLeave) const;

	CNamespaceBlock* currentBlock;
	const std::string tableName;
	std::vector<std::unique_ptr<CNamespaceBlock> > blocks;
	static std::map<const std::string, std::unique_ptr<CSymbolTable> > tables;
	static CSymbolTable* currentTable;
};