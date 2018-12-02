#include "NamespaceBlock.h"
#include <InvalidDefinitionException.h>
#include <UndefinedTypeException.h>

CNamespaceBlock::CNamespaceBlock() : parent(nullptr)
{}

CNamespaceBlock::CNamespaceBlock(const CNamespaceBlock * _parent) : parent(_parent)
{}

const CNamespaceBlock * CNamespaceBlock::GetParent() const
{
	return parent;
}

void CNamespaceBlock::AddClass(CClassInfo * classDecl)
{
	classes.emplace_back(classDecl);
}

const CClassInfo * CNamespaceBlock::FindClass(const CSymbol * id) const
{
	for (int i = 0; i < classes.size(); ++i) {
		if (classes[i].get()->String() == id) {
			return classes[i].get();
		}
	}
	if (parent != nullptr) {
		return parent->FindClass(id);
	}
	return nullptr;
}

const CFunctionInfo * CNamespaceBlock::FindMethod(const CSymbol * id) const
{
	for (int i = 0; i < methods.size(); ++i) {
		if (methods[i].get()->String() == id) {
			return methods[i].get();
		}
	}
	if (parent != nullptr) {
		return parent->FindMethod(id);
	}
	return nullptr;
}

const CVariableInfo * CNamespaceBlock::FindMember(const CSymbol * id) const
{
	for (int i = 0; i < members.size(); ++i) {
		if (members[i].get()->String() == id) {
			return members[i].get();
		}
	}
	if (parent != nullptr) {
		return parent->FindMember(id);
	}
	return nullptr;
}

void CNamespaceBlock::AddMember(const CVariableInfo * variable)
{
	members.emplace_back(variable);
}

void CNamespaceBlock::AddMethod(const CFunctionInfo * method)
{
	throw new CInvalidDefinitionException(method->String()->String());
}

void CNamespaceBlock::AddArgument(const CVariableInfo * argument)
{
	throw new CInvalidDefinitionException(argument->String()->String());
}

const CClassInfo * CNamespaceBlock::GetThis() const
{
	if (parent != nullptr) {
		return parent->GetThis();
	}
	throw new CUndefinedTypeException("this");
}

CFunctionNamespaceBlock::CFunctionNamespaceBlock(const CNamespaceBlock* _parent, CFunctionInfo* function)
	: CNamespaceBlock(_parent), funcToUpdate(function)
{
	const std::vector< const CVariableInfo* > arguments = function->GetArguments();
	for (int i = 0; i < arguments.size(); ++i) {
		AddMember(arguments[i]);
	}
}
void CFunctionNamespaceBlock::AddMember(const CVariableInfo * member)
{
	members.emplace_back(member);
}

void CFunctionNamespaceBlock::AddArgument(const CVariableInfo * argument)
{
	funcToUpdate->AddArgument(argument);
	members.emplace_back(argument);
}

CClassNamespaceBlock::CClassNamespaceBlock(const CNamespaceBlock * _parent, CClassInfo * _classToUpdate)
	: CNamespaceBlock(_parent), classToUpdate(_classToUpdate)
{}

void CClassNamespaceBlock::AddMember(const CVariableInfo * member)
{
	members.emplace_back(member);
	classToUpdate->AddMember(member);
}

void CClassNamespaceBlock::AddMethod(const CFunctionInfo * method)
{
	methods.emplace_back(method);
	classToUpdate->AddMethod(method);
}

const CClassInfo * CClassNamespaceBlock::GetThis() const
{
	return classToUpdate;
}
