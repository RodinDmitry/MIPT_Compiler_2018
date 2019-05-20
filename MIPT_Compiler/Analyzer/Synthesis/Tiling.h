#pragma once

#include <IR/IRVisitor.h>

#include <IR/IRExpression.h>
#include <IR/IRStatement.h>

#include <Synthesis/Patterns.h>

#include <vector>
#include <memory>


namespace Synthesis {

	class CTilingVisitor : public IR::IIRVisitor {
	public:
		CTilingVisitor(const IR::ITree* _root) : root(_root) {
			patterns.push_back(std::make_shared<CTempPattern>(&dynamic));
			patterns.push_back(std::make_shared<CLabelPattern>(&dynamic));
			patterns.push_back(std::make_shared<CAddPattern>(&dynamic));
			patterns.push_back(std::make_shared<CSubPattern>(&dynamic));
			patterns.push_back(std::make_shared<CMultPattern>(&dynamic));
			patterns.push_back(std::make_shared<CDivPattern>(&dynamic));
			patterns.push_back(std::make_shared<CSubConstPattern>(&dynamic));
			patterns.push_back(std::make_shared<CAddConstLeftPattern>(&dynamic));
			patterns.push_back(std::make_shared<CAddConstRightPattern>(&dynamic));
			patterns.push_back(std::make_shared<CConstPattern>(&dynamic));
			patterns.push_back(std::make_shared<CLoadMemoryPattern>(&dynamic));
			patterns.push_back(std::make_shared<CLoadConstMemoryPattern>(&dynamic));
			patterns.push_back(std::make_shared<CLoadMemoryLeftOffsetPattern>(&dynamic));
			patterns.push_back(std::make_shared<CLoadMemoryRightOffsetPattern>(&dynamic));
			patterns.push_back(std::make_shared<CStoreMemoryPattern>(&dynamic));
			patterns.push_back(std::make_shared<CStoreConstMemoryPattern>(&dynamic));
			patterns.push_back(std::make_shared<CStoreMemoryLeftOffsetPattern>(&dynamic));
			patterns.push_back(std::make_shared<CStoreMemoryRightOffsetPattern>(&dynamic));
			patterns.push_back(std::make_shared<CStoreRegisterPattern>(&dynamic));
			patterns.push_back(std::make_shared<CCallFunctionPattern>(&dynamic));
			patterns.push_back(std::make_shared<CJumpPattern>(&dynamic));
			patterns.push_back(std::make_shared<CConditionalJumpPattern>(&dynamic));
			patterns.push_back(std::make_shared<CExpStatementPattern>(&dynamic));
			patterns.push_back(std::make_shared<CNamePattern>(&dynamic));

		}
		~CTilingVisitor() = default;


		void ApplyPatterns(const IR::ITree* node) {
			for (const auto& pattern : patterns) {
				pattern->Consume(node);
			}
		}

		virtual void visit(const IR::ITree* node) override;
		virtual void visit(const IR::IExpression* node) override;
		virtual void visit(const IR::CExpressionList* node) override;
		virtual void visit(const IR::CConstExpression* node) override;
		virtual void visit(const IR::CNameExpression* node) override;
		virtual void visit(const IR::CTempExpression* node) override;
		virtual void visit(const IR::CBinaryExpression* node) override;
		virtual void visit(const IR::CMemExpression* node) override;
		virtual void visit(const IR::CCallExpression* node) override;
		virtual void visit(const IR::CEseqExpression* node) override;
		virtual void visit(const IR::IStatement* node) override;
		virtual void visit(const IR::CMoveStatement* node) override;
		virtual void visit(const IR::CExpStatement* node) override;
		virtual void visit(const IR::CJumpStatement* node) override;
		virtual void visit(const IR::CJumpConditionalStatement* node) override;
		virtual void visit(const IR::CSeqStatement* node) override;
		virtual void visit(const IR::CLabelStatement* node) override;
		virtual void visit(const IR::CStatementList* node) override;

		const ICommand* Result() const { return dynamic.at(root).second.get(); }

	private:
		Dynamic dynamic;
		std::vector<std::shared_ptr<CPattern>> patterns;
		const IR::ITree* root;
	};

}