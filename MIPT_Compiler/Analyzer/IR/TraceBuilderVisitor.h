#pragma once

#include <cassert>
#include <memory>

#include <IR/IRVisitor.h>

namespace IR {

class CTraceBuilderVisitor : public IIRVisitor {
public:

	inline const std::string& getLabel() { return startLabel->GetLabel(); }
	inline const std::string& getTrueTarget() { return trueTargetLabel->GetLabel(); }
	inline const std::string& getFalseTarget() { return falseTragetLabel->GetLabel(); }
	inline bool isConditional() { return isJumpConditional; }


	virtual void visit(const ITree* node) override { assert(false); }
	virtual void visit(const IExpression* node) override { assert(false); }
	virtual void visit(const CExpressionList* node) override { assert(false); }
	virtual void visit(const CConstExpression* node) override { assert(false); }
	virtual void visit(const CNameExpression* node) override { assert(false); }
	virtual void visit(const CTempExpression* node) override { assert(false); }
	virtual void visit(const CBinaryExpression* node) override { assert(false); }
	virtual void visit(const CMemExpression* node) override { assert(false); }
	virtual void visit(const CCallExpression* node) override { assert(false); }
	virtual void visit(const CEseqExpression* node) override { assert(false); }
	virtual void visit(const IStatement* node) override { assert(false); }
	virtual void visit(const CMoveStatement* node) override { assert(false); }
	virtual void visit(const CExpStatement* node) override { assert(false); }
	virtual void visit(const CJumpStatement* node) override;
	virtual void visit(const CJumpConditionalStatement* node) override;
	virtual void visit(const CSeqStatement* node) override { assert(false); }
	virtual void visit(const CLabelStatement* node) override;
	virtual void visit(const CStatementList* node) override;

private:
	
	CLabel* startLabel;
	CLabel* trueTargetLabel;
	CLabel* falseTragetLabel;
	bool isJumpConditional;
};

} // namespace IR