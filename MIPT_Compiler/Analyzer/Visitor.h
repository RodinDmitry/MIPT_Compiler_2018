#pragma once

#include <Tree.h>
#include <Expressions.h>
#include <Argument.h>
#include <Class.h>
#include <Function.h>
#include <Id.h>
#include <MainClass.h>
#include <Modifier.h>
#include <Program.h>
#include <Statement.h>
#include <Type.h>
#include <Value.h>
#include <Variable.h>
#include <string>
#include <fstream>
#include <deque>

class Modifier;
class Value;
class Identifier;
class Statement;
class FunctionCall;
class BinaryOperator;
class Expression;
class TypeIdentifier;
class MainMethodDeclaration;
class MethodDeclaration;
class VarDeclaration;
class Argument;
class ClassInternals;
class ClassStart;
class ClassDeclaration;
class MainClass;
class Goal;

class IVisitor {
public:
	virtual void visit(ITree* ) = 0;
	virtual void visit(CArgumentList*) = 0;
	virtual void visit(CClassDeclaration*) = 0;
	virtual void visit(CClassInternals*) = 0;
	virtual void visit(CClassInternalsList*) = 0;
	virtual void visit(CClass*) = 0;
	virtual void visit(CClassList*) = 0;
	virtual void visit(IExpression*) = 0;
	virtual void visit(CExpressionList*) = 0;
	virtual void visit(CLValueExpression*) = 0;
	virtual void visit(CBinaryExpression*) = 0;
	virtual void visit(CArrayExpression*) = 0;
	virtual void visit(CCallExpression*) = 0;
	virtual void visit(CValueExpression*) = 0;
	virtual void visit(CNewArrayExpression*) = 0;
	virtual void visit(CNewExpression*) = 0;
	virtual void visit(CIdExpression*) = 0;
	virtual void visit(CThisExpression*) = 0;
	virtual void visit(CNotExpression*) = 0;
	virtual void visit(CBracketsExpression*) = 0;
	virtual void visit(CReturnStatement*) = 0;
	virtual void visit(CFunction*) = 0;
	virtual void visit(CId*) = 0;
	virtual void visit(CMainArgument*) = 0;
	virtual void visit(CMainFunction*) = 0;
	virtual void visit(CMain*) = 0;
	virtual void visit(CModifier*) = 0;
	virtual void visit(CProgram*) = 0;
	virtual void visit(IStatement*) = 0;
	virtual void visit(CStatementList*) = 0;
	virtual void visit(CVisibilityStatement*) = 0;
	virtual void visit(CIfStatement*) = 0;
	virtual void visit(CWhileStatement*) = 0;
	virtual void visit(CPrintStatement*) = 0;
	virtual void visit(CAssignStatement*) = 0;
	virtual void visit(CVariableStatement*) = 0;
	virtual void visit(CType*) = 0;
	virtual void visit(IValue*) = 0;
	virtual void visit(CValue*) = 0;
	virtual void visit(CVariable*) = 0;
	virtual void visit(CCallLengthExpression*) = 0;
	virtual void visit(CClassVisibilityStart*) { assert(false); }
	virtual void visit(CClassVisibilityEnd*) { assert(false); }
	virtual void visit(CFunctionVisibilityStart*) { assert(false); }
	virtual void visit(CFunctionVisibilityEnd*) { assert(false); } 
	virtual void visit(CVisibilityBlockStart*) { assert(false); }
	virtual void visit(CVisibilityBlockEnd*) { assert(false); }

};



