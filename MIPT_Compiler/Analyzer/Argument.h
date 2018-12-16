#pragma once

#include <Tree.h>
#include <Variable.h>
#include <vector>

class CArgumentList : public ITree {
public:
	CArgumentList();
	virtual void Accept(IVisitor* visitor) override;
	void Add(CVariable* argument);

	std::vector<std::shared_ptr<CVariable>> arguments;

	std::string GetLabel() const override;
};