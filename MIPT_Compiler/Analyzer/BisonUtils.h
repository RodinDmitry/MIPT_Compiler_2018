#pragma once
#include "Entities.h"

using exst = Expression::ExpressionState;
using boot = BinaryOperator::OperationType;
using titt = TypeIdentifier::TypeType;
using sst = Statement::StatementType;
using aas = Argument::ArgumentState;
using mv = Modifier::Value;

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

inline Statement* ToState(Tree* node)
{
	return static_cast<Statement*>(node);
}

inline TypeIdentifier* ToType(Tree* node)
{
	return static_cast<TypeIdentifier*>(node);
}

inline VarDeclaration* ToVar(Tree* node)
{
	return static_cast<VarDeclaration*>(node);
}

inline Argument* ToArg(Tree* node)
{
	return static_cast<Argument*>(node);
}

inline Modifier* ToMod(Tree* node)
{
	return static_cast<Modifier*>(node);
}

inline MethodDeclaration* ToFunc(Tree* node)
{
	return static_cast<MethodDeclaration*>(node);
}