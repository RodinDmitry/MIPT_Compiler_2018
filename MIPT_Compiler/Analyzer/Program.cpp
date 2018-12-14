#include <Program.h>
#include <Visitor.h>

CProgram::CProgram(CMain* _main, CClassList* _classes, int _line) : main(_main), classes(_classes), ITree(_line)
{
}

void CProgram::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

const std::string& CProgram::GetLabel() const
{
	return  "program" + labelAddings;;
}
