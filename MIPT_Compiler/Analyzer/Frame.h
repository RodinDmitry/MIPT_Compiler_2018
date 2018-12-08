#pragma once

#include <Symbol.h>
#include <Access.h>
#include <Type.h>
#include <vector>
#include <map>

class IFrame {
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
	virtual void AddFormal(const CSymbol* name, const CType* type);
	virtual void AddLocal(const CSymbol* name, const CType* type);
	virtual int FormalsCount() const;
	virtual const IAccess* GetFormal(int index) const;
	virtual const IAccess* FindFormalorLocal(const CSymbol* name) const;
	void Finalize();
	virtual int GetTotalSize() const;

	static int GetOffset(TDataType type);
protected:
	int currOffset = 0;
	std::vector< std::unique_ptr<const IAccess> > formals;
	std::vector< std::unique_ptr<const IAccess> > locals;
	std::map< const CSymbol*, const IAccess* > namesMap;
	bool isFinalized = false;
};

class CNestedFrame : public CMiniJavaFrame {
public:

};



class CFunctionFrame : public CMiniJavaFrame {
public:
private:

};