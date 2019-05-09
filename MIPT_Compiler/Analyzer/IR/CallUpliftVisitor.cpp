#include <IR/CallUpliftVisitor.h>

namespace IR {

std::shared_ptr<const IStatement> CCallUpliftVisitor::getStatementTree()
{
	return lastStatement;
}

std::shared_ptr<const IExpression> CCallUpliftVisitor::getExpressionTree()
{
	return lastExpression;
}

void CCallUpliftVisitor::visit(const ITree* node)
{
	assert(false);
}

void CCallUpliftVisitor::visit(const IExpression* node)
{
	assert(false);
}

void CCallUpliftVisitor::visit(const CExpressionList* node)
{
	CExpressionList* newList = new CExpressionList();

	const std::vector<std::shared_ptr<const IExpression>>& expressions = node->Get();
	for (int i = 0; i < expressions.size(); i++) {
		expressions[i]->Accept(this);
		newList->Add(lastExpression);
	}

	updateLastExpressionList(newList);
}

void CCallUpliftVisitor::visit(const CConstExpression* node)
{
	updateLastExpression(new CConstExpression(node->Get()));
}

void CCallUpliftVisitor::visit(const CNameExpression* node)
{
	updateLastExpression(new CNameExpression(node->Get()));
}

void CCallUpliftVisitor::visit(const CTempExpression* node)
{
	updateLastExpression(new CTempExpression(node->Temporary()));
}

void CCallUpliftVisitor::visit(const CBinaryExpression* node)
{
	node->LeftOperand()->Accept(this);
	std::shared_ptr<const IExpression> left = lastExpression;
	node->RightOperand()->Accept(this);
	std::shared_ptr<const IExpression> right = lastExpression;
	std::shared_ptr<const IExpression> resultExpression = std::shared_ptr<const IExpression>(new CBinaryExpression(node->Operation(), left, right));

	updateLastExpression(resultExpression);
}

void CCallUpliftVisitor::visit(const CMemExpression* node)
{
	node->Get()->Accept(this);
	std::shared_ptr<const IExpression> address = lastExpression;
	updateLastExpression(new CMemExpression(address));
}

void CCallUpliftVisitor::visit(const CCallExpression* node)
{
	node->Function()->Accept(this);
	std::shared_ptr<const IExpression> function = lastExpression;
	node->Arguments()->Accept(this);
	std::shared_ptr<const CExpressionList> arguments = lastExpressionList;

	CTemp temp;

	std::shared_ptr<const IExpression> resultExpression = std::shared_ptr<const IExpression>(new CEseqExpression(new CMoveStatement(
		new CTempExpression(temp), new CCallExpression(function, arguments)), new CTempExpression(temp)));
	updateLastExpression(resultExpression);
}

void CCallUpliftVisitor::visit(const CEseqExpression* node)
{
	node->Statement()->Accept(this);
	std::shared_ptr<const IStatement> statement = lastStatement;
	node->Expression()->Accept(this);
	std::shared_ptr<const IExpression> expression = lastExpression;
	updateLastExpression(new CEseqExpression(statement, expression));
}

void CCallUpliftVisitor::visit(const IStatement* node)
{
	assert(false);
}

void CCallUpliftVisitor::visit(const CMoveStatement* node)
{
	node->Destination()->Accept(this);
	std::shared_ptr<const IExpression> destination = lastExpression;
	node->Source()->Accept(this);
	std::shared_ptr<const IExpression> source = lastExpression;

	updateLastStatement(new CMoveStatement(destination, source));
}

void CCallUpliftVisitor::visit(const CExpStatement* node)
{
	node->Expression()->Accept(this);
	std::shared_ptr<const IExpression> expression = lastExpression;
	updateLastStatement(new CExpStatement(expression));
}

void CCallUpliftVisitor::visit(const CJumpStatement* node)
{
	updateLastStatement(new CJumpStatement(node->Target()));
}

void CCallUpliftVisitor::visit(const CJumpConditionalStatement* node)
{
	node->Left()->Accept(this);
	std::shared_ptr<const IExpression> left = lastExpression;
	node->Right()->Accept(this);
	std::shared_ptr<const IExpression> right = lastExpression;
	updateLastStatement(new CJumpConditionalStatement(node->Operation(), left, right, node->TrueLabel(), node->FalseLabel()));
}

void CCallUpliftVisitor::visit(const CSeqStatement* node)
{
	node->LeftStatement()->Accept(this);
	std::shared_ptr<const IStatement> left = lastStatement;
	node->RightStatement()->Accept(this);
	std::shared_ptr<const IStatement> right = lastStatement;
	updateLastStatement(new CSeqStatement(left, right));
}

void CCallUpliftVisitor::visit(const CLabelStatement* node)
{
	updateLastStatement(new CLabelStatement(node->Label()));
}

void CCallUpliftVisitor::visit(const CStatementList * node)
{
	assert(false);
}

void CCallUpliftVisitor::updateLastExpression(const IExpression* expression)
{
	updateLastExpression(std::shared_ptr<const IExpression>(expression));
}

void CCallUpliftVisitor::updateLastExpression(std::shared_ptr<const IExpression> expression)
{
	lastExpression = expression;
}

void CCallUpliftVisitor::updateLastExpressionList(const CExpressionList* list)
{
	updateLastExpressionList(std::shared_ptr<const CExpressionList>(list));
}

void CCallUpliftVisitor::updateLastExpressionList(std::shared_ptr<const CExpressionList> list)
{
	lastExpressionList = list;
}

void CCallUpliftVisitor::updateLastStatement(const IStatement* statement)
{
	updateLastStatement(std::shared_ptr<const IStatement>(statement));
}

void CCallUpliftVisitor::updateLastStatement(std::shared_ptr<const IStatement> statement)
{
	lastStatement = statement;
}

} // namespace IR