#include <FunctionInfo.h>
#include <SymbolTable.h>
#include <Type.h>
#include <UndefinedTypeException.h>

CFunctionInfo::CFunctionInfo(std::string& table, const CSymbol* _name, const CSymbol* _userType,
		TDataType _returnType, TVisabilityModifierType _modifierType)
	:name(_name), userType(_userType), returnType(_returnType), modifierType(_modifierType)
{
	if (returnType == DT_Instance) {
		dataType.reset(new CType(userType->String().c_str()));
	}
	else {
		dataType.reset(new CType(returnType));
	}
}

void CFunctionInfo::AddArgument(const CVariableInfo* argument)
{
	arguments.push_back(argument);
}

void CFunctionInfo::AddLocal(const CVariableInfo * local)
{
	locals.push_back(local);
}

void CFunctionInfo::AddArguments(std::vector<const CVariableInfo*>&& _arguments)
{
	arguments = _arguments;
}

const std::vector<const CVariableInfo*>& CFunctionInfo::GetArguments() const
{
	return arguments;
}

const std::vector<const CVariableInfo*>& CFunctionInfo::GetLocals() const
{
	return locals;
}

const CVariableInfo * CFunctionInfo::GetVariable(const CSymbol * name) const
{
	for (int i = 0; i < arguments.size(); ++i) {
		if (arguments[i]->String() == name) {
			return arguments[i];
		}
	}
	for (int i = 0; i < locals.size(); ++i) {
		if (locals[i]->String() == name) {
			return locals[i];
		}
	}
}

const CSymbol * CFunctionInfo::String() const
{
	return name;
}

std::shared_ptr<CType> CFunctionInfo::GetType() const
{
	return dataType;
}

void CFunctionInfo::SetParent(const CNamespaceBlock * _parentBlock)
{
	parentBlock = _parentBlock;
}

const CNamespaceBlock * CFunctionInfo::GetParent() const
{
	return parentBlock;
}
