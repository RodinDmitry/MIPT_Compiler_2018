#pragma once

#include <Symbol.h>
#include <Access.h>
#include <IR/IRExpression.h>

class CType;

class IFrame {
public:
	virtual void AddFormal(const CSymbol* name) = 0;
	virtual void AddLocal(const CSymbol* name) = 0;
	virtual int FormalsCount() const = 0;
	virtual std::shared_ptr<const IR::IExpression> GetWordSize() const = 0;
	virtual const IAccess* GetFormal(int index) const = 0;
	virtual const IAccess* FindFormalorLocal(const CSymbol* name) const = 0;
	virtual const std::shared_ptr<const IR::IExpression> GetFramePtr() const = 0;

	virtual const IAccess* GetThis() const = 0;
	virtual const IAccess* GetReturn() const = 0;
	virtual const IAccess* GetFP() const = 0;
	virtual const IAccess* GetSP() const = 0;

	virtual std::shared_ptr<const IR::IExpression> ExternalCall(const std::string& functionName, std::shared_ptr<const IR::CExpressionList> args) const = 0;

	virtual ~IFrame() = default;
};
