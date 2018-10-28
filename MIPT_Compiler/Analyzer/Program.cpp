#include <Program.h>
#include <Visitor.h>

CProgram::CProgram(CMain* _main, CClassList* _classes) : main(_main), classes(_classes)
{
}

void CProgram::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}
