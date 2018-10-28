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
		CType* returns, CReturnExpression* returnExpression);
	virtual void Accept(IVisitor* visitor) override;

	CModifier* visibility;
	CId* name;
	CArgumentList* arguments;
	CStatementList* body;
	CType* returns;
	CReturnExpression* returnExpression;
};
