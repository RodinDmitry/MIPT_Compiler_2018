#pragma once

#include <Symbol.h>
#include <Access.h>
#include <IR/IRExpression.h>

class CType;

class IFrame {
public:
	virtual void AddFormal(const CSymbol* name, const CType* type) = 0;
	virtual void AddLocal(const CSymbol* name, const CType* type) = 0;
	virtual int FormalsCount() const = 0;
	virtual std::shared_ptr<const IR::IExpression> GetWordSize() const = 0;
	virtual const IAccess* GetFormal(int index) const = 0;
	virtual const IAccess* FindFormalorLocal(const CSymbol* name) const = 0;
	virtual int GetTotalSize() const = 0;

	virtual ~IFrame() = default;
};
