#include <Synthesis/Patterns.h>
#include <limits>
//#include <Synthesis/visitors/TypingVisitor.h>
#include <Synthesis/Commands.h>
#include <IR/IRExpression.h>

namespace Synthesis {

template <typename T>
CPattern::ValidAndValue<const T*> CPattern::GetTypedNode(const IR::ITree* node) {
	//CTypingVisitor<T> visitor;
	//node->Accept(&visitor);
	//const T* pointer = visitor.GetNode();
	const T* pointer = dynamic_cast<const T*>(node);
	return ValidAndValue<const T*>(pointer != nullptr, pointer);
}

int CPattern::GetDynamicPrice(const IR::ITree* node) {
	auto iterator = dynamic->find(node);
	if (iterator == dynamic->end()) {
		return std::numeric_limits<int>::max();
	}
	else {
		return iterator->second.first;
	}
}

const Synthesis::IExpression* CPattern::GetDynamicValue(const IR::ITree* node) {
	return dynamic_cast<const IExpression*>(dynamic->find(node)->second.second.get());
}

template <typename Command>
void CPattern::ConsumeBinaryOperation(const IR::ITree* node, IR::TOperator operation) {
	auto root = GetTypedNode<IR::CBinaryExpression>(node);
	if (!root.IsValid() || root->Operation() != operation) {
		return;
	}

	const int price = GetDynamicPrice(root->LeftOperand()) + GetDynamicPrice(root->RightOperand()) + 1;
	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price,
			std::make_shared<Command>(GetDynamicValue(root->LeftOperand()),
				GetDynamicValue(root->RightOperand())));
	}
}

void CTempPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CTempExpression>(node);

	if (!root.IsValid()) {
		return;
	}

	(*dynamic)[*root] = std::make_pair(1, std::make_shared<CTempExpression>(root->Temporary().Get()));
}

void CLabelPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CLabelStatement>(node);

	if (!root.IsValid()) {
		return;
	}

	(*dynamic)[*root] = std::make_pair(1, std::make_shared<CLabelDeclarationCommand>(root->Label().GetLabel()));
}

void CAddPattern::Consume(const IR::ITree* node) {
	ConsumeBinaryOperation<CAddCommand>(node, IR::TOperator::O_Plus);
}

void CSubPattern::Consume(const IR::ITree* node) {
	ConsumeBinaryOperation<CSubCommand>(node, IR::TOperator::O_Minus);
}

void CMultPattern::Consume(const IR::ITree* node) {
	ConsumeBinaryOperation<CMultCommand>(node, IR::TOperator::O_Multiplication);
}

void CDivPattern::Consume(const IR::ITree* node) {
	ConsumeBinaryOperation<CDivCommand>(node, IR::TOperator::O_Division);
}

void CSubConstPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CBinaryExpression>(node);
	if (!root.IsValid() || root->Operation() != IR::TOperator::O_Minus) {
		return;
	}

	const IR::IExpression* left = root->LeftOperand();
	const IR::IExpression* right = root->RightOperand();

	const auto rightConst = GetTypedNode<IR::CConstExpression>(node);
	if (!rightConst.IsValid()) {
		return;
	}

	const int price = GetDynamicPrice(left) + 1;

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price, std::make_shared<CSubConstCommand>( GetDynamicValue(left),
			rightConst->Get()));
	}
}

void CAddConstLeftPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CBinaryExpression>(node);
	if (!root.IsValid() || root->Operation() != IR::TOperator::O_Plus) {
		return;
	}

	const IR::IExpression* left = root->LeftOperand();
	const IR::IExpression* right = root->RightOperand();

	const auto leftConst = GetTypedNode<IR::CConstExpression>(node);
	if (!leftConst.IsValid()) {
		return;
	}

	const int price = GetDynamicPrice(right) + 1;

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price,
			std::make_shared<CAddConstCommand>(GetDynamicValue(right), leftConst->Get()));
	}
}

void CAddConstRightPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CBinaryExpression>(node);
	if (!root.IsValid() || root->Operation() != IR::TOperator::O_Plus) {
		return;
	}

	const IR::IExpression* left = root->LeftOperand();
	const IR::IExpression* right = root->RightOperand();

	const auto rightConst = GetTypedNode<IR::CConstExpression>(node);
	if (!rightConst.IsValid()) {
		return;
	}

	const int price = GetDynamicPrice(left) + 1;

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price,
			std::make_shared<CAddConstCommand>(GetDynamicValue(left), rightConst->Get()));
	}
}

void CConstPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CConstExpression>(node);
	if (!root.IsValid()) {
		return;
	}

	const int price = 1;

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price, std::make_shared<CAddConstCommand>(new CNullExpression(), root->Get()));
	}
}

void CLoadMemoryPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CMemExpression>(node);
	if (!root.IsValid()) {
		return;
	}
	const IR::IExpression* value = root->Get();
	const int price = GetDynamicPrice(value) + 1;

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price,
			std::make_shared<CLoadCommand>(GetDynamicValue(value), 0));
	}
}

void CLoadConstMemoryPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CMemExpression>(node);
	if (!root.IsValid()) {
		return;
	}
	const IR::IExpression* value = root->Get();
	const auto constValue = GetTypedNode<IR::CConstExpression>(value);
	if (!constValue.IsValid()) {
		return;
	}
	const int price = 1;

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price, std::make_shared<CLoadCommand>(new CNullExpression(), constValue->Get()));
	}
}

void CLoadMemoryLeftOffsetPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CMemExpression>(node);
	if (!root.IsValid()) {
		return;
	}
	const IR::IExpression* child = root->Get();
	const auto expression = GetTypedNode<IR::CBinaryExpression>(child);
	if (!expression.IsValid() || expression->Operation() != IR::TOperator::O_Plus) {
		return;
	}

	const IR::IExpression* left = expression->LeftOperand();
	const IR::IExpression* right = expression->RightOperand();

	const auto leftConst = GetTypedNode<IR::CConstExpression>(node);
	if (!leftConst.IsValid()) {
		return;
	}

	const int price = GetDynamicPrice(right) + 1;

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price, std::make_shared<CLoadCommand>( GetDynamicValue(right), leftConst->Get()));
	}
}

void CLoadMemoryRightOffsetPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CMemExpression>(node);
	if (!root.IsValid()) {
		return;
	}
	const IR::IExpression* child = root->Get();
	const auto expression = GetTypedNode<IR::CBinaryExpression>(child);
	if (!expression.IsValid() || expression->Operation() != IR::TOperator::O_Plus) {
		return;
	}

	const IR::IExpression* left = expression->LeftOperand();
	const IR::IExpression* right = expression->RightOperand();

	const auto rightConst = GetTypedNode<IR::CConstExpression>(node);
	if (!rightConst.IsValid()) {
		return;
	}

	const int price = GetDynamicPrice(left) + 1;

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price, std::make_shared<CLoadCommand>(GetDynamicValue(left), rightConst->Get()));
	}
}

void CStoreMemoryPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CMoveStatement>(node);
	if (!root.IsValid()) {
		return;
	}
	const IR::IExpression* dest = root->Destination();
	const IR::IExpression* source = root->Source();

	const auto destValue = GetTypedNode<IR::CMemExpression>(dest);
	if (!destValue.IsValid()) {
		return;
	}

	const int price = GetDynamicPrice(destValue->Get()) + GetDynamicPrice(source) + 1;

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price, std::make_shared<CStoreCommand>(GetDynamicValue(dest), 0, GetDynamicValue(source)));
	}
}

void CStoreConstMemoryPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CMoveStatement>(node);
	if (!root.IsValid()) {
		return;
	}
	const IR::IExpression* dest = root->Destination();
	const IR::IExpression* source = root->Source();

	const auto destValue = GetTypedNode<IR::CMemExpression>(dest);
	if (!destValue.IsValid()) {
		return;
	}
	const IR::IExpression* destChild = destValue->Get();
	const auto constValue = GetTypedNode<IR::CConstExpression>(destChild);
	if (!constValue.IsValid()) {
		return;
	}

	const int price = GetDynamicPrice(source) + 1;

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price, std::make_shared<CStoreCommand>(new CNullExpression(),
			constValue->Get(), GetDynamicValue(source)));
	}
}

void CStoreMemoryRightOffsetPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CMoveStatement>(node);
	if (!root.IsValid()) {
		return;
	}
	const IR::IExpression* dest = root->Destination();
	const IR::IExpression* source = root->Source();

	const auto memValue = GetTypedNode<IR::CMemExpression>(dest);
	if (!memValue.IsValid()) {
		return;
	}
	const auto memExpressionValue = GetTypedNode<IR::CBinaryExpression>(memValue->Get());
	if (!memExpressionValue.IsValid() || memExpressionValue->Operation() != IR::TOperator::O_Plus) {
		return;
	}
	const IR::IExpression* left = memExpressionValue->LeftOperand();
	const IR::IExpression* right = memExpressionValue->RightOperand();

	const auto leftConst = GetTypedNode<IR::CConstExpression>(left);
	if (!leftConst.IsValid()) {
		return;
	}

	const int price = GetDynamicPrice(right) + GetDynamicPrice(source) + 1;

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price, std::make_shared<CStoreCommand>(GetDynamicValue(dest), leftConst->Get(), GetDynamicValue(source)));
	}

}

void CStoreMemoryLeftOffsetPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CMoveStatement>(node);
	if (!root.IsValid()) {
		return;
	}
	const IR::IExpression* dest = root->Destination();
	const IR::IExpression* source = root->Source();

	const auto memValue = GetTypedNode<IR::CMemExpression>(dest);
	if (!memValue.IsValid()) {
		return;
	}
	const auto memExpressionValue = GetTypedNode<IR::CBinaryExpression>(memValue->Get());
	if (!memExpressionValue.IsValid() || memExpressionValue->Operation() != IR::TOperator::O_Plus) {
		return;
	}
	const IR::IExpression* left = memExpressionValue->LeftOperand();
	const IR::IExpression* right = memExpressionValue->RightOperand();

	const auto rightConst = GetTypedNode<IR::CConstExpression>(right);
	if (!rightConst.IsValid()) {
		return;
	}

	const int price = GetDynamicPrice(left) + GetDynamicPrice(source) + 1;

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price, std::make_shared<CStoreCommand>(GetDynamicValue(dest), rightConst->Get(), GetDynamicValue(source)));
	}
}

void CStoreRegisterPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CMoveStatement>(node);
	if (!root.IsValid()) {
		return;
	}
	const IR::IExpression* dest = root->Destination();
	const IR::IExpression* source = root->Source();

	const auto destValue = GetTypedNode<IR::CTempExpression>(dest);
	if (!destValue.IsValid()) {
		return;
	}

	const int price = GetDynamicPrice(source) + 1;

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price, std::make_shared<CMoveRegisterCommand>(
			new Synthesis::CTempExpression(destValue->Temporary().Get()), GetDynamicValue(source)));
	}
}

void CCallFunctionPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CCallExpression>(node);

	if (!root.IsValid()) {
		return;
	}

	const auto function = GetTypedNode<IR::CNameExpression>(root->Function());
	const std::vector<std::shared_ptr<const IR::IExpression>>& arguments = root->Arguments()->Get();

	int price = 1;

	std::vector<const Synthesis::IExpression*> commandArguments;
	for (unsigned int i = 0; i < arguments.size(); i++) {
		price += GetDynamicPrice(arguments[i].get());
		commandArguments.push_back(GetDynamicValue(arguments[i].get()));
	}
	(*dynamic)[*root] = std::make_pair(price, std::make_shared<CCallFunctionCommand>(function->Get().GetLabel(), commandArguments));
}

void CJumpPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CJumpStatement>(node);

	if (!root.IsValid()) {
		return;
	}

	std::string targetLabel = root->Target().GetLabel();

	const int price = 1;

	(*dynamic)[*root] = std::make_pair(price, std::make_shared<CJumpCommand>(targetLabel));
}

void CConditionalJumpPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CJumpConditionalStatement>(node);

	if (!root.IsValid()) {
		return;
	}

	const IR::IExpression* leftOperand = root->Left();
	const IR::IExpression* rightOperand = root->Right();

	const int price = GetDynamicPrice(leftOperand) + GetDynamicPrice(rightOperand) + 1;

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price,
			std::make_shared<CConditionalJumpCommand>(GetDynamicValue(leftOperand),
				GetDynamicValue(rightOperand), root->Operation(), root->TrueLabel().GetLabel(),
				root->FalseLabel().GetLabel()));
	}
}

void CExpStatementPattern::Consume(const IR::ITree* node) {
	const auto root = GetTypedNode<IR::CExpStatement>(node);

	if (!root.IsValid()) {
		return;
	}

	const IR::IExpression* expression = root->Expression();

	const int price = GetDynamicPrice(expression);

	if (GetDynamicPrice(*root) > price) {
		(*dynamic)[*root] = std::make_pair(price, std::make_shared<CExpStatementCommand>(GetDynamicValue(expression)));
	}
}

}