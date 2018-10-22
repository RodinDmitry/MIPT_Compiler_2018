#pragma once

#include <Tree.h>
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
	virtual void visit(Modifier*) = 0;
	virtual void visit(Value*) = 0;
	virtual void visit(Identifier*) = 0;
	virtual void visit(Statement*) = 0;
	virtual void visit(FunctionCall*) = 0;
	virtual void visit(BinaryOperator*) = 0;
	virtual void visit(Expression*) = 0;
	virtual void visit(TypeIdentifier*) = 0;
	virtual void visit(MainMethodDeclaration*) = 0;
	virtual void visit(MethodDeclaration*) = 0;
	virtual void visit(VarDeclaration*) = 0;
	virtual void visit(Argument*) = 0;
	virtual void visit(ClassInternals*) = 0;
	virtual void visit(ClassStart*) = 0;
	virtual void visit(ClassDeclaration*) = 0;
	virtual void visit(MainClass*) = 0;
	virtual void visit(Goal*) = 0;
};

class CPrettyPrinter : public IVisitor {
public:

	CPrettyPrinter(std::string name);

	void close();

	virtual void visit(ITree*) override;
	virtual void visit(Modifier*) override;
	virtual void visit(Value*) override;
	virtual void visit(Identifier*) override;
	virtual void visit(Statement*) override;
	virtual void visit(FunctionCall*) override;
	virtual void visit(BinaryOperator*) override;
	virtual void visit(Expression*) override;
	virtual void visit(TypeIdentifier*) override;
	virtual void visit(MainMethodDeclaration*) override;
	virtual void visit(MethodDeclaration*) override;
	virtual void visit(VarDeclaration*) override;
	virtual void visit(Argument*) override;
	virtual void visit(ClassInternals*) override;
	virtual void visit(ClassStart*) override;
	virtual void visit(ClassDeclaration*) override;
	virtual void visit(MainClass*) override;
	virtual void visit(Goal*) override;

private:
	std::ofstream output;
	std::deque<std::string> nodes;

	void visitNullable(ITree* node, std::string& currentNode);
};


inline void CPrettyPrinter::visitNullable(ITree* node, std::string& currentNode) {
	if (node != nullptr) {
		node->Accept(this);
		output << currentNode << " -- " << nodes.front() << std::endl;
		nodes.pop_front();
		printerSet.erase(node);
	}
}

inline CPrettyPrinter::CPrettyPrinter(std::string name) {
	output.open(name, std::ofstream::out);
	output << "strict graph {" << std::endl;
}

inline void CPrettyPrinter::close()
{
	output << "}" << std::endl;
}
