#pragma once
#include "Entities.h"

using exst = Expression::ExpressionState;
using boot = BinaryOperator::OperationType;

template<class T>
inline T* To(Tree* node)
{
	return static_cast<T*>(node);
}

inline Expression* ToExpr(Tree* node)
{
	return static_cast<Expression*>(node);
}

inline BinaryOperator* ToBinOp(Tree* node)
{
	return static_cast<BinaryOperator*>(node);
}

inline FunctionCall* ToFcall(Tree* node)
{
	return static_cast<FunctionCall*>(node);
}

inline Value* ToVal(Tree* node)
{
	return static_cast<Value*>(node);
}

inline Identifier* ToID(Tree* node)
{
	return static_cast<Identifier*>(node);
}