#pragma once
#include <Symbol.h>

class CFunctionInfo;

class CClassInfo {
public:
	CClassInfo(const std::string& tableName, const CSymbol* _name);
	CClassInfo(const std::string& tableName, const CSymbol* _name, const CSymbol* _extends);

	void AddMember(std::unique_ptr<const CVariableInfo>&& member);
	void AddMembers(std::vector<std::unique_ptr<const CVariableInfo>>&& _members);
	void AddMethod(std::unique_ptr<const CFunctionInfo>&& method);
	void AddMethods(std::vector<std::unique_ptr<const CFunctionInfo>>&& _methods);

	int GetSize() const;
	const std::vector<std::unique_ptr<const CFunctionInfo>>& GetMethods() const;
	std::shared_ptr<std::vector<const CVariableInfo*>> GetMembers() const;

	const CFunctionInfo* FindMethod(const CSymbol* name) const;
	const CVariableInfo* FindMember(const CSymbol* name) const;
	const CSymbol* String() const;
	const CSymbol* GetBase() const;
	bool HasCyclicInheritance(const std::string& tableName) const;
	bool InheritedFromKnownClass(const std::string& tableName) const;
	std::shared_ptr<CType> GetType() const;
private:
	const CSymbol* name;
	const CSymbol* extends;
	const std::string& tableName;
	std::vector<std::unique_ptr<const CVariableInfo> > members;
	std::vector<std::unique_ptr<const CFunctionInfo> > methods;
};