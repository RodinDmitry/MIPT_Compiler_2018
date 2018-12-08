#include <Type.h>
#include <Visitor.h>

CType::CType() : type(TDataType::DT_Void), ITree(-1)
{
}

CType::CType(char* _instance, int _line) : type(TDataType::DT_Instance), instance(_instance), ITree(_line)
{
}

CType::CType(TDataType _type, int _line) : type(_type), ITree(_line)
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
