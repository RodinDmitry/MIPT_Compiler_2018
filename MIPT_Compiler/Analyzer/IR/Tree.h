#pragma once

#include <string>
#include <assert.h>

namespace IR {

class IVisitor;

class ITree {
public:
	ITree() = default;
	virtual ~ITree() = default;

	virtual void Accept(IVisitor* visitor) = 0;

	virtual const std::string& GetLabel() { assert(false); }
	void AddToLabel(const std::string& adding) { labelAddings += adding; }

protected:

	std::string labelAddings = "";
};

} // namespace IR