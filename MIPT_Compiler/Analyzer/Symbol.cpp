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
	auto symb = allStrings.find(src);
	if (symb != allStrings.end()) {
		return (*symb).second.get();
	}
	return new CSymbol(src);
}
