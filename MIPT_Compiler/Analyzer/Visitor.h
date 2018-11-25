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
	virtual void visit(CReturnExpression*) = 0;
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
	virtual void visit(CEqualStatement*) = 0;
	virtual void visit(CVariableStatement*) = 0;
	virtual void visit(CType*) = 0;
	virtual void visit(IValue*) = 0;
	virtual void visit(CValue*) = 0;
	virtual void visit(CVariable*) = 0;

	std::deque< ITree* > printerStack;
};

class CPrettyPrinter : public IVisitor {
public:

	CPrettyPrinter(std::string name);

	void close();

	virtual void visit(ITree*) override;
	virtual void visit(CArgumentList*) override;
	virtual void visit(CClassDeclaration*) override;
	virtual void visit(CClassInternals*) override;
	virtual void visit(CClassInternalsList*) override;
	virtual void visit(CClass*) override;
	virtual void visit(CClassList*) override;
	virtual void visit(IExpression*) override;
	virtual void visit(CExpressionList*) override;
	virtual void visit(CLValueExpression*) override;
	virtual void visit(CBinaryExpression*) override;
	virtual void visit(CArrayExpression*) override;
	virtual void visit(CCallExpression*) override;
	virtual void visit(CValueExpression*) override;
	virtual void visit(CNewArrayExpression*) override;
	virtual void visit(CNewExpression*) override;
	virtual void visit(CIdExpression*) override;
	virtual void visit(CThisExpression*) override;
	/////////////////////////
	virtual void visit(CNotExpression*) override;
	virtual void visit(CBracketsExpression*) override;
	virtual void visit(CReturnExpression*) override;
	virtual void visit(CFunction*) override;
	virtual void visit(CId*) override;
	virtual void visit(CMainArgument*) override;
	virtual void visit(CMainFunction*) override;
	virtual void visit(CMain*) override;
	virtual void visit(CModifier*) override;
	virtual void visit(CProgram*) override;
	virtual void visit(IStatement*) override;
	virtual void visit(CStatementList*) override;
	virtual void visit(CVisibilityStatement*) override;
	virtual void visit(CIfStatement*) override;
	virtual void visit(CWhileStatement*) override;
	virtual void visit(CPrintStatement*) override;
	virtual void visit(CEqualStatement*) override;
	virtual void visit(CVariableStatement*) override;
	virtual void visit(CType*) override;
	virtual void visit(IValue*) override;
	virtual void visit(CValue*) override;
	virtual void visit(CVariable*) override;


private:
	std::ofstream output;
	std::deque<std::string> nodes;
	std::vector< std::pair<std::string, ITree*> > labels;

	void visitIfNotNull(ITree* node, std::string currentNode);
	void visitIfNotNull(ITree* node, std::string currentNode, std::string adding);
};


