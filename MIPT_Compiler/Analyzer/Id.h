#pragma once

#include <Tree.h>

class CId : public ITree {
public:
	CId(char* name, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::string name;

	std::string GetLabel() const override;
};