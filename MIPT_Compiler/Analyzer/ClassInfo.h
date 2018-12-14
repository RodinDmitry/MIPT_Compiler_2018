#pragma once
#include <FunctionInfo.h>

class CClassInfo {
public:
	explicit CClassInfo(const CSymbol* _name);
	CClassInfo(const std::string& tableName, const CSymbol* _name, const CSymbol* _extends);
	void AddMember(const CVariableInfo* member);
	void AddMembers(std::vector<const CVariableInfo* >&& _members);
	void AddMethod(const CFunctionInfo* method);
	void AddMethods(std::vector<const CFunctionInfo* >&& _methods);
	const std::vector<const CFunctionInfo*>& GetMethods() const;
	const CFunctionInfo* FindMethod(const CSymbol* name) const;
	const CSymbol* String() const;
	const CSymbol* GetBase() const;
	bool HasCyclicInheritance(const std::string& tableName) const;
	bool InheritedFromKnownClass(const std::string& tableName) const;
private:
	const CSymbol* name;
	const CSymbol* extends;
	std::vector<const CVariableInfo* > members;
	std::vector<const CFunctionInfo* > methods;

	
};