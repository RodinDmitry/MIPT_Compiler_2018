#include <Id.h>
#include <Visitor.h>

CId::CId(char* _name)
{
	if (_name != nullptr) {
		name = std::string(_name);
	}
	else {
		name = "";
	}
}

void CId::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

