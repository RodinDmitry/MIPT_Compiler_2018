#include "ClassInfo.h"
#include <SymbolTable.h>

CClassInfo::CClassInfo(const CSymbol * _name) 
	: name(_name), extends(nullptr)
{}

CClassInfo::CClassInfo(const CSymbol* _name, const CSymbol* _extends) 
	: name(_name), extends(_extends)
{}

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

const CFunctionInfo* CClassInfo::FindMethod(const CSymbol * name) const
{
	for (int i = 0; i < methods.size(); ++i) {
		if (methods[i]->String() == name) {
			return methods[i];
		}
	}
	return nullptr;
}

const CVariableInfo * CClassInfo::FindMember(const CSymbol * name) const
{
	for (int i = 0; i < members.size(); ++i) {
		if (members[i]->String() == name) {
			return members[i];
		}
	}
	return nullptr;
}

const CSymbol * CClassInfo::String() const
{
	return name;
}

const CSymbol * CClassInfo::GetBase() const
{
	return extends;
}

bool CClassInfo::HasCyclicInheritance(const std::string& tableName) const
{
	const CSymbol* target = name;
	const CSymbol* current = name;
	const CSymbol* parent = extends;

	while (parent != nullptr) {
		if (target == parent) {
			return true;
		}
		current = parent;
		const CClassInfo* info = CSymbolTable::FindClass(tableName, current);
		parent = info->extends;
	}

	return false;
}

bool CClassInfo::InheritedFromKnownClass(const std::string& tableName) const
{
	if (extends == nullptr) {
		return false;
	}
	const CClassInfo* info = CSymbolTable::FindClass(tableName, extends);
	if (info == nullptr) {
		return true;
	}
	return false;
}

std::shared_ptr<CType> CClassInfo::GetType() const
{
	return std::shared_ptr<CType>(new CType(name->String().c_str()));
}
