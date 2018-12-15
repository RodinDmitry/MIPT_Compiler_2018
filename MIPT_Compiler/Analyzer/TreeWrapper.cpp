#include <TreeWrapper.h>
#include <IR/Temporary.h>

namespace IR {
	std::shared_ptr<const IExpression> CExpressionWrapper::ToExpression()
	{
		return expression;
	}

	std::shared_ptr<const IStatement> CExpressionWrapper::ToStatement()
	{
		return std::shared_ptr<const IStatement>(new CExpStatement(expression));
	}

	std::shared_ptr<const IStatement> CExpressionWrapper::ToConditional(CLabel labelTrue, CLabel labelFalse)
	{
		return std::shared_ptr<const IStatement>(new CJumpConditionalStatement(TLogicOperatorType::LOT_NE,
			expression, std::shared_ptr<const IExpression>(new CConstExpression(0)), labelTrue, labelFalse));
	}

	std::shared_ptr<const IExpression> CStatementWrapper::ToExpression()
	{
		assert(false);
		return std::shared_ptr<const IExpression>();
	}

	std::shared_ptr<const IStatement> CStatementWrapper::ToStatement()
	{
		return statement;
	}

	std::shared_ptr<const IStatement> CStatementWrapper::ToConditional(CLabel labelTrue, CLabel labelFalse)
	{
		assert(false);
		return std::shared_ptr<const IStatement>();
	}

	std::shared_ptr<const IExpression> CConditionalWrapper::ToExpression()
	{
		CTempExpression* temp = new CTempExpression(CTemp());
		CLabel labelTrue;
		CLabel labelFalse;
		return std::shared_ptr<const IExpression>(new CEseqExpression(new CSeqStatement(
			new CMoveStatement(temp, new CConstExpression(1)), new CSeqStatement(ToConditional(labelTrue, labelFalse),
				std::shared_ptr<const CSeqStatement>( new CSeqStatement( new CLabelStatement(labelFalse), new CSeqStatement( 
					new CMoveStatement(temp, new CConstExpression(0)), new CLabelStatement(labelTrue) ) ) ) ) ), temp ) );
	}

	std::shared_ptr<const IStatement> CConditionalWrapper::ToStatement()
	{
		assert(false);
		return std::shared_ptr<const IStatement>();
	}

	std::shared_ptr<const IStatement> CConditionalWrapper::ToConditional(CLabel labelTrue, CLabel labelFalse)
	{
		return statement;
	}

	std::shared_ptr<const IStatement> CRelativeConditionalWrapper::ToConditional(CLabel labelTrue, CLabel labelFalse)
	{
		return std::shared_ptr<const IStatement>(new CJumpConditionalStatement(operatorType, operandLeft, operandRight,
			labelTrue, labelFalse));
	}

	std::shared_ptr<const IStatement> CAndConditionalWrapper::ToConditional(CLabel labelTrue, CLabel labelFalse)
	{
		CLabel middleLabel;
		const CSeqStatement* rightBranch = new CSeqStatement(std::shared_ptr<const CLabelStatement>(new CLabelStatement(middleLabel)),
			operandRight->ToConditional(labelTrue, labelFalse));
		return std::shared_ptr<const IStatement>(new CSeqStatement(operandLeft->ToConditional(middleLabel, labelFalse),
			std::shared_ptr<const CSeqStatement>(rightBranch)));
	}

	std::shared_ptr<const IStatement> CNegateConditionalWrapper::ToConditional(CLabel labelTrue, CLabel labelFalse)
	{
		return wrapper->ToConditional(labelFalse, labelTrue);
	}

	std::shared_ptr<const IStatement> COrConditionalWrapper::ToConditional(CLabel labelTrue, CLabel labelFalse)
	{
		CLabel middleLabel;
		const CSeqStatement* rightBranch = new CSeqStatement(std::shared_ptr<const CLabelStatement>(new CLabelStatement(middleLabel)),
			operandRight->ToConditional(labelTrue, labelFalse));
		return std::shared_ptr<const IStatement>(new CSeqStatement(operandLeft->ToConditional(labelTrue, middleLabel),
			std::shared_ptr<const CSeqStatement>(rightBranch)));
	}
}