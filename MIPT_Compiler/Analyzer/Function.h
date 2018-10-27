#pragma once

#include<Tree.h>

class CModifier;
class CId;
class CArgumentList;
class CStatementList;

class CFunction : public ITree {
public:
	CFunction(CModifier* visibility, CId* name, CArgumentList* arguments, CStatementList* body);
	virtual void Accept(IVisitor* visitor) override;

	CModifier* visibility;
	CId* name;
	CArgumentList* arguments;
	CStatementList* body;
};
