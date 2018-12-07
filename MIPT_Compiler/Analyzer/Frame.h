#pragma once

#include <Symbol.h>
#include <Access.h>
#include <vector>

class IFrame {
public:
	virtual void AddFormal(const CSymbol* name) = 0;
	virtual void AddLocal(const CSymbol* name) = 0;
	virtual int FormalsCount() const = 0;
	virtual const IAccess* GetFormal(int index) const = 0;
	virtual const IAccess* FindFormalorLocal(const CSymbol* name) const = 0;
	virtual int GetTotalSize() const = 0;
};

class CNestedFrame : public IFrame {
public:
	virtual void AddFormal(const CSymbol* name) = 0;
	virtual void AddLocal(const CSymbol* name) = 0;
	virtual int FormalsCount() const = 0;
	virtual const IAccess* GetFormal(int index) const = 0;
	virtual const IAccess* FindFormalorLocal(const CSymbol* name) const = 0;
	virtual int GetTotalSize() const = 0;
};

class CMiniJavaFrame : public IFrame {
public:
	virtual void AddFormal(const CSymbol* name) = 0;
	virtual void AddLocal(const CSymbol* name) = 0;
	virtual int FormalsCount() const = 0;
	virtual const IAccess* GetFormal(int index) const = 0;
	virtual const IAccess* FindFormalorLocal(const CSymbol* name) const = 0;
	void Finalize();
	virtual int GetTotalSize() const = 0;
private:
	int currOffset = 0;
	std::vector< std::unique_ptr<const IAccess> > formals;
	std::vector< std::unique_ptr<const IAccess> > locals;
	std::vector< std::unique_ptr<const CNestedFrame> > nested;
	bool isFinalized;
};