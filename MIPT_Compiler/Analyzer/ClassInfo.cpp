#include "ClassInfo.h"
#include <SymbolTable.h>

CClassInfo::CClassInfo(const CSymbol * _name) 
	: name(_name), extends(nullptr)
{}

CClassInfo::CClassInfo(const CSymbol * _name, const CSymbol * _extends) 
	: name(_name), extends(_extends)
{
	if (CSymbolTable::FindClassInCurrent(_extends)) {
		throw new CUndefinedTypeException(_extends->String());
	}
}

void CClassInfo::AddMember(const CVariableInfo * member)
{
	members.push_back(member);
}

void CClassInfo::AddMembers(std::vector<const CVariableInfo*>&& _members)
{
	members = _members;
}

void CClassInfo::AddMethod(const CFunctionInfo * method)
{
	methods.push_back(method);
}

void CClassInfo::AddMethods(std::vector<const CFunctionInfo*>&& _methods)
{
	methods = _methods;
}

const std::vector<const CFunctionInfo*>& CClassInfo::GetMethods() const
{
	return methods;
}

const CSymbol * CClassInfo::String() const
{
	return name;
}
