#include <MainClass.h>
#include <Visitor.h>
#include <Id.h>
#include <Statement.h>


CMainArgument::CMainArgument(CId* _name) : name(_name)
{
}

void CMainArgument::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

CMainFunction::CMainFunction(CMainArgument* _argument, CStatementList* _body) : argument(_argument), body(_body)
{
}

void CMainFunction::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

CMain::CMain(CId* _name, CMainFunction* _mainFunction) : name(_name), mainFunction(_mainFunction)
{
}

void CMain::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}
