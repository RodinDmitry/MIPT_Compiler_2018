#pragma once

#include <IFrame.h>
#include <Type.h>
#include <vector>
#include <map>
#include <FunctionInfo.h>

class CMiniJavaMethodFrame : public IFrame {
public:
	CMiniJavaMethodFrame(const CClassInfo*, const CFunctionInfo* info);
	CMiniJavaMethodFrame(const CClassInfo*, const IAccess* _thisAccess);

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
	virtual const std::string& GetFunctionName() const override;
	virtual const std::string& GetClassName() const override;

	std::shared_ptr<const IR::IExpression> ExternalCall(const std::string& functionName, std::shared_ptr<const IR::CExpressionList> args) const override;
private:
	void initStatic();

	int currOffset = 0;
	std::shared_ptr<IFrame> classFrame;
	const IAccess* thisAccess;
	std::vector< std::unique_ptr<const IAccess> > formals;
	std::vector< std::unique_ptr<const IAccess> > locals;
	std::map< const CSymbol*, const IAccess* > namesMap;
	const std::string functionName;
	const std::string className;

	static CSymbol* thisName;
	static CSymbol* returnName;
	static CSymbol* framePointerName;
	static CSymbol* stackPointerName;
	const static int wordSize;

	void addRegister(const CSymbol* regName, const CSymbol* name);
	void addMember(const CSymbol* name);
	void addLocal(const CSymbol* name);
};