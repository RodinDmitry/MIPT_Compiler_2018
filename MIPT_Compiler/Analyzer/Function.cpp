#include <Function.h>
#include <Visitor.h>
#include <Modifier.h>
#include <Statement.h>
#include <Id.h>

CFunction::CFunction(CModifier* _visibility, CId* _name, CArgumentList* _arguments, CStatementList* _body) :
		visibility(_visibility), name(_name), arguments(_arguments), body(_body)
{
}

void CFunction::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}
