#pragma once
#include <IR/IRVisitor.h>

namespace IR {

class CIRPrinterVisitor : IIRVisitor {
public:

	void PrintTree(ITree* root);

	virtual void visit(ITree* node) override;
	virtual void visit(IExpression* node) override;
	virtual void visit(CExpressionList* node) override;
	virtual void visit(CConstExpression* node) override;
	virtual void visit(CNameExpression* node) override;
	virtual void visit(CTempExpression* node) override;
	virtual void visit(CBinaryExpression* node) override;
	virtual void visit(CMemExpression* node) override;
	virtual void visit(CCallExpression* node) override;
	virtual void visit(CEseqExpression* node) override;
	virtual void visit(IStatement* node) override;
	virtual void visit(CMoveStatement* node) override;
	virtual void visit(CExpStatement* node) override;
	virtual void visit(CJumpStatement* node) override;
	virtual void visit(CJumpConditionalStatement* node) override;
	virtual void visit(CSeqStatement* node) override;
	virtual void visit(CLabelStatement* node) override;
	virtual void visit(CStatementList* node) override;
};

} //IR