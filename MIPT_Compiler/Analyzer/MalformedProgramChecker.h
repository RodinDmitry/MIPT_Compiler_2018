#pragma once
#include <Visitor.h>
#include <SymbolTable.h>

class CMalformedProgramChecker : public IVisitor {
public:

	void BuildTable(ITree* startNode, std::string tableName);

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
	virtual void visit(CNotExpression*) override;
	virtual void visit(CBracketsExpression*) override;
	virtual void visit(CReturnStatement*) override;
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
	virtual void visit(CAssignStatement*) override;
	virtual void visit(CVariableStatement*) override;
	virtual void visit(CType*) override;
	virtual void visit(IValue*) override;
	virtual void visit(CValue*) override;
	virtual void visit(CVariable*) override;
	virtual void visit(CVisibilityBlockStart*) override;
	virtual void visit(CVisibilityBlockEnd*) override;
	virtual void visit(CCallLengthExpression*) override;

private:

	CVariableInfo* createVariableInfo(CVariable*);
	CFunctionInfo* createFunctionInfo(CFunction*);
	CFunctionInfo* createFunctionInfo(CMainFunction*);
	void createEnterPlaceholder();
	void createLeavePlaceholder();
	void cleanup();
	bool checkVariableDoubleDeclaration(const CSymbol* symbol);
	bool checkFunctionDoubleDeclaration(const CSymbol* symbol);
	bool checkClassDoubleDeclaration(const CSymbol* symbol);
	bool checkMemberDoubleDeclaration(const CSymbol * symbol);

	std::deque<ITree*> waitingNodes;
	std::vector<std::shared_ptr<ITree>> placeholders;
	std::string tableName;
};