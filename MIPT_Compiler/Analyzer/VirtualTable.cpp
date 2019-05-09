#include "VirtualTable.h"
#include <FunctionInfo.h>

CVirtualTable::CVirtualTable(const std::string _name, const CVirtualTable& table)
	: name(_name), 
	methods(table.methods)
{}

int CVirtualTable::GetMethodIndex(const CSymbol* name) const
{
	for (int i = 0; i < methods.size(); ++i) {
		if (methods[i]->String() == name) {
			return i;
		}
	}
	return -1;
}

void CVirtualTable::ReplaceMethod(const CFunctionInfo* method)
{
	int index = GetMethodIndex( method->String() );
	if (index < 0) {
		AddMethod(method);
	} else {
		methods[index] = method;
	}
}

std::shared_ptr<const IR::CNameExpression> CVirtualTable::GetTableName() const
{
	return std::make_shared<const IR::CNameExpression>(name);
}
