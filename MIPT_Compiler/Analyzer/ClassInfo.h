#pragma once
#include <FunctionInfo.h>

class CClassInfo {
public:
	explicit CClassInfo(const CSymbol* _name);
	CClassInfo(const CSymbol* _name, const CSymbol* _extends);
	void AddMember(const CVariableInfo* member);
	void AddMembers(std::vector<const CVariableInfo* >&& _members);
	void AddMethod(const CFunctionInfo* method);
	void AddMethods(std::vector<const CFunctionInfo* >&& _methods);
	const CSymbol* String() const;

private:
	const CSymbol* name;
	const CSymbol* extends;
	std::vector<const CVariableInfo* > members;
	std::vector<const CFunctionInfo* > methods;
};