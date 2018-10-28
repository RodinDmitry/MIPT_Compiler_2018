#pragma once
#include "Entities.h"

#include <Expressions.h>
#include <Argument.h>
#include <Class.h>
#include <Function.h>
#include <Id.h>
#include <MainClass.h>
#include <Modifier.h>
#include <Program.h>
#include <Statement.h>
#include <Tree.h>
#include <Type.h>
#include <Value.h>
#include <Variable.h>

using exst = Expression::ExpressionState;
using boot = BinaryOperator::OperationType;
using titt = TypeIdentifier::TypeType;
using sst = Statement::StatementType;
using aas = Argument::ArgumentState;
using mv = Modifier::Value;
using cit = ClassInternals::Type;
using cdt = ClassDeclaration::Type;

template<class T>
inline T* To(ITree* node)
{
	return static_cast<T*>(node);
}

inline Expression* ToExpr(ITree* node)
{
	return static_cast<Expression*>(node);
}

inline BinaryOperator* ToBinOp(ITree* node)
{
	return static_cast<BinaryOperator*>(node);
}

inline FunctionCall* ToFcall(ITree* node)
{
	return static_cast<FunctionCall*>(node);
}

inline Value* ToVal(ITree* node)
{
	return static_cast<Value*>(node);
}

inline Identifier* ToID(ITree* node)
{
	return static_cast<Identifier*>(node);
}

inline Statement* ToState(ITree* node)
{
	return static_cast<Statement*>(node);
}

inline TypeIdentifier* ToType(ITree* node)
{
	return static_cast<TypeIdentifier*>(node);
}

inline VarDeclaration* ToVar(ITree* node)
{
	return static_cast<VarDeclaration*>(node);
}

inline Argument* ToArg(ITree* node)
{
	return static_cast<Argument*>(node);
}

inline Modifier* ToMod(ITree* node)
{
	return static_cast<Modifier*>(node);
}

inline MethodDeclaration* ToFunc(ITree* node)
{
	return static_cast<MethodDeclaration*>(node);
}

inline ClassInternals* ToClInt(ITree* node)
{
	return static_cast<ClassInternals*>(node);
}

inline ClassDeclaration* ToClDecl(ITree* node)
{
	return static_cast<ClassDeclaration*>(node);
}

inline ClassStart* ToClSt(ITree* node)
{
	return static_cast<ClassStart*>(node);
}

inline MainClass* ToMCl(ITree* node)
{
	return static_cast<MainClass*>(node);
}