#include <MainClass.h>
#include <Visitor.h>
#include <Id.h>
#include <Statement.h>


CMainArgument::CMainArgument(CId* _name, int _line) : name(_name), ITree(_line)
{
}

void CMainArgument::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CMainArgument::GetLabel()
{
	return  "mainArgument" + labelAddings;;
}

CMainFunction::CMainFunction(CMainArgument* _argument, CStatementList* _body, int _line) : argument(_argument), body(_body), ITree(_line)
{
}

void CMainFunction::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CMainFunction::GetLabel()
{
	return  "mainFunc" + labelAddings;;
}

CMain::CMain(CId* _name, CMainFunction* _mainFunction, int _line) : name(_name), mainFunction(_mainFunction), ITree(_line)
{
}

void CMain::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CMain::GetLabel()
{
	return  "main" + labelAddings;;
}
