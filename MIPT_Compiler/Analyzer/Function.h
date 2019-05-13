#pragma once

#include<Tree.h>

class CModifier;
class CId;
class CArgumentList;
class CStatementList;
class CType;
class CReturnStatement;

class CFunction : public ITree {
public:
	CFunction(CModifier* visibility, CId* name, CArgumentList* arguments, CStatementList* body,
		CType* returns, CReturnStatement* returnExpression, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CModifier> visibility;
	std::unique_ptr<CId> name;
	std::unique_ptr<CArgumentList> arguments;
	std::unique_ptr<CStatementList> body;
	std::shared_ptr<CType> returns;
	std::unique_ptr<CReturnStatement> returnExpression;

	std::string GetLabel() const override;
};
