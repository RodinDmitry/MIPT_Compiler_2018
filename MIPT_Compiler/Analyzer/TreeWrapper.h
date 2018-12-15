#pragma once

#include <IR/IRExpression.h>
#include <IR/IRStatement.h>

namespace IR {

class ITreeWrapper {
public:
	virtual ~ITreeWrapper() = default;
	virtual std::shared_ptr<const IExpression> ToExpression() = 0;
	virtual std::shared_ptr<const IStatement> ToStatement() = 0;
	virtual std::shared_ptr<const IStatement> ToConditional(CLabel labelTrue, CLabel labelFalse) = 0;
};

class CExpressionWrapper : public ITreeWrapper {
public:
	CExpressionWrapper(const IExpression* _expression) : expression(_expression) {}
	CExpressionWrapper(std::shared_ptr<const IExpression> _expression) : expression(_expression) {}
	virtual std::shared_ptr<const IExpression> ToExpression() override;
	virtual std::shared_ptr<const IStatement> ToStatement() override;
	virtual std::shared_ptr<const IStatement> ToConditional(CLabel labelTrue, CLabel labelFalse) override;

private:
	std::shared_ptr<const IExpression> expression;
};

class CStatementWrapper : public ITreeWrapper {
public:
	CStatementWrapper(const IStatement* _statement) : statement(_statement) {}
	CStatementWrapper(std::shared_ptr<const IStatement> _statement) : statement(_statement) {}
	virtual std::shared_ptr<const IExpression> ToExpression() override;
	virtual std::shared_ptr<const IStatement> ToStatement() override;
	virtual std::shared_ptr<const IStatement> ToConditional(CLabel labelTrue, CLabel labelFalse) override;

private:
	std::shared_ptr<const IStatement> statement;
};

class CConditionalWrapper : public ITreeWrapper {
public:
	CConditionalWrapper() = default;
	virtual ~CConditionalWrapper() = default;
	CConditionalWrapper(const IStatement* _statement) : statement(_statement) {}
	CConditionalWrapper(std::shared_ptr<const IStatement> _statement) : statement(_statement) {}
	virtual std::shared_ptr<const IExpression> ToExpression() override;
	virtual std::shared_ptr<const IStatement> ToStatement() override;
	virtual std::shared_ptr<const IStatement> ToConditional(CLabel labelTrue, CLabel labelFalse) override;

private:
	std::shared_ptr<const IStatement> statement;
};

class CRelativeConditionalWrapper : public CConditionalWrapper {
public:
	CRelativeConditionalWrapper(TLogicOperatorType _operatorType, const IExpression* _operandLeft, 
		const IExpression* _operandRight) : operatorType(_operatorType), operandLeft(_operandLeft), operandRight(_operandRight) {}

	CRelativeConditionalWrapper(TLogicOperatorType _operatorType, std::unique_ptr<const IExpression> _operandLeft,
		std::unique_ptr<const IExpression> _operandRight) : operatorType(_operatorType), operandLeft(std::move(_operandLeft)),
			operandRight(std::move(_operandRight)) {}

	virtual std::shared_ptr<const IStatement> ToConditional(CLabel labelTrue, CLabel labelFalse) override;

private:
	TLogicOperatorType operatorType;
	std::shared_ptr<const IExpression> operandLeft;
	std::shared_ptr<const IExpression> operandRight;
};

class CAndConditionalWrapper : public CConditionalWrapper {
public:
	CAndConditionalWrapper(std::shared_ptr<ITreeWrapper> _operandLeft, std::shared_ptr<ITreeWrapper> _operandRight)
		: operandLeft(_operandLeft), operandRight(_operandRight) {}

	virtual std::shared_ptr<const IStatement> ToConditional(CLabel labelTrue, CLabel labelFalse) override;
private:
	std::shared_ptr<ITreeWrapper> operandLeft;
	std::shared_ptr<ITreeWrapper> operandRight;
};

class COrConditionalWrapper : public CConditionalWrapper {
public:
	COrConditionalWrapper(std::shared_ptr<ITreeWrapper> _operandLeft, std::shared_ptr<ITreeWrapper> _operandRight)
		: operandLeft(_operandLeft), operandRight(_operandRight) {}

	virtual std::shared_ptr<const IStatement> ToConditional(CLabel labelTrue, CLabel labelFalse) override;
private:
	std::shared_ptr<ITreeWrapper> operandLeft;
	std::shared_ptr<ITreeWrapper> operandRight;
};

class CNegateConditionalWrapper : public CConditionalWrapper {
public:
	CNegateConditionalWrapper(std::shared_ptr<ITreeWrapper> _wrapper)
		: wrapper(_wrapper) {}

	virtual std::shared_ptr<const IStatement> ToConditional(CLabel labelTrue, CLabel labelFalse) override;
private:
	std::shared_ptr<ITreeWrapper> wrapper;
};

} // namespace IR