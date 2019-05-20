#pragma once

#include <Synthesis/Visitor.h>
#include <Synthesis/AsmCommand.h>
#include <map>
#include <string>
#include <vector>

namespace Synthesis {

	class CCommandBuilder : public IVisitor {
	public:
		CCommandBuilder();
		virtual ~CCommandBuilder() = default;

		virtual void visit(const INode* node) override;
		virtual void visit(const ICommand* node) override;
		virtual void visit(const IExpression* node) override;
		virtual void visit(const CConditionalJumpCommand* node) override;
		virtual void visit(const CJumpCommand* node) override;
		virtual void visit(const CCallFunctionCommand* node) override;
		virtual void visit(const CLabelDeclarationCommand* node) override;
		virtual void visit(const CMoveRegisterCommand* node) override;
		virtual void visit(const CTempExpression* node) override;
		virtual void visit(const CAddCommand* node) override;
		virtual void visit(const CAddConstCommand* node) override;
		virtual void visit(const CSubCommand* node) override;
		virtual void visit(const CSubConstCommand* node) override;
		virtual void visit(const CMultCommand* node) override;
		virtual void visit(const CDivCommand* node) override;
		virtual void visit(const CLoadCommand* node) override;
		virtual void visit(const CStoreCommand* node) override;
		virtual void visit(const CNullExpression* node) override;
		virtual void visit(const CExpStatementCommand* node) override;

		const std::vector<CAsmCommand>& Result() const {
			return commands;
		}

	private:
		std::string lastRegisterValue;
		std::vector<CAsmCommand> commands;

		std::map<std::string, std::string> tempToRegister;
	};

}; // Synthesis