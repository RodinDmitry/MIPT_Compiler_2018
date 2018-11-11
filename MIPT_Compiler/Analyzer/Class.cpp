#include <Class.h>
#include <Visitor.h>
#include <Variable.h>
#include <Function.h>

CClassInternals::CClassInternals(CFunction* _function) : function(function), variable(nullptr)
{
}

CClassInternals::CClassInternals(CVariable* _variable) : variable(_variable), function(nullptr)
{
}

void CClassInternals::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CClassInternals::GetLabel()
{
	return  "internal" + labelAddings;;
}

CClassDeclaration::CClassDeclaration(CId* _name, CId* _extends) : name(_name), extend(_extends)
{
}

void CClassDeclaration::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CClassDeclaration::GetLabel()
{
	return  "classDeclaration" + labelAddings;;
}

CClass::CClass(CClassDeclaration* _declaration, CClassInternalsList* _internals) : declaration(_declaration), internals(_internals)
{
}

void CClass::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CClass::GetLabel()
{
	return  "class" + labelAddings;;
}

void CClassInternalsList::Add(CClassInternals* item)
{
	internals.push_back(item);
}

void CClassInternalsList::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CClassInternalsList::GetLabel()
{
	return  "internals" + labelAddings;;
}

void CClassList::Add(CClass* item)
{
	classes.push_back(item);
}

void CClassList::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CClassList::GetLabel()
{
	return  "classes" + labelAddings;;
}
