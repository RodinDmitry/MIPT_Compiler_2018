#pragma once
#include <string>
#include <map>

class CSymbol {
public:
	CSymbol(const std::string& name);
	const std::string& String() const;

	CSymbol( const CSymbol& ) = delete;
	void operator=( const CSymbol& ) = delete;

	static CSymbol* GetSymbol(const std::string& src);

protected:
	std::string name;
	static std::map<std::string, std::unique_ptr<CSymbol> > allStrings;
};
