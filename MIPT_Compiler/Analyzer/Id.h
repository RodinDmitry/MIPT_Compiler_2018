#pragma once

#include <Tree.h>

class CId : public ITree {
public:
	CId(char* name);
	virtual void Accept(IVisitor* visitor) override;

	std::string name;
};