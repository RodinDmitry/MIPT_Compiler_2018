#pragma once

#include <Synthesis/Node.h>
#include <Synthesis/Commands.h>

namespace Synthesis 
{


class IVisitor {
public:
	virtual ~IVisitor() = default;
	
	virtual void visit(const INode* node) = 0;
	virtual void visit(const ICommand* node) = 0;
	virtual void visit(const IExpression* node) = 0;
	virtual void visit(const CConditionalJumpCommand* node) = 0;
	virtual void visit(const CJumpCommand* node) = 0;
	virtual void visit(const CCallFunctionCommand* node) = 0;
	virtual void visit(const CLabelDeclarationCommand* node) = 0;
	virtual void visit(const CMoveRegisterCommand* node) = 0;
	virtual void visit(const CTempExpression* node) = 0;
	virtual void visit(const CAddCommand* node) = 0;
	virtual void visit(const CAddConstCommand* node) = 0;
	virtual void visit(const CSubCommand* node) = 0;
	virtual void visit(const CSubConstCommand* node) = 0;
	virtual void visit(const CMultCommand* node) = 0;
	virtual void visit(const CDivCommand* node) = 0;
	virtual void visit(const CLoadCommand* node) = 0;
	virtual void visit(const CStoreCommand* node) = 0;
	virtual void visit(const CNullExpression* node) = 0;
	virtual void visit(const CExpStatementCommand* node) = 0;
};

} // namespace Synthesis