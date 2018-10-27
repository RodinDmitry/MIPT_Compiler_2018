#pragma once

#include <Tree.h>

class IValue : public ITree
{
public:
	virtual void Accept(IVisitor* visitor) override;
};

class CValue : public IValue
{
public:
	inline enum TType {
		T_Integer,
		T_Boolean
	};

	CValue(int value, TType type);
	virtual void Accept(IVisitor* visitor) override;

	int value;
	TType type;
};