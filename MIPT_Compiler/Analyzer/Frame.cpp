#include "Frame.h"

void CMiniJavaMethodFrame::AddFormal(const CSymbol* name)
{
	formals.emplace_back(new CInFrameAccess(currOffset));
	namesMap.emplace(name, formals.back().get());
	currOffset += wordSize;
}

void CMiniJavaMethodFrame::AddLocal(const CSymbol * name)
{
	locals.emplace_back(new CInFrameAccess(currOffset));
	namesMap.emplace(name, locals.back().get());
	currOffset += wordSize;
}

int CMiniJavaMethodFrame::FormalsCount() const
{
	return formals.size();
}

const IAccess * CMiniJavaMethodFrame::GetFormal(int index) const
{
	return formals[index].get();
}

const IAccess * CMiniJavaMethodFrame::FindFormalorLocal(const CSymbol * name) const
{
	auto var = namesMap.find(name);
	if (var != namesMap.end()) {
		return (*var).second;
	}
	return nullptr;
}

std::shared_ptr<const IR::IExpression> CMiniJavaMethodFrame::GetWordSize() const
{
	return std::make_shared<const IR::CConstExpression>(wordSize);
}

const std::shared_ptr<const IR::IExpression> CMiniJavaMethodFrame::GetFramePtr() const
{
	return GetFP()->GetExp(nullptr);
}

CSymbol* CMiniJavaMethodFrame::thisName = nullptr;
CSymbol* CMiniJavaMethodFrame::returnName = nullptr;
CSymbol* CMiniJavaMethodFrame::framePointerName = nullptr;
CSymbol* CMiniJavaMethodFrame::stackPointerName = nullptr;
const static int wordSize = 4;

CMiniJavaMethodFrame::CMiniJavaMethodFrame(const CType* classType, const CType* returnType)
{
	initStatic();
	AddRegister(thisName, thisName);
	AddRegister(framePointerName, framePointerName);
	AddRegister(stackPointerName, stackPointerName);
	AddLocal(returnName);
}

CMiniJavaMethodFrame::CMiniJavaMethodFrame(const CClassInfo* classInfo, const CFunctionInfo* info)
{
	initStatic();
	AddRegister(thisName, thisName);
	AddRegister(framePointerName, framePointerName);
	AddRegister(stackPointerName, stackPointerName);
	AddLocal(returnName);

	for (const CVariableInfo* var : info->GetArguments()) {
		AddFormal(var->String());
	}
	for (const CVariableInfo* var : info->GetLocals()) {
		AddLocal(var->String());
	}
}

const IAccess * CMiniJavaMethodFrame::GetThis() const
{
	return FindFormalorLocal(thisName);
}

const IAccess * CMiniJavaMethodFrame::GetReturn() const
{
	return FindFormalorLocal(returnName);
}

const IAccess * CMiniJavaMethodFrame::GetFP() const
{
	return FindFormalorLocal(framePointerName);
}

const IAccess * CMiniJavaMethodFrame::GetSP() const
{
	return FindFormalorLocal(stackPointerName);
}

void CMiniJavaMethodFrame::initStatic()
{
	if (stackPointerName == nullptr) {
		thisName = CSymbol::GetSymbol("$this$");
		returnName = CSymbol::GetSymbol("$return$");
		framePointerName = CSymbol::GetSymbol("$fp$");
		stackPointerName = CSymbol::GetSymbol("$sp$");
	}
}

void CMiniJavaMethodFrame::AddRegister(const CSymbol * regName, const CSymbol * name)
{
	locals.emplace_back(new CInRegAccess(std::make_shared< const IR::CTemp >(regName->String())));
	namesMap.emplace(name, locals.back().get());
}

std::shared_ptr<const IR::IExpression> CMiniJavaMethodFrame::ExternalCall(const std::string& functionName, std::shared_ptr<const IR::CExpressionList> args) const {
	return std::make_shared<const IR::CCallExpression>(std::make_shared<const IR::CNameExpression>(IR::CLabel(functionName)), args);
}