#pragma once
#include <IR/IRExpression.h>

class IAccess {
public:
	virtual std::shared_ptr<const IR::IExpression> GetExp(std::shared_ptr<const IR::IExpression> framePtr) const = 0;
	virtual ~IAccess() {};
};

class CInRegAccess : public IAccess {
public:
	explicit CInRegAccess(std::shared_ptr<const IR::CTemp> reg);
	std::shared_ptr<const IR::IExpression> GetExp(std::shared_ptr<const IR::IExpression> null) const override;

	~CInRegAccess() {};
private:
	std::shared_ptr<const IR::CTemp> reg;
};

class CInClassAccess : public IAccess {
public:
	CInClassAccess(int _offset, std::shared_ptr<const IR::IExpression> thisExpr);
	std::shared_ptr<const IR::IExpression> GetExp(std::shared_ptr<const IR::IExpression> null) const override;

	~CInClassAccess() {};
private:
	int offset;
	std::shared_ptr<const IR::IExpression> thisExpr;
};

class CInFrameAccess : public IAccess {
public:
	explicit CInFrameAccess(int _offset);
	std::shared_ptr<const IR::IExpression> GetExp(std::shared_ptr<const IR::IExpression> framePtr) const override;

	~CInFrameAccess() {};
private:
	int offset;
};