#pragma once

#include <IFrame.h>
#include <Type.h>
#include <vector>
#include <map>
#include <ClassInfo.h>

class CMiniJavaFrame : public IFrame {
public:
	virtual void AddFormal(const CSymbol* name, const CType* type) override;
	virtual void AddLocal(const CSymbol* name, const CType* type) override;
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

class CMiniJavaMethodFrame : public CMiniJavaFrame {
public:
	CMiniJavaMethodFrame(const CType* classType, const CType* returnType);
	CMiniJavaMethodFrame(const CClassInfo* classInfo, const CFunctionInfo* info);

	virtual const IAccess* GetThis() const;
	virtual const IAccess* GetReturn() const;
	virtual const IAccess* GetFP() const;
	virtual const IAccess* GetSP() const;
private:
	void initStatic();

	static CSymbol* thisName;
	static CSymbol* returnName;
	static CSymbol* framePointerName;
	static CSymbol* stackPointerName;
};