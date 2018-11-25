#pragma once
#include <ClassInfo.h>

class NamespaceBlock {
public:
	NamespaceBlock();
	explicit NamespaceBlock(NamespaceBlock* _parent);
	NamespaceBlock(NamespaceBlock* _parent, CFunctionInfo* function);

	void AddMember(CVariableInfo* member);
	void AddMethod(CFunctionInfo* method);
	void AddClass(CClassInfo* classDecl);
	void AddVariable(CVariableInfo* variable);
	void CreateClass(const std::string& name, const std::string& extends);

	bool FindSymbol(CSymbol* id) const;
private:
	NamespaceBlock* parent;
	std::vector<CVariableInfo* > members;
	std::vector<CFunctionInfo* > methods;
	std::vector<CClassInfo* > classes;
};