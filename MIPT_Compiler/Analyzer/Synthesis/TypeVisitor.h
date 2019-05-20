#pragma once

#include <IR/IRVisitor.h>
#include <IR/IRExpression.h>

namespace Synthesis {

template<typename T>
class CTypeVisitor : public IR::IIRVisitor {
public:
	CTypeVisitor(bool _verbose = false) : node(nullptr) {}
	~CTypeVisitor() {}

	// Visitors for different node types.
	void visit(const IR::CConstExpression* exprssion) override {}
	void visit(const IR::CNameExpression* expression) override {}
	void visit(const IR::CTempExpression* expression) override {}
	void visit(const IR::CBinaryExpression* expression) override {}
	void visit(const IR::CMemExpression* expression) override {}
	void visit(const IR::CCallExpression* expression) override {}
	void visit(const IR::CEseqExpression* expression) override {}
	void visit(const IR::CExpStatement* statement) override {}
	void visit(const IR::CJumpConditionalStatement* statement) override {}
	void visit(const IR::CJumpStatement* statement) override {}
	void visit(const IR::CLabelStatement* statement) override {}
	void visit(const IR::CMoveStatement* statement) override {}
	void visit(const IR::CSeqStatement* statement) override {}
	void visit(const IR::CExpressionList* list) override {}
	void visit(const IR::CStatementList* list) override {}

	void visit(const IR::ITree* node) override {};
	void visit(const IR::IExpression* node) override {};
	void visit(const IR::IStatement* node) override {};

	const T* GetNode();
private:
	const T* node;
};

template<>
void CTypeVisitor<IR::CConstExpression>::visit(const IR::CConstExpression* expression) {
	node = expression;
}

template<>
void CTypeVisitor<IR::CNameExpression>::visit(const IR::CNameExpression* expression) {
	node = expression;
}

template<>
void CTypeVisitor<IR::CTempExpression>::visit(const IR::CTempExpression* expression) {
	node = expression;
}

template<>
void CTypeVisitor<IR::CBinaryExpression>::visit(const IR::CBinaryExpression* expression) {
	node = expression;
}

template<>
void CTypeVisitor<IR::CMemExpression>::visit(const IR::CMemExpression* expression) {
	node = expression;
}

template<>
void CTypeVisitor<IR::CCallExpression>::visit(const IR::CCallExpression* expression) {
	node = expression;
}

template<>
void CTypeVisitor<IR::CEseqExpression>::visit(const IR::CEseqExpression* expression) {
	node = expression;
}

template<>
void CTypeVisitor<IR::CExpStatement>::visit(const IR::CExpStatement* statement) {
	node = statement;
}

template<>
void CTypeVisitor<IR::CJumpConditionalStatement>::visit(
	const IR::CJumpConditionalStatement* statement) {
	node = statement;
}

template<>
void CTypeVisitor<IR::CJumpStatement>::visit(const IR::CJumpStatement* statement) {
	node = statement;
}

template<>
void CTypeVisitor<IR::CLabelStatement>::visit(const IR::CLabelStatement* statement) {
	node = statement;
}

template<>
void CTypeVisitor<IR::CMoveStatement>::visit(const IR::CMoveStatement* statement) {
	node = statement;
}

template<>
void CTypeVisitor<IR::CSeqStatement>::visit(const IR::CSeqStatement* statement) {
	node = statement;
}

template<>
void CTypeVisitor<IR::CExpressionList>::visit(const IR::CExpressionList* list) {
	node = list;
}

template<>
void CTypeVisitor<IR::CStatementList>::visit(const IR::CStatementList* list) {
	node = list;
}

template<typename T>
const T* CTypeVisitor<T>::GetNode() {
	return node;
}

}