#pragma once

#include <cassert>
#include <memory>

#include <IR/IRVisitor.h>

namespace IR {

class CLinearizationVisitor : public IIRVisitor {
public:

	std::shared_ptr<const IStatement> getResult();

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
	void updateLastExpression(const IExpression* expression);
	void updateLastExpression(std::shared_ptr<const IExpression> expression);

	void updateLastExpressionList(const CExpressionList* list);
	void updateLastExpressionList(std::shared_ptr<const CExpressionList> list);

	void updateLastStatement(const IStatement* statement);
	void updateLastStatement(std::shared_ptr<const IStatement> statement);

	void saveResult(std::shared_ptr<const IStatement> result);

	std::vector<std::vector<std::shared_ptr<const IStatement>>> statementStack;
	std::vector<int> distanceToSeqStack;
	std::shared_ptr<const IExpression> lastExpression;
	std::shared_ptr<const IStatement> lastStatement;
	std::shared_ptr<const CExpressionList> lastExpressionList;
};

} // namespace IR