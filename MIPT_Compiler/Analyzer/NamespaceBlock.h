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

	CSymbol* FindSymbol() const;
private:
	NamespaceBlock* parent;
	std::vector<std::unique_ptr<CVariableInfo*> > members;
	std::vector<std::unique_ptr<CFunctionInfo*> > methods;
	std::vector<std::unique_ptr<CClassInfo*> > classes;
};