#pragma once

#include <Tree.h>

class CStatementBase : public ITree
{
public:
	CStatementBase(CStatementBase* next);
	virtual void Accept(IVisitor* visitor) override;

	CStatementBase* next;
};