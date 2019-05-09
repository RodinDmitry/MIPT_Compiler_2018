#include <SymbolTable.h>
#include <Type.h>
#include <ClassInfo.h>

CClassInfo::CClassInfo(const std::string& _tableName, const CSymbol * _name)
	: name(_name), extends(nullptr), tableName(_tableName)
{}

CClassInfo::CClassInfo(const std::string& _tableName, const CSymbol* _name, const CSymbol* _extends)
	: name(_name), extends(_extends), tableName(_tableName)
{}

void CClassInfo::AddMember(std::unique_ptr<const CVariableInfo>&& member)
{
	members.emplace_back(std::move(member));
}

void CClassInfo::AddMembers(std::vector<std::unique_ptr<const CVariableInfo>>&& _members)
{
	members = std::move(_members);
}

void CClassInfo::AddMethod(std::unique_ptr<const CFunctionInfo>&& method)
{
	methods.emplace_back(std::move(method));
}

void CClassInfo::AddMethods(std::vector<std::unique_ptr<const CFunctionInfo>>&& _methods)
{
	methods = std::move(_methods);
}

int CClassInfo::GetSize() const
{
	int size = members.size() + 1;
	if (extends != nullptr) {
		const CClassInfo* base = CSymbolTable::FindClass(tableName, extends);
		if (base != nullptr) {
			size += base->GetSize() - 1;
		}
	}
	return size;
}

const std::vector<std::unique_ptr<const CFunctionInfo>>& CClassInfo::GetMethods() const
{
	return methods;
}

std::shared_ptr<std::vector<const CVariableInfo*>> CClassInfo::GetMembers() const
{
	std::shared_ptr<std::vector<const CVariableInfo*>> tmembers = std::make_shared< std::vector<const CVariableInfo* >>();;
	if (extends != nullptr) {
		const CClassInfo* base = CSymbolTable::FindClass(tableName, extends);
		if (base != nullptr) {
			tmembers = base->GetMembers();
		}
	}
	for (int i = 0; i < members.size(); ++i) {
		tmembers->push_back(members[i].get());
	}
	return tmembers;
}

const CFunctionInfo* CClassInfo::FindMethod(const CSymbol * name) const
{
	for (int i = 0; i < methods.size(); ++i) {
		if (methods[i]->String() == name) {
			return methods[i].get();
		}
	}
	if (extends != nullptr) {
		const CClassInfo* base = CSymbolTable::FindClass(tableName, extends);
		if (base != nullptr) {
			return base->FindMethod(name);
		}
	}
	return nullptr;
}

const CVariableInfo * CClassInfo::FindMember(const CSymbol * name) const
{
	for (int i = 0; i < members.size(); ++i) {
		if (members[i]->String() == name) {
			return members[i].get();
		}
	}
	if (extends != nullptr) {
		const CClassInfo* base = CSymbolTable::FindClass(tableName, extends);
		if (base != nullptr) {
			return base->FindMember(name);
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

const CVirtualTable* CClassInfo::GetVirtualTable() const
{
	if (virtualTable == nullptr) {
		if (extends != 0) {
			const CClassInfo* parent = CSymbolTable::FindClass(tableName, extends);
			assert(parent != 0);
			virtualTable = std::make_unique<CVirtualTable>(name->String(), *(parent->GetVirtualTable()));
		}
		else {
			virtualTable = std::make_unique<CVirtualTable>(name->String());
		}
		for (int i = 0; i < methods.size(); ++i) {
			virtualTable->ReplaceMethod(methods[i].get());
		}
	}
	return virtualTable.get();
}
