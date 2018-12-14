#pragma once

#include <string>
#include <assert.h>

namespace IR {

class IIRVisitor;

class ITree {
public:
	ITree() = default;
	virtual ~ITree() = default;

	virtual void Accept(IIRVisitor* visitor);

};

} // namespace IR