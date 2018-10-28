#include <Function.h>
#include <Visitor.h>
#include <Modifier.h>
#include <Statement.h>
#include <Id.h>
#include <Type.h>

CFunction::CFunction(CModifier* _visibility, CId* _name, CArgumentList* _arguments, CStatementList* _body,
	CType* _returns, CReturnExpression* _returnExpression) : visibility(_visibility), name(_name),
		arguments(_arguments), body(_body), returns(_returns), returnExpression(_returnExpression)
{
}

void CFunction::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}