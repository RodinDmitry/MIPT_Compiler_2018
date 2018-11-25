#include "ClassInfo.h"

CClassInfo * CClassInfo::GetSymbol(const std::string & src, CSymbol * extends)
{
	CClassInfo* symb = static_cast<CClassInfo*>(GetSymbolOrNull(src));
	if (symb == nullptr) {
		symb = new CClassInfo(src, extends);
	}
	return symb;
}
