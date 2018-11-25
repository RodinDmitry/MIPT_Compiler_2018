#include "Symbol.h"

CSymbol::CSymbol(const std::string & _name) : name(_name)
{
	auto symb = allStrings.find(name);
	if (symb != allStrings.end()) {
		allStrings.emplace(name, this);
	}
}

const std::string & CSymbol::String() const
{
	return name;
}

CSymbol * CSymbol::GetSymbol(const std::string & src)
{
	CSymbol* symb = GetSymbolOrNull(src);
	if (symb == nullptr) {
		symb = new CSymbol(src);
	}
	return symb;
}

CSymbol * CSymbol::GetSymbolOrNull(const std::string & src)
{
	auto symb = allStrings.find(src);
	if (symb != allStrings.end()) {
		return (*symb).second.get();
	}
	return nullptr;
}
