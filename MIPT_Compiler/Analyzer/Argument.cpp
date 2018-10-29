#include <Argument.h>
#include <Visitor.h>

void CArgumentList::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CArgumentList::Add(CVariable* argument)
{
	arguments.push_back(argument);
}

std::string CArgumentList::GetLabel()
{
	return  "arguments" + labelAddings;;
}
