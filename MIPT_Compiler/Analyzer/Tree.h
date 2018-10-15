#pragma once


class IVisitor;

class ITree {
public:
	virtual void Accept(IVisitor* visitor) = 0;
};


class IExpression : public ITree {

};
