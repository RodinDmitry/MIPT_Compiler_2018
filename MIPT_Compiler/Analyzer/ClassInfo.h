#pragma once
#include <FunctionInfo.h>

class CClassInfo : public CSymbol {
public:
	explicit CClassInfo(const std::string& _name);
	CClassInfo(const std::string& _name, CSymbol* _extends);
	void AddMember(CVariableInfo* member);
	void AddMembers(std::vector<std::unique_ptr<CVariableInfo> >&& _members);
	void AddMethod(CFunctionInfo* method);
	void AddMethods(std::vector<std::unique_ptr<CFunctionInfo> >&& _methods);

	static CClassInfo* GetSymbol(const std::string& src, CSymbol* extends);
private:
	std::unique_ptr<CSymbol> extends;
	std::vector<std::unique_ptr<CVariableInfo> > members;
	std::vector<std::unique_ptr<CFunctionInfo> > methods;
};