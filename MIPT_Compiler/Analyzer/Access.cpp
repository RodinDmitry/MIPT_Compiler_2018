#include "Access.h"

CInFrameAccess::CInFrameAccess(int _offset) : offset(_offset) {}

int CInFrameAccess::GetOffset() const
{
	return offset;
}

CInRegAccess::CInRegAccess(int _reg) : reg(_reg) {}

int CInRegAccess::GetReg() const
{
	return reg;
}
