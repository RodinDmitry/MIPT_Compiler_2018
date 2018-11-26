#include "NamespaceBlock.h"
#include <InvalidDefinitionException.h>

NamespaceBlock::NamespaceBlock() : parent(nullptr)
{}

NamespaceBlock::NamespaceBlock(const NamespaceBlock * _parent) : parent(_parent)
{}

const NamespaceBlock * NamespaceBlock::GetParent() const
{
	return parent;
}

void NamespaceBlock::AddClass(const CClassInfo * classDecl)
{
	classes.emplace_back(classDecl);
}

const CClassInfo * NamespaceBlock::FindClass(const CSymbol * id) const
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

const CFunctionInfo * NamespaceBlock::FindMethod(const CSymbol * id) const
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

const CVariableInfo * NamespaceBlock::FindMember(const CSymbol * id) const
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

void NamespaceBlock::AddMember(const CVariableInfo * variable)
{
	throw new CInvalidDefinitionException(variable->String()->String());
}

void NamespaceBlock::AddMethod(const CFunctionInfo * method)
{
	throw new CInvalidDefinitionException(method->String()->String());
}

FunctionNamespaceBlock::FunctionNamespaceBlock(const NamespaceBlock * _parent, const CFunctionInfo * function)
	: NamespaceBlock(_parent)
{
	const std::vector< const CVariableInfo* > arguments = function->GetArguments();
	for (int i = 0; i < arguments.size(); ++i) {
		AddMember(arguments[i]);
	}
}
void FunctionNamespaceBlock::AddMember(const CVariableInfo * member)
{
	members.emplace_back(member);
}

ClassNamespaceBlock::ClassNamespaceBlock(const NamespaceBlock * _parent, CClassInfo * _classToUpdate)
	: NamespaceBlock(_parent), classToUpdate(_classToUpdate)
{}

void ClassNamespaceBlock::AddMember(const CVariableInfo * member)
{
	members.emplace_back(member);
	classToUpdate->AddMember(member);
}

void ClassNamespaceBlock::AddMethod(const CFunctionInfo * method)
{
	methods.emplace_back(method);
	classToUpdate->AddMethod(method);
}
