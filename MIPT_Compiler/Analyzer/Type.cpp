#include <Type.h>
#include <Visitor.h>

CType::CType() : type(TVariableType::VT_Void)
{
}

CType::CType(char* _instance) : type(TVariableType::VT_Instance), instance(_instance)
{
}

CType::CType(TVariableType _type) : type(_type)
{
}

void CType::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}
