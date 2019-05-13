#pragma once

#include <cassert>
#include <memory>

#include <IR/IRVisitor.h>

namespace IR {

class CBlockVisitor : public IIRVisitor {
public:

	inline std::shared_ptr<std::vector<std::shared_ptr<CStatementList>>> getResult() { return blocks; }

	virtual void visit(const ITree* node) override { assert(false); }
	virtual void visit(const IExpression* node) override { assert(false); }
	virtual void visit(const CExpressionList* node) override { lastVisitedNodeType = TNodeType::OTHER; }
	virtual void visit(const CConstExpression* node) override { lastVisitedNodeType = TNodeType::OTHER; }
	virtual void visit(const CNameExpression* node) override { lastVisitedNodeType = TNodeType::OTHER; }
	virtual void visit(const CTempExpression* node) override { lastVisitedNodeType = TNodeType::OTHER; }
	virtual void visit(const CBinaryExpression* node) override { lastVisitedNodeType = TNodeType::OTHER; } 
	virtual void visit(const CMemExpression* node) override { lastVisitedNodeType = TNodeType::OTHER; }
	virtual void visit(const CCallExpression* node) override { lastVisitedNodeType = TNodeType::OTHER; }
	virtual void visit(const CEseqExpression* node) override { assert(false); }
	virtual void visit(const IStatement* node) override { assert(false); }
	virtual void visit(const CMoveStatement* node) override { lastVisitedNodeType = TNodeType::OTHER; }
	virtual void visit(const CExpStatement* node) override { lastVisitedNodeType = TNodeType::OTHER; }
	virtual void visit(const CJumpStatement* node) override { lastVisitedNodeType = TNodeType::JUMP; }
	virtual void visit(const CJumpConditionalStatement* node) override { lastVisitedNodeType = TNodeType::JUMP; }
	virtual void visit(const CSeqStatement* node) override { assert(false); }
	virtual void visit(const CLabelStatement* node) override;
	virtual void visit(const CStatementList* node) override;

private:
	enum class TNodeType {
		LABEL, 
		JUMP, 
		OTHER
	};

	void saveBlock(std::shared_ptr<CStatementList> block, TNodeType previousNodeType, bool isLastBlock);
	std::shared_ptr<CStatementList> newBlock();

	CLabel lastVisitedLabel;
	TNodeType lastVisitedNodeType;
	std::shared_ptr<std::vector<std::shared_ptr<CStatementList>>> blocks;
};

} // namespace IR