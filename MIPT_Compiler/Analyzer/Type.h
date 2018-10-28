#pragma once
#include <Tree.h>

class CType : public ITree {
public:
	enum TVariableType {
		VT_Integer,
		VT_IntegerArray,
		VT_Boolean,
		VT_Instance,
		VT_Void
	};


	CType();
	CType(char* instance);
	CType(TVariableType type);

	virtual void Accept(IVisitor* visitor) override;

	TVariableType type;
	std::string instance;
};