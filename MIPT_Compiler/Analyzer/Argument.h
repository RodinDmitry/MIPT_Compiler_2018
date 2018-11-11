#pragma once

#include <Tree.h>
#include <Variable.h>
#include <vector>

class CArgumentList : public ITree {
public:
	virtual void Accept(IVisitor* visitor) override;
	void Add(CVariable* argument);

	std::vector<CVariable*> arguments;

	std::string GetLabel() override;
};