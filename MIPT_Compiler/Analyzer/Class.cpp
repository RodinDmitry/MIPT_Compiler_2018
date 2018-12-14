#include <Class.h>
#include <Visitor.h>
#include <Variable.h>
#include <Function.h>

CClassInternals::CClassInternals(CFunction* _function, int _line) : function(_function), variable(nullptr), ITree(_line)
{
}

CClassInternals::CClassInternals(CVariable* _variable, int _line) : variable(_variable), function(nullptr), ITree(_line)
{
}

void CClassInternals::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

const std::string& CClassInternals::GetLabel() const
{
	return  "internal" + labelAddings;;
}

CClassDeclaration::CClassDeclaration(CId* _name, CId* _extends, int _line) : name(_name), extend(_extends), ITree(_line)
{
}

void CClassDeclaration::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

const std::string& CClassDeclaration::GetLabel() const
{
	return  "classDeclaration" + labelAddings;;
}

CClass::CClass(CClassDeclaration* _declaration, CClassInternalsList* _internals, int _line) : declaration(_declaration), internals(_internals), ITree(_line)
{
}

void CClass::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

const std::string& CClass::GetLabel() const
{
	return  "class" + labelAddings;;
}

CClassInternalsList::CClassInternalsList() : ITree(-1) {}

void CClassInternalsList::Add(CClassInternals* item)
{
	std::shared_ptr<CClassInternals> ptr(item);
	internals.push_back(ptr);
}

void CClassInternalsList::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

const std::string& CClassInternalsList::GetLabel() const
{
	return  "internals" + labelAddings;;
}

CClassList::CClassList() : ITree(-1) {}

void CClassList::Add(CClass* item)
{
	std::shared_ptr<CClass> ptr(item);
	classes.push_back(ptr);
}

void CClassList::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

const std::string& CClassList::GetLabel() const
{
	return  "classes" + labelAddings;;
}
