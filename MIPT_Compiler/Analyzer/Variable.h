#pragma once

#include <Tree.h>

class CId;

class CVariable : public ITree {
public:
	inline enum TVariableType {
		VT_Integer,
		VT_IntegerArray,
		VT_Boolean,
		VT_Instance,
		VT_Void
	};

	CVariable(CId* classInstance, CId* name);
	virtual void Accept(IVisitor* visitor) override;

	CId* classInstance;
	CId* name;


};