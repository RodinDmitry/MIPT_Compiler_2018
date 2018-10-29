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

std::string CType::GetLabel()
{
	std::string name;
	switch (type) {
		case VT_Integer: name = "int"; break;
		case VT_IntegerArray: name = "int"; break;
		case VT_Boolean: name = "int"; break;
		case VT_Instance: name = "int"; break;
		case VT_Void: name = "int"; break;
	}
	return name + labelAddings;
}
