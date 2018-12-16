#pragma once

#include <IFrame.h>
#include <Type.h>
#include <vector>
#include <map>
#include <FunctionInfo.h>

class CMiniJavaMethodFrame : public IFrame {
public:
	CMiniJavaMethodFrame(const CType* classType, const CType* returnType);
	CMiniJavaMethodFrame(const CClassInfo* classInfo, const CFunctionInfo* info);

	virtual void AddFormal(const CSymbol* name) override;
	virtual void AddLocal(const CSymbol* name) override;
	virtual int FormalsCount() const override;
	virtual const IAccess* GetFormal(int index) const override;
	virtual const IAccess* FindFormalorLocal(const CSymbol* name) const override;

	virtual std::shared_ptr<const IR::IExpression> GetWordSize() const override;
	virtual const std::shared_ptr<const IR::IExpression> GetFramePtr() const override;

	virtual const IAccess* GetThis() const override;
	virtual const IAccess* GetReturn() const override;
	virtual const IAccess* GetFP() const override;
	virtual const IAccess* GetSP() const override;

	std::shared_ptr<const IR::IExpression> ExternalCall(const std::string& functionName, std::shared_ptr<const IR::CExpressionList> args) const override;
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