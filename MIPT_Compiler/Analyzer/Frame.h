#pragma once

#include <IFrame.h>
#include <Type.h>
#include <vector>
#include <map>
#include <ClassInfo.h>

class CMiniJavaMethodFrame : public IFrame {
public:
	CMiniJavaMethodFrame(const CType* classType, const CType* returnType);
	CMiniJavaMethodFrame(const CClassInfo* classInfo, const CFunctionInfo* info);

	virtual void AddFormal(const CSymbol* name) override;
	virtual void AddLocal(const CSymbol* name) override;
	virtual int FormalsCount() const;
	virtual const IAccess* GetFormal(int index) const;
	virtual const IAccess* FindFormalorLocal(const CSymbol* name) const;

	virtual std::shared_ptr<const IR::IExpression> GetWordSize() const;
	virtual const std::shared_ptr<const IR::IExpression> GetFramePtr() const;

	virtual const IAccess* GetThis() const;
	virtual const IAccess* GetReturn() const;
	virtual const IAccess* GetFP() const;
	virtual const IAccess* GetSP() const;

	std::shared_ptr<const IR::IExpression> ExternalCall(const std::string& functionName, std::shared_ptr<const IR::CExpressionList> args) const;
private:
	void initStatic();

	int currOffset = 0;
	std::vector< std::unique_ptr<const IAccess> > formals;
	std::vector< std::unique_ptr<const IAccess> > locals;
	std::map< const CSymbol*, const IAccess* > namesMap;

	static CSymbol* thisName;
	static CSymbol* returnName;
	static CSymbol* framePointerName;
	static CSymbol* stackPointerName;
	const static int wordSize;

	void AddRegister(const CSymbol* regName, const CSymbol* name);
};