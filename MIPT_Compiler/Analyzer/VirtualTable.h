#pragma once

#include <vector>

class CSymbol;
class CFunctionInfo;

class CVirtualTable {
public:

	CVirtualTable() {};
	CVirtualTable(const CVirtualTable& table);

	int GetMethodIndex(const CSymbol* name) const;
	void ReplaceMethod(const CFunctionInfo* method);
	void AddMethod(const CFunctionInfo* method) { methods.push_back(method); };
	int GetSize() const { return methods.size(); };

private:
	std::vector<const CFunctionInfo*> methods;
};
