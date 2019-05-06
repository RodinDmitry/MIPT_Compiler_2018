#include <IR/LinearizationVisitor.h>

namespace IR {

std::shared_ptr<const IStatement> CLinearizationVisitor::getResult()
{
	return lastStatement;
}

	void CLinearizationVisitor::visit(const ITree* node)
{
	assert(false);
}

void CLinearizationVisitor::visit(const IExpression* node)
{
	assert(false);
}

void CLinearizationVisitor::visit(const CExpressionList* node)
{
	CExpressionList* newList = new CExpressionList();

	const std::vector<std::shared_ptr<const IExpression>>& expressions = node->Get();
	for (int i = 0; i < expressions.size(); i++) {
		expressions[i]->Accept(this);
		newList->Add(lastExpression);
	}
}

void CLinearizationVisitor::visit(const CConstExpression* node)
{
	distanceToSeqStack.back()++;
	updateLastExpression(new CConstExpression(node->Get()));
	distanceToSeqStack.back()--;
}

void CLinearizationVisitor::visit(const CNameExpression* node)
{
	distanceToSeqStack.back()++;
	updateLastExpression(new CNameExpression(node->Get()));
	distanceToSeqStack.back()--;
}
void CLinearizationVisitor::visit(const CTempExpression* node)
{
	distanceToSeqStack.back()++;
	updateLastExpression(new CTempExpression(node->Temporary()));
	distanceToSeqStack.back()--;
}

void CLinearizationVisitor::visit(const CBinaryExpression* node)
{
	distanceToSeqStack.back()++;
	node->LeftOperand()->Accept(this);
	std::shared_ptr<const IExpression> left = lastExpression;
	node->RightOperand()->Accept(this);
	std::shared_ptr<const IExpression> right = lastExpression;

	updateLastExpression(new CBinaryExpression(node->Operation(), left, right));
	distanceToSeqStack.back()--;
}

void CLinearizationVisitor::visit(const CMemExpression* node)
{
	distanceToSeqStack.back()++;
	node->Get()->Accept(this);
	std::shared_ptr<const IExpression> address = lastExpression;
	updateLastExpression(new CMemExpression(address));
	distanceToSeqStack.back()--;
}
void CLinearizationVisitor::visit(const CCallExpression * node)
{
	distanceToSeqStack.back()++;
	node->Function()->Accept(this);
	std::shared_ptr<const IExpression> function = lastExpression;
	node->Arguments()->Accept(this);
	std::shared_ptr<const CExpressionList> arguments = lastExpressionList;

	updateLastExpression(new CCallExpression(function, arguments));
	distanceToSeqStack.back()--;
}

void CLinearizationVisitor::visit(const CEseqExpression* node)
{
	assert(false);
}

void CLinearizationVisitor::visit(const IStatement* node)
{
	assert(false);
}

void CLinearizationVisitor::visit(const CMoveStatement* node)
{
	distanceToSeqStack.back()++;
	node->Destination()->Accept(this);
	std::shared_ptr<const IExpression> destination = lastExpression;
	node->Source()->Accept(this);
	std::shared_ptr<const IExpression> source = lastExpression;

	std::shared_ptr<const IStatement> result(new CMoveStatement(destination, source));
	saveResult(result);
	distanceToSeqStack.back()--;
}

void CLinearizationVisitor::visit(const CExpStatement* node)
{
	distanceToSeqStack.back()++;

	node->Expression()->Accept(this);
	std::shared_ptr<const IExpression> expression = lastExpression;

	std::shared_ptr<IStatement> result(new CExpStatement(expression));
	saveResult(result);

	distanceToSeqStack.back()++;
}

void CLinearizationVisitor::visit(const CJumpStatement* node)
{
	distanceToSeqStack.back()++;
	std::shared_ptr<const IStatement> result(new CJumpStatement(node->Target()));
	saveResult(result);
	distanceToSeqStack.back()--;
}

void CLinearizationVisitor::visit(const CJumpConditionalStatement* node)
{
	distanceToSeqStack.back()++;
	node->Left()->Accept(this);
	std::shared_ptr<const IExpression> left = lastExpression;
	node->Right()->Accept(this);
	std::shared_ptr<const IExpression> right = lastExpression;
	std::shared_ptr<const IStatement> result(new CJumpConditionalStatement(node->Operation(), left, right, node->TrueLabel(), node->FalseLabel()));
	saveResult(result);
	distanceToSeqStack.back()--;
}

void CLinearizationVisitor::visit(const CSeqStatement* node)
{
	distanceToSeqStack.back()++;

	if (distanceToSeqStack.back() > 1) {
		statementStack.push_back(std::vector<std::shared_ptr<const IStatement>>());
	}

	distanceToSeqStack.push_back(0);
	node->LeftStatement()->Accept(this);
	node->RightStatement()->Accept(this);

	distanceToSeqStack.pop_back();
	if (distanceToSeqStack.back() > 1) {
		CStatementList* statementList = new CStatementList();
		for (int i = 0; i < statementStack.back().size(); i++) {
			statementList->Add(statementStack.back()[i]);
		}
		updateLastStatement(statementList);
		statementStack.pop_back();
	}

	distanceToSeqStack.back()++;

}

void CLinearizationVisitor::visit(const CLabelStatement* node)
{
	distanceToSeqStack.back()++;
	std::shared_ptr<const IStatement> result(new CLabelStatement(node->Label()));
	saveResult(result);
	distanceToSeqStack.back()--;
}

void CLinearizationVisitor::visit(const CStatementList* node)
{
	assert(false);
}

void CLinearizationVisitor::updateLastExpression(const IExpression* expression)
{
	updateLastExpression(std::shared_ptr<const IExpression>(expression));
}

void CLinearizationVisitor::updateLastExpression(std::shared_ptr<const IExpression> expression)
{
	lastExpression = expression;
}

void CLinearizationVisitor::updateLastExpressionList(const CExpressionList* list)
{
	updateLastExpressionList(std::shared_ptr<const CExpressionList>(list));
}

void CLinearizationVisitor::updateLastExpressionList(std::shared_ptr<const CExpressionList> list)
{
	lastExpressionList = list;
}

void CLinearizationVisitor::updateLastStatement(const IStatement* statement)
{
	updateLastStatement(std::shared_ptr<const IStatement>(statement));
}

void CLinearizationVisitor::updateLastStatement(std::shared_ptr<const IStatement> statement)
{
	lastStatement = statement;
}

void CLinearizationVisitor::saveResult(std::shared_ptr<const IStatement> result)
{
	if (distanceToSeqStack.back() == 1) {
		statementStack.back().push_back(result);
	} else {
		updateLastStatement(result);
	}
}
} // namespace IR