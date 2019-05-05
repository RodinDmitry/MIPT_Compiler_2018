#pragma once

#include <cassert>
#include <memory>

#include <IR/IRVisitor.h>

namespace IR {

class CEseqRemoverVisitor : public IIRVisitor {
public:

	std::shared_ptr<const IStatement> getStatementTree();
	std::shared_ptr<const IExpression> getExpressionTree();

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

private:
	void updateLastExpression(const IExpression* newLastExpression);
	void updateLastExpression(std::shared_ptr<const IExpression> newLastExpression);

	void updateLastExpressionList(const CExpressionList* newLastExpressionList);
	void updateLastExpressionList(std::shared_ptr<const CExpressionList> newLastExpressionList);

	void updateLastStatement(const IStatement* newLastStatement);
	void updateLastStatement(std::shared_ptr<const IStatement> newLastStatement);


	std::shared_ptr<const IExpression> processExpression(std::shared_ptr<const IExpression> expression) const;
	std::shared_ptr<const IStatement> processStatement(std::shared_ptr<const IStatement> statement) const;

	bool areCommuting(const IStatement* statement, const IExpression* expression);

	std::shared_ptr<const IExpression> lastExpression;
	std::shared_ptr<const IStatement> lastStatement;
	std::shared_ptr<const CExpressionList> lastExpressionList;
};

} // namespace IR