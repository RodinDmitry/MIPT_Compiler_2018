#pragma once

#include <IR/IRTree.h>
#include <IR/IRExpression.h>
#include <IR/IRStatement.h>

namespace IR {

class IIRVisitor {
public:
	virtual void visit(ITree* node) = 0;
	virtual void visit(IExpression* node) = 0;
	virtual void visit(CExpressionList* node) = 0;
	virtual void visit(CConstExpression* node) = 0;
	virtual void visit(CNameExpression* node) = 0;
	virtual void visit(CTempExpression* node) = 0;
	virtual void visit(CBinaryExpression* node) = 0;
	virtual void visit(CMemExpression* node) = 0;
	virtual void visit(CCallExpression* node) = 0;
	virtual void visit(CEseqExpression* node) = 0;
	virtual void visit(IStatement* node) = 0;
	virtual void visit(CMoveStatement* node) = 0;
	virtual void visit(CExpStatement* node) = 0;
	virtual void visit(CJumpStatement* node) = 0;
	virtual void visit(CJumpConditionalStatement* node) = 0;
	virtual void visit(CSeqStatement* node) = 0;
	virtual void visit(CLabelStatement* node) = 0;
	virtual void visit(CStatementList* node) = 0;
};

}