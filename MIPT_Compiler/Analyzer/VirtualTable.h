#pragma once

#include <vector>
#include <IR/IRExpression.h>

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
	std::shared_ptr<const IR::CNameExpression> GetTableName() const;


private:
	std::vector<const CFunctionInfo*> methods;
};
