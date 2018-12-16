#include <Argument.h>
#include <Visitor.h>

CArgumentList::CArgumentList() : ITree(-1) {}

void CArgumentList::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CArgumentList::Add(CVariable* argument)
{
	std::shared_ptr<CVariable> ptr(argument);
	arguments.push_back(ptr);
}

std::string CArgumentList::GetLabel() const
{
	return  "arguments" + labelAddings;
}
