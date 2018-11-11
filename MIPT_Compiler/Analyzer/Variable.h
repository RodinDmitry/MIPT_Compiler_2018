#pragma once

#include <Tree.h>
#include <Type.h>

class CId;

class CVariable : public ITree {
public:

	CVariable(CType* type, CId* name);
	virtual void Accept(IVisitor* visitor) override;

	CType* type;
	CId* name;

	std::string GetLabel() override;
};