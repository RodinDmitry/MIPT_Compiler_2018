#include <Type.h>
#include <Visitor.h>

CType::CType() : type(TDataType::DT_Void)
{
}

CType::CType(char* _instance) : type(TDataType::DT_Instance), instance(_instance)
{
}

CType::CType(TDataType _type) : type(_type)
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
		case DT_Integer: name = "int"; break;
		case DT_IntegerArray: name = "int"; break;
		case DT_Boolean: name = "int"; break;
		case DT_Instance: name = "int"; break;
		case DT_Void: name = "int"; break;
	}
	return name + labelAddings;
}
