#pragma once
#include <IR/IRVisitor.h>
#include <fstream>
#include <deque>

namespace IR {

class CIRPrinterVisitor : IIRVisitor {
public:
	explicit CIRPrinterVisitor(const std::string& name);
	void PrintTree(const ITree* root);
	void close();

	virtual void visit(const ITree* node) override;
	virtual void visit(const IExpression* node) override;
	virtual void visit(const CExpressionList* node) override;
	virtual void visit(const CConstExpression* node) override;
	virtual void visit(const CNameExpression* node) override;
	virtual void visit(const CTempExpression* node) override;
	virtual void visit(const CBinaryExpression* node) override;
	virtual void visit(const CMemExpression* node) override;
	virtual void visit(const CCallExpression* node) override;
	virtual void visit(const CEseqExpression* node) override;
	virtual void visit(const IStatement* node) override;
	virtual void visit(const CMoveStatement* node) override;
	virtual void visit(const CExpStatement* node) override;
	virtual void visit(const CJumpStatement* node) override;
	virtual void visit(const CJumpConditionalStatement* node) override;
	virtual void visit(const CSeqStatement* node) override;
	virtual void visit(const CLabelStatement* node) override;
	virtual void visit(const CStatementList* node) override;

private:
	static int lastId;
	std::ofstream output;
	std::deque<std::string> nodes;
	std::vector< std::pair<std::string, ITree*> > labels;

	void visitIfNotNull(const ITree* node, const std::string& currentNode);
	std::string labelNode(const std::string& name, const std::string& adding);
	std::string operationName(TLogicOperatorType type);
	std::string operatorName(TOperator type);
};

} //IR