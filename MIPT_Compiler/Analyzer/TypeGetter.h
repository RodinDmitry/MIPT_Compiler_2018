#pragma once

#include <Visitor.h>
#include <SymbolTable.h>

class CTypeGetter : public IVisitor {
public:
	std::shared_ptr<CType> GetType(IExpression* node, std::string symbolTable);
	virtual void visit(ITree*) override { assert(false); }
	virtual void visit(CArgumentList*) override { assert(false); }
	virtual void visit(CClassDeclaration*) override { assert(false); }
	virtual void visit(CClassInternals*) override { assert(false); }
	virtual void visit(CClassInternalsList*) override { assert(false); }
	virtual void visit(CClass*) override { assert(false); }
	virtual void visit(CClassList*) override { assert(false); }
	virtual void visit(IExpression*) override { assert(false); }
	virtual void visit(CExpressionList*) override { assert(false); }
	virtual void visit(CLValueExpression*) override { assert(false); }
	virtual void visit(CBinaryExpression*) override;
	virtual void visit(CArrayExpression*) override;
	virtual void visit(CCallExpression*) override;
	virtual void visit(CValueExpression*) override;
	virtual void visit(CNewArrayExpression*) override;
	virtual void visit(CNewExpression*) override;
	virtual void visit(CIdExpression*) override;
	virtual void visit(CThisExpression*) override;
	virtual void visit(CNotExpression*) override;
	virtual void visit(CBracketsExpression*) override;
	virtual void visit(CReturnExpression*) override;
	virtual void visit(CFunction*) override { assert(false); }
	virtual void visit(CId*) override { assert(false); }
	virtual void visit(CMainArgument*) override { assert(false); }
	virtual void visit(CMainFunction*) override { assert(false); }
	virtual void visit(CMain*) override { assert(false); }
	virtual void visit(CModifier*) override { assert(false); }
	virtual void visit(CProgram*) override { assert(false); }
	virtual void visit(IStatement*) override { assert(false); }
	virtual void visit(CStatementList*) override { assert(false); }
	virtual void visit(CVisibilityStatement*) override { assert(false); }
	virtual void visit(CIfStatement*) override { assert(false); }
	virtual void visit(CWhileStatement*) override { assert(false); }
	virtual void visit(CPrintStatement*) override { assert(false); }
	virtual void visit(CAssignStatement*) override { assert(false); }
	virtual void visit(CVariableStatement*) override { assert(false); }
	virtual void visit(CType*) override { assert(false); }
	virtual void visit(IValue*) override { assert(false); }
	virtual void visit(CValue*) override;
	virtual void visit(CVariable*) override { assert(false); }

private:  

	std::shared_ptr<CType> checkType();
	
	std::vector<std::shared_ptr<CType>> resultingTypes;
	std::deque<ITree*> waitingNodes;
	std::string symbolTable;
};