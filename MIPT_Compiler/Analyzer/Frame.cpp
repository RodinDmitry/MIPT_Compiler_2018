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

const CSymbol* CMiniJavaMethodFrame::thisName = CSymbol::GetSymbol("$this$");
const CSymbol* CMiniJavaMethodFrame::returnName = CSymbol::GetSymbol("$return$");

CMiniJavaMethodFrame::CMiniJavaMethodFrame(const CType* classType, const CType* returnType)
{
	AddFormal(thisName, classType);
	AddLocal(returnName, returnType);
}

const IAccess * CMiniJavaMethodFrame::GetThis() const
{
	return FindFormalorLocal(thisName);
}

const IAccess * CMiniJavaMethodFrame::GetReturn() const
{
	return FindFormalorLocal(returnName);
}
