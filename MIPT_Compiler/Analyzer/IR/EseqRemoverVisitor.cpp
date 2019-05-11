#include <IR/EseqRemoverVisitor.h>

namespace IR {

std::shared_ptr<const IStatement> CEseqRemoverVisitor::getStatementTree()
{
	return lastStatement;
}

std::shared_ptr<const IExpression> CEseqRemoverVisitor::getExpressionTree()
{
	return lastExpression;
}

void CEseqRemoverVisitor::visit(const ITree* node)
{
	assert(false);
}

void CEseqRemoverVisitor::visit(const IExpression* node)
{
	assert(false);
}

void CEseqRemoverVisitor::visit(const CExpressionList* node)
{
	std::shared_ptr<CExpressionList> newList = std::make_shared<CExpressionList>();
	const std::vector<std::shared_ptr<const IExpression>>& expressions = node->Get();
	for (int i = 0; i < expressions.size(); i++) {
		expressions[i]->Accept(this);
		newList->Add(lastExpression);
	}

	updateLastExpressionList(newList);
}

void CEseqRemoverVisitor::visit(const CConstExpression* node)
{
	updateLastExpression(new CConstExpression(node->Get()));
}
void CEseqRemoverVisitor::visit(const CNameExpression* node)
{
	updateLastExpression(new CNameExpression(node->Get()));
}
void CEseqRemoverVisitor::visit(const CTempExpression* node)
{
	updateLastExpression(new CTempExpression(node->Temporary()));
}
void CEseqRemoverVisitor::visit(const CBinaryExpression* node)
{
	node->LeftOperand()->Accept(this);
	std::shared_ptr<const IExpression> leftCanon = lastExpression;
	node->RightOperand()->Accept(this);
	std::shared_ptr<const IExpression> rightCanon = lastExpression;
	const CEseqExpression* leftEseq = dynamic_cast<const CEseqExpression*>(leftCanon.get());
	const CEseqExpression* rightEseq = dynamic_cast<const CEseqExpression*>(rightCanon.get());

	std::shared_ptr<const IExpression> resultExpression;

	if (leftEseq) {
		resultExpression = std::make_shared<const CEseqExpression>(leftEseq->Statement(),
			std::make_shared<const CBinaryExpression>(node->Operation(), leftEseq->Expression(), rightCanon));
		if (rightEseq) {
			resultExpression = this->processExpression(resultExpression);
		}
	} else if (rightEseq) {
		if (areCommuting(rightEseq->Statement().get(), leftCanon.get())) {
			resultExpression = std::make_shared<const CEseqExpression>(rightEseq->Statement(),
				std::make_shared<const CBinaryExpression>(node->Operation(), leftCanon, rightEseq->Expression()));
		} else {
			CTemp temp;
			std::shared_ptr<const IStatement> leftSubtree = std::make_shared<const CMoveStatement>(std::make_shared<const CTempExpression>(temp), leftCanon);
			std::shared_ptr<const IExpression> rightSubtree = std::make_shared<const CEseqExpression>(rightEseq->Statement(), 
				std::make_shared<const CBinaryExpression>(node->Operation(), std::make_shared<const CTempExpression>(temp), rightEseq->Expression()));
			resultExpression = processExpression(std::make_shared<const CEseqExpression>(leftSubtree, rightSubtree));
		}
	} else {
		resultExpression = std::make_shared<const CBinaryExpression>(node->Operation(), leftCanon, rightCanon);
	}

	updateLastExpression(resultExpression);
}
void CEseqRemoverVisitor::visit(const CMemExpression* node)
{
	node->Get()->Accept(this);
	std::shared_ptr<const IExpression> canon = getExpressionTree();
	const CEseqExpression* addressEseq = dynamic_cast<const CEseqExpression*>(canon.get());
	std::shared_ptr<const IExpression> resultExpression;

	if (addressEseq) {
		resultExpression = std::make_shared<const CEseqExpression>(addressEseq->Statement(), std::make_shared<const CMemExpression>(addressEseq->Expression()));
	}
	else {
		resultExpression = std::make_shared<const CMemExpression>(canon);
	}

	updateLastExpression(resultExpression);
}

void CEseqRemoverVisitor::visit(const CCallExpression* node)
{

	node->Function()->Accept(this);
	std::shared_ptr<const IExpression> canonFunction = lastExpression;
	node->Arguments()->Accept(this);
	std::shared_ptr<const CExpressionList> canonArgumentsList = lastExpressionList;
	std::vector<std::shared_ptr<const IStatement>> newStatements;
	std::shared_ptr<CExpressionList> tempExpressionList = std::make_shared<CExpressionList>();

	const std::vector<std::shared_ptr<const IExpression>>& canonArguments = canonArgumentsList->Get();
	

	for (int i = 0; i < canonArguments.size(); i++) {
		const CEseqExpression* argumentEseq = dynamic_cast<const CEseqExpression*>(canonArguments[i].get());
		if (argumentEseq) {
			newStatements.push_back(argumentEseq->Statement());
		}

		CTemp temp;
		tempExpressionList->Add(new CTempExpression(temp));
		std::shared_ptr<const IExpression> moveSourceExpression;

		if (argumentEseq) {
			moveSourceExpression = argumentEseq->Expression();
		} else {
			moveSourceExpression = canonArguments[i];
		}
		std::shared_ptr<const IStatement> moveStatement = std::make_shared<const CMoveStatement>(std::make_shared<const CTempExpression>(temp), moveSourceExpression);
		newStatements.push_back(moveStatement);

	}

	std::shared_ptr<const IExpression> resultExpression;
	if (!newStatements.empty()) {
		std::shared_ptr<const IStatement> suffix = newStatements.back();
		newStatements.pop_back();
		for (int i = 0; i < newStatements.size(); i++) {
			suffix = std::make_shared<const CSeqStatement>(newStatements[i], suffix);
		}

		resultExpression = std::make_shared<const CEseqExpression>(suffix,
			std::make_shared<const CCallExpression>(canonFunction, tempExpressionList));
	} else {
		resultExpression = std::shared_ptr<const IExpression>(new CCallExpression(canonFunction, canonArgumentsList));
	}
	
	updateLastExpression(resultExpression);
}

void CEseqRemoverVisitor::visit(const CEseqExpression* node)
{
	node->Statement()->Accept(this);
	std::shared_ptr<const IStatement> canonStatement = lastStatement;
	node->Expression()->Accept(this);
	std::shared_ptr<const IExpression> canonExpression = lastExpression;

	const CEseqExpression* expressionEseq = dynamic_cast<const CEseqExpression*>(canonExpression.get());

	std::shared_ptr<const IExpression> resultExpression;

	if (expressionEseq) {
		resultExpression = std::make_shared<const CEseqExpression>(std::make_shared<const CSeqStatement>(canonStatement, expressionEseq->Statement()), expressionEseq->Expression());
	} else {
		resultExpression = std::make_shared<const CEseqExpression>(canonStatement, canonExpression);
	}

	updateLastExpression(resultExpression);
}

void CEseqRemoverVisitor::visit(const IStatement* node)
{
	assert(false);
}

void CEseqRemoverVisitor::visit(const CMoveStatement* node)
{
	node->Destination()->Accept(this);
	std::shared_ptr<const IExpression> canonDest = lastExpression;
	node->Source()->Accept(this);
	std::shared_ptr<const IExpression> canonSource = lastExpression;

	const CEseqExpression* destEseq = dynamic_cast<const CEseqExpression*>(canonDest.get());
	const CEseqExpression* sourceEseq = dynamic_cast<const CEseqExpression*>(canonSource.get());

	std::shared_ptr<const IStatement> resultStatement;
	if (destEseq) {
		resultStatement = std::make_shared<const CMoveStatement>(destEseq->Expression(), canonSource);
		
		if (sourceEseq) {
			resultStatement = processStatement(resultStatement);
		}
		resultStatement = std::make_shared<const CSeqStatement>(destEseq->Statement(), resultStatement);
	}
	else if (sourceEseq) {
		if (areCommuting(sourceEseq->Statement().get(), canonDest.get())) {
			resultStatement = std::make_shared<const CSeqStatement>(sourceEseq->Statement(), std::make_shared<const CMoveStatement>(canonDest, sourceEseq->Expression()));
		} else {
			// TODO MEM
			#pragma warning("TODO")
			CTemp temp;
			resultStatement = std::make_shared<const CSeqStatement>(std::make_shared<const CMoveStatement>(std::make_shared<const CTempExpression>(temp), canonDest),
				std::make_shared<const CSeqStatement>(sourceEseq->Statement(), std::make_shared<const CMoveStatement>(std::make_shared<const CTempExpression>(temp), sourceEseq->Expression())));
		}
	} else {
		resultStatement = std::make_shared<const CMoveStatement>(canonDest, canonSource);
	}

	updateLastStatement(std::move(resultStatement));
}
void CEseqRemoverVisitor::visit(const CExpStatement* node)
{
	node->Expression()->Accept(this);
	std::shared_ptr<const IExpression> canonExpression = lastExpression;

	const CEseqExpression* expressionEseq = dynamic_cast<const CEseqExpression*>(canonExpression.get());

	std::shared_ptr<const IStatement> resultStatement;
	if (expressionEseq) {

		resultStatement = std::make_shared<const CSeqStatement>(expressionEseq->Statement(), std::make_shared<const CExpStatement>(expressionEseq->Expression()));
	} else {
		resultStatement = std::make_shared<const CExpStatement>(canonExpression);
	}

	updateLastStatement(resultStatement);
}

void CEseqRemoverVisitor::visit(const CJumpStatement* node)
{
	updateLastStatement(new CJumpStatement(node->Target()));
}

void CEseqRemoverVisitor::visit(const CJumpConditionalStatement* node)
{
	node->Left()->Accept(this);
	std::shared_ptr<const IExpression> canonLeft = lastExpression;
	node->Right()->Accept(this);
	std::shared_ptr<const IExpression> canonRight = lastExpression;

	const CEseqExpression* leftEseq = dynamic_cast<const CEseqExpression*>(canonLeft.get());
	const CEseqExpression* rightEseq = dynamic_cast<const CEseqExpression*>(canonRight.get());

	std::shared_ptr<const IStatement> resultStatement;

	if (leftEseq) {

		resultStatement = std::make_shared<const CJumpConditionalStatement>(node->Operation(), leftEseq->Expression(), canonRight, node->TrueLabel(), node->FalseLabel());
		
		if (rightEseq) {
			resultStatement = processStatement(resultStatement);
		}
		resultStatement = std::make_shared<const CSeqStatement>(leftEseq->Statement(), resultStatement);
	}
	else if (rightEseq) {
		if (areCommuting(rightEseq->Statement().get(), canonLeft.get())) {

			resultStatement = std::make_shared<const CSeqStatement>(rightEseq->Statement(), 
				std::make_shared<const CJumpConditionalStatement>(node->Operation(), canonLeft, rightEseq->Expression(), node->TrueLabel(), node->FalseLabel()));
		} else {
			CTemp temp;
			resultStatement = nullptr;
			resultStatement = std::make_shared<const CSeqStatement>(std::make_shared<const CMoveStatement>(std::make_shared<const CTempExpression>(temp), canonLeft),
				std::make_shared<const CSeqStatement>(rightEseq->Statement(), std::make_shared<const CJumpConditionalStatement>(node->Operation(),
				std::make_shared<const CMemExpression>(std::make_shared<const CTempExpression>(temp)), rightEseq->Expression(), node->TrueLabel(), node->FalseLabel())));
		}
	} else {
		resultStatement = std::make_shared<const CJumpConditionalStatement>(node->Operation(), canonLeft, canonRight, node->TrueLabel(), node->FalseLabel());
	}

	updateLastStatement(resultStatement);

}

void CEseqRemoverVisitor::visit(const CSeqStatement* node)
{
	node->LeftStatement()->Accept(this);
	std::shared_ptr<const IStatement> canonLeft = lastStatement;
	node->RightStatement()->Accept(this);
	std::shared_ptr<const IStatement> canonRight = lastStatement;

	std::shared_ptr<const IStatement> resultStatement = std::make_shared<const CSeqStatement>(canonLeft, canonRight);

	updateLastStatement(resultStatement);

}

void CEseqRemoverVisitor::visit(const CLabelStatement* node)
{
	updateLastStatement(new CLabelStatement(node->Label()));
}

void CEseqRemoverVisitor::visit(const CStatementList * node)
{
	assert(false);
}

void CEseqRemoverVisitor::updateLastExpression(const IExpression* expression)
{
	lastExpression = std::shared_ptr<const IExpression>(expression);
}

void CEseqRemoverVisitor::updateLastExpression(std::shared_ptr<const IExpression> expression)
{
	lastExpression = expression;
}

void CEseqRemoverVisitor::updateLastExpressionList(const CExpressionList* list)
{
	lastExpressionList = std::shared_ptr<const CExpressionList>(list);
}

void CEseqRemoverVisitor::updateLastExpressionList(std::shared_ptr<const CExpressionList> list)
{
	lastExpressionList = list;
}

void CEseqRemoverVisitor::updateLastStatement(const IStatement* statement)
{
	lastStatement = std::shared_ptr<const IStatement>(statement);
}

void CEseqRemoverVisitor::updateLastStatement(std::shared_ptr<const IStatement> statement)
{
	lastStatement = statement;
}

std::shared_ptr<const IExpression> CEseqRemoverVisitor::processExpression(std::shared_ptr<const IExpression> expression) const
{
	CEseqRemoverVisitor visitor;
	expression->Accept(&visitor);
	return visitor.getExpressionTree();
}

std::shared_ptr<const IStatement> CEseqRemoverVisitor::processStatement(std::shared_ptr<const IStatement> statement) const
{
	CEseqRemoverVisitor visitor;
	statement->Accept(&visitor);
	return visitor.getStatementTree();
}

bool CEseqRemoverVisitor::areCommuting(const IStatement* statement, const IExpression* expression)
{
	assert(statement != nullptr && expression != nullptr);
	const CExpStatement* expStatement = dynamic_cast<const CExpStatement*>(statement);
	bool isStatementEmpty = expStatement != 0 && dynamic_cast<const CConstExpression*>(expStatement->Expression()) != 0;
	bool isConstExpression = dynamic_cast<const CConstExpression*>(expression) != 0;
	bool isNameExpression = dynamic_cast<const CNameExpression*>(expression) != 0;
	return isStatementEmpty || isConstExpression || isNameExpression;
}

} // namespace IR