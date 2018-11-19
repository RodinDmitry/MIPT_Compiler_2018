#pragma once
#include <VariableInfo.h>
#include <vector>

class CFunctionInfo : public CSymbol {
public:
	CFunctionInfo(TDataType _returnType);
	void AddArgument(CVariableInfo* argument);
	void AddArguments(std::vector<std::unique_ptr<CVariableInfo*> >&& _arguments);

	static CFunctionInfo* GetSymbol(const std::string& src);
private:
	TDataType returnType;
	std::vector<std::unique_ptr<CVariableInfo*> > arguments;
};
