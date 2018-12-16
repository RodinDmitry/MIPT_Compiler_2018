#pragma once

#include <IR/IRTree.h>
#include <IR/IRExpression.h>
#include <IR/IRStatement.h>

namespace IR {

class IIRVisitor {
public:
	virtual void visit(const ITree* node) = 0;
	virtual void visit(const IExpression* node) = 0;
	virtual void visit(const CExpressionList* node) = 0;
	virtual void visit(const CConstExpression* node) = 0;
	virtual void visit(const CNameExpression* node) = 0;
	virtual void visit(const CTempExpression* node) = 0;
	virtual void visit(const CBinaryExpression* node) = 0;
	virtual void visit(const CMemExpression* node) = 0;
	virtual void visit(const CCallExpression* node) = 0;
	virtual void visit(const CEseqExpression* node) = 0;
	virtual void visit(const IStatement* node) = 0;
	virtual void visit(const CMoveStatement* node) = 0;
	virtual void visit(const CExpStatement* node) = 0;
	virtual void visit(const CJumpStatement* node) = 0;
	virtual void visit(const CJumpConditionalStatement* node) = 0;
	virtual void visit(const CSeqStatement* node) = 0;
	virtual void visit(const CLabelStatement* node) = 0;
	virtual void visit(const CStatementList* node) = 0;
};

}