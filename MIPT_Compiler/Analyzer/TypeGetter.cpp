#include <TypeGetter.h>
#include <SymbolTable.h>
#include <ErrorTable.h>

CTypeGetter::CTypeGetter() : className(""), functionName(""), symbolTable(""), enterCount(0), leaveCount(0)
{
}

std::shared_ptr<CType> CTypeGetter::GetType(IExpression* node, const std::string& _symbolTable,
	const std::string& _className, const std::string& _functionName, int _entered, int _left)
{
	className = _className;
	functionName = _functionName;
	symbolTable = _symbolTable;
	enterCount = _entered;
	leaveCount = _left;
	waitingNodes.clear();
	resultingTypes.clear();
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
	CTypeGetter getter;
	switch (node->operation)
	{
	case node->TOperator::O_And:
	case node->TOperator::O_Or: {
		std::shared_ptr<CType> leftType = getter.GetType(node->left.get(), symbolTable, className,
			functionName, enterCount, leaveCount);
		std::shared_ptr<CType> rightType = getter.GetType(node->right.get(), symbolTable, className,
			functionName, enterCount, leaveCount);
		if (leftType == nullptr || rightType == nullptr) {
			CErrorTable::AddError(CErrorTable::InvalidOperation, node->GetLine());
			return;
		}

		if (leftType->type != DT_Boolean || rightType->type != DT_Boolean) {
			CErrorTable::AddError(CErrorTable::InvalidOperation, node->GetLine());
		}
		std::shared_ptr<CType> type(new CType(TDataType::DT_Boolean));
		resultingTypes.push_back(type);
		break;
	}
	case node->TOperator::O_Less:
	case node->TOperator::O_More: {
		std::shared_ptr<CType> leftType = getter.GetType(node->left.get(), symbolTable, className,
			functionName, enterCount, leaveCount);
		std::shared_ptr<CType> rightType = getter.GetType(node->right.get(), symbolTable, className,
			functionName, enterCount, leaveCount);
		if (leftType == nullptr || rightType == nullptr) {
			CErrorTable::AddError(CErrorTable::InvalidOperation, node->GetLine());
			return;
		}

		if (leftType->type != DT_Integer || rightType->type != DT_Integer) {
			CErrorTable::AddError(CErrorTable::InvalidOperation, node->GetLine());
			return;
		}
		std::shared_ptr<CType> type(new CType(TDataType::DT_Boolean));
		resultingTypes.push_back(type);
		break;
	}
	case node->TOperator::O_Plus:
	case node->TOperator::O_Minus:
	case node->TOperator::O_Multiplication:
	case node->TOperator::O_Division:
	case node->TOperator::O_IntegerDivision: {
		std::shared_ptr<CType> leftType = getter.GetType(node->left.get(), symbolTable, className,
			functionName, enterCount, leaveCount);
		std::shared_ptr<CType> rightType = getter.GetType(node->right.get(), symbolTable, className,
			functionName, enterCount, leaveCount);
		if (leftType == nullptr || rightType == nullptr) {
			CErrorTable::AddError(CErrorTable::InvalidOperation, node->GetLine());
			return;
		}

		if (leftType->type != DT_Integer || rightType->type != DT_Integer) {
			CErrorTable::AddError(CErrorTable::InvalidOperation, node->GetLine());
		}
		std::shared_ptr<CType> type(new CType(TDataType::DT_Integer));
		resultingTypes.push_back(type);
		break;
	}
	default: {
		assert(false);
	}
	}
}

void CTypeGetter::visit(CArrayExpression* )
{
	std::shared_ptr<CType> type(new CType(TDataType::DT_Integer));
	resultingTypes.push_back(type);
}

void CTypeGetter::visit(CCallExpression* node)
{
	CTypeGetter getter;
	std::shared_ptr<CType> callerType = getter.GetType(node->caller.get(), symbolTable, className, functionName,
		enterCount, leaveCount);
	if (!callerType) {
		callerType = getter.GetType(node->caller.get(), symbolTable, className, functionName,
			enterCount, leaveCount);
	}
	if (callerType->type != TDataType::DT_Instance) {
		return;
	}
	const CClassInfo* classInfo = CSymbolTable::FindClass(symbolTable, CSymbol::GetSymbol(callerType->instance));
	if (classInfo == nullptr) {
		return;
	}
	const CFunctionInfo* method = classInfo->FindMethod(CSymbol::GetSymbol(node->function->name));
	if (method != nullptr) {
		std::shared_ptr<CType> type(new CType(*(method->GetType())));
		resultingTypes.push_back(type);
	}	
}

void CTypeGetter::visit(CCallLengthExpression* node)
{
	std::shared_ptr<CType> type(new CType(DT_Integer));
	resultingTypes.push_back(type);
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
	const CVariableInfo* info = CSymbolTable::FindLocalVariable(symbolTable, node->id->name, className,
		functionName, enterCount, leaveCount);
	if (info != nullptr) {
		resultingTypes.push_back(info->GetType());
	}
	else {
		auto classInfo = CSymbolTable::FindClass(symbolTable, CSymbol::GetSymbol(node->id->name));
		if (classInfo != nullptr) {
			std::shared_ptr<CType> type(new CType(classInfo->String()->String().c_str()));
			resultingTypes.push_back(type);
		}
	}
}

void CTypeGetter::visit(CThisExpression* node)
{
	std::shared_ptr<CType> type(new CType(className.c_str()));
	resultingTypes.push_back(type);
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

void CTypeGetter::visit(CReturnStatement* node)
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
