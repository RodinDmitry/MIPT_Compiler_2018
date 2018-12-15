#include "Frame.h"

void CMiniJavaFrame::AddFormal(const CSymbol* name, const CType* type)
{
	formals.emplace_back(new CInFrameAccess(currOffset));
	namesMap.emplace(name, formals.back().get());
	currOffset += GetOffset(type->type);
}

void CMiniJavaFrame::AddLocal(const CSymbol * name, const CType * type)
{
	locals.emplace_back(new CInFrameAccess(currOffset));
	namesMap.emplace(name, locals.back().get());
	currOffset += GetOffset(type->type);
}

int CMiniJavaFrame::FormalsCount() const
{
	if (!isFinalized) {
		return -1;
	}
	return formals.size();
}

const IAccess * CMiniJavaFrame::GetFormal(int index) const
{
	return formals[index].get();
}

const IAccess * CMiniJavaFrame::FindFormalorLocal(const CSymbol * name) const
{
	auto var = namesMap.find(name);
	if (var != namesMap.end()) {
		return (*var).second;
	}
	return nullptr;
}

void CMiniJavaFrame::Finalize()
{
	isFinalized = true;
}

int CMiniJavaFrame::GetTotalSize() const
{
	if (!isFinalized) {
		return -1;
	}
	return currOffset;
}

int CMiniJavaFrame::GetOffset(TDataType type)
{
	switch (type) {
		case TDataType::DT_Boolean: return 1;
		default: return 4;
	}
}

CSymbol* CMiniJavaMethodFrame::thisName = nullptr;
CSymbol* CMiniJavaMethodFrame::returnName = nullptr;
CSymbol* CMiniJavaMethodFrame::framePointerName = nullptr;
CSymbol* CMiniJavaMethodFrame::stackPointerName = nullptr;

CMiniJavaMethodFrame::CMiniJavaMethodFrame(const CType* classType, const CType* returnType)
{
	initStatic();
	AddFormal(thisName, classType);
	std::unique_ptr<CType> ptr(new CType(DT_Integer));
	AddLocal(framePointerName, ptr.get());
	AddLocal(stackPointerName, ptr.get());
	AddLocal(returnName, returnType);
}

CMiniJavaMethodFrame::CMiniJavaMethodFrame(const CClassInfo* classInfo, const CFunctionInfo* info)
{
	initStatic();
	AddFormal(thisName, classInfo->GetType().get());
	std::unique_ptr<CType> ptr(new CType(DT_Integer));
	AddLocal(framePointerName, ptr.get());
	AddLocal(stackPointerName, ptr.get());
	AddLocal(returnName, info->GetType().get());

	for (const CVariableInfo* var : info->GetArguments()) {
		AddFormal(var->String(), var->GetType().get());
	}
	for (const CVariableInfo* var : info->GetLocals()) {
		AddLocal(var->String(), var->GetType().get());
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
