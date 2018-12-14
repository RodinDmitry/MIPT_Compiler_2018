#pragma once

#include <Tree.h>
#include <Type.h>

class CId;

class CVariable : public ITree {
public:

	CVariable(CType* type, CId* name, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CType> type;
	std::unique_ptr<CId> name;

	std::string GetLabel() const override;
};