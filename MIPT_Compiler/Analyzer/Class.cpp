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

CClassDeclaration::CClassDeclaration(CId* _name, CId* _extends) : name(_name), extend(_extends)
{
}

void CClassDeclaration::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

CClass::CClass(CClassDeclaration* _declaration, CClassInternals* _internals) : declaration(_declaration), internals(_internals)
{
}

void CClass::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}
