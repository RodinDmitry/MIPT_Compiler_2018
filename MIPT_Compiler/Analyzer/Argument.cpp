#include <Argument.h>
#include <Visitor.h>

void CArgumentList::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CArgumentList::Add(CVariable* argument)
{
	std::shared_ptr<CVariable> ptr(argument);
	arguments.push_back(ptr);
}

std::string CArgumentList::GetLabel()
{
	return  "arguments" + labelAddings;;
}
