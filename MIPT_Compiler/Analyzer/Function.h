#pragma once

#include<Tree.h>

class CModifier;
class CId;
class CArgumentList;
class CStatementList;
class CType;
class CReturnExpression;

class CFunction : public ITree {
public:
	CFunction(CModifier* visibility, CId* name, CArgumentList* arguments, CStatementList* body,
		CType* returns, CReturnExpression* returnExpression, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CModifier> visibility;
	std::unique_ptr<CId> name;
	std::unique_ptr<CArgumentList> arguments;
	std::unique_ptr<CStatementList> body;
	std::unique_ptr<CType> returns;
	std::unique_ptr<CReturnExpression> returnExpression;

	std::string GetLabel() override;
};
