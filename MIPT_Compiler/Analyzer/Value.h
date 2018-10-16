#pragma once

#include <Tree.h>

class IValue : public ITree
{
public:
};

class CValue : public IValue
{
public:
	inline enum TType {
		T_Integer,
		T_Boolean
	};

	CValue(int value, TType type);

	int value;
	TType type;
};