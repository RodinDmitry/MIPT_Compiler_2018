#pragma once


namespace Synthesis
{
class IVisitor;

class INode {
public:
	virtual ~INode() = default;
	virtual void Accept(IVisitor* visitor) const = 0;
};
}
