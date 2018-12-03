#include <TypeGetter.h>
#include <SymbolTable.h>

std::shared_ptr<CType> CTypeGetter::GetType(IExpression * node, std::string _symbolTable)
{
	symbolTable = _symbolTable;
	waitingNodes.push_back(node);
	while (waitingNodes.size() > 0) {
		ITree* current = waitingNodes.front();
		waitingNodes.pop_front();
		current->Accept(this);
	}
	std::shared_ptr<CType> result(checkType());
	return result;
}

void CTypeGetter::visit(CBinaryExpression* node)
{
	waitingNodes.push_front(node->right.get());
	waitingNodes.push_front(node->left.get());
}

void CTypeGetter::visit(CArrayExpression* )
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Integer));
	resultingTypes.push_back(type);
}

void CTypeGetter::visit(CCallExpression* node)
{
	const CFunctionInfo* info = CSymbolTable::FindMethod(symbolTable, CSymbol::GetSymbol(node->function->name));
	if (info != nullptr) {
		resultingTypes.push_back(info->GetType());
	}
}

void CTypeGetter::visit(CValueExpression* node)
{
	waitingNodes.push_front(node->value.get());
}

void CTypeGetter::visit(CNewArrayExpression*)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_IntegerArray));
	resultingTypes.push_back(type);
}

void CTypeGetter::visit(CNewExpression* node)
{
	std::shared_ptr<CType> type(new CType(node->id->name.c_str()));
	resultingTypes.push_back(type);
}

void CTypeGetter::visit(CIdExpression* node)
{
	const CVariableInfo* info = CSymbolTable::FindMember(symbolTable, CSymbol::GetSymbol(node->id->name));
	if (info != nullptr) {
		resultingTypes.push_back(info->GetType());
	}
}

void CTypeGetter::visit(CThisExpression* node)
{
	const CClassInfo* info = CSymbolTable::GetThis(symbolTable);
	std::shared_ptr<CType> type(new CType(info->String()->String().c_str()));
}

void CTypeGetter::visit(CNotExpression* node)
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Boolean));
	resultingTypes.push_back(type);
	waitingNodes.push_front(node->expression.get());
}

void CTypeGetter::visit(CBracketsExpression* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CTypeGetter::visit(CReturnExpression* node)
{
	waitingNodes.push_front(node->expression.get());
}

void CTypeGetter::visit(CValue* node)
{
	switch (node->type)
	{
	case CValue::T_Boolean: {
		std::shared_ptr<CType> type(new CType(TDataType::DT_Boolean));
		resultingTypes.push_back(type);
		break;
	}
	case CValue::T_Integer: {
		std::shared_ptr<CType> type(new CType(TDataType::DT_Integer));
		resultingTypes.push_back(type);
		break;
	}
	default:
		assert(false);
	}
}

std::shared_ptr<CType> CTypeGetter::checkType()
{
	std::vector<int> counts;

	if (resultingTypes.size() == 0) {
		return nullptr;
	}

	counts.resize(DT_Total);
	for (int i = 0; i < resultingTypes.size(); i++) {
		counts[resultingTypes[i]->type]++;
	}
	int different = 0;

	for (int i = 0; i < counts.size(); i++) {
		if (counts[i] > 0) {
			different++;
		}
	}
	if (counts[DT_Instance] == 0) {
		if (different == 1) {
			return resultingTypes[0];
		}

		if (counts[DT_Integer] > 0 && counts[DT_Boolean] > 0 && different == 2) {
			return std::shared_ptr<CType>(new CType(DT_Integer));
		}
	}
	if (different == 1) {
		std::string target = resultingTypes[0]->instance;
		bool areAllEqual = true; 
		for (int i = 0; i < resultingTypes.size(); i++) {
			if (resultingTypes[i]->instance != target) {
				areAllEqual = false;
			}
		}
		if (areAllEqual) {
			return resultingTypes[0];
		}
	}

	return nullptr;

}
