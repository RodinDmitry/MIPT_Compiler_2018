#pragma once

#include <Synthesis/Node.h>
#include <Synthesis/Commands.h>

namespace Synthesis 
{


class IVisitor {
public:
	virtual ~IVisitor() = default;
	
	virtual void Visit(const INode*) = 0;
	virtual void Visit(const ICommand*) = 0;
	virtual void Visit(const IExpression*) = 0;
};

} // namespace Synthesis