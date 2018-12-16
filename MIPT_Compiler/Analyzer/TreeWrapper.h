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
	explicit CExpressionWrapper(const IExpression* _expression) : expression(_expression) {}
	explicit CExpressionWrapper(std::shared_ptr<const IExpression> _expression) : expression(_expression) {}
	virtual std::shared_ptr<const IExpression> ToExpression() override;
	virtual std::shared_ptr<const IStatement> ToStatement() override;
	virtual std::shared_ptr<const IStatement> ToConditional(CLabel labelTrue, CLabel labelFalse) override;

	virtual ~CExpressionWrapper() = default;
private:
	std::shared_ptr<const IExpression> expression;
};

class CStatementWrapper : public ITreeWrapper {
public:
	explicit CStatementWrapper(const IStatement* _statement) : statement(_statement) {}
	explicit CStatementWrapper(std::shared_ptr<const IStatement> _statement) : statement(_statement) {}
	virtual std::shared_ptr<const IExpression> ToExpression() override;
	virtual std::shared_ptr<const IStatement> ToStatement() override;
	virtual std::shared_ptr<const IStatement> ToConditional(CLabel labelTrue, CLabel labelFalse) override;

	virtual ~CStatementWrapper() = default;
private:
	std::shared_ptr<const IStatement> statement;
};

class CConditionalWrapper : public ITreeWrapper {
public:
	CConditionalWrapper() = default;
	virtual ~CConditionalWrapper() = default;
	explicit CConditionalWrapper(const IStatement* _statement) : statement(_statement) {}
	explicit CConditionalWrapper(std::shared_ptr<const IStatement> _statement) : statement(_statement) {}
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

	CRelativeConditionalWrapper(TLogicOperatorType _operatorType, std::shared_ptr<const IExpression> _operandLeft,
		std::shared_ptr<const IExpression> _operandRight) : operatorType(_operatorType), operandLeft(_operandLeft),
			operandRight(_operandRight) {}

	virtual std::shared_ptr<const IStatement> ToConditional(CLabel labelTrue, CLabel labelFalse) override;
	virtual ~CRelativeConditionalWrapper() = default;
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
	virtual ~CAndConditionalWrapper() = default;
private:
	std::shared_ptr<ITreeWrapper> operandLeft;
	std::shared_ptr<ITreeWrapper> operandRight;
};

class COrConditionalWrapper : public CConditionalWrapper {
public:
	COrConditionalWrapper(std::shared_ptr<ITreeWrapper> _operandLeft, std::shared_ptr<ITreeWrapper> _operandRight)
		: operandLeft(_operandLeft), operandRight(_operandRight) {}

	virtual std::shared_ptr<const IStatement> ToConditional(CLabel labelTrue, CLabel labelFalse) override;
	virtual ~COrConditionalWrapper() = default;
private:
	std::shared_ptr<ITreeWrapper> operandLeft;
	std::shared_ptr<ITreeWrapper> operandRight;
};

class CNegateConditionalWrapper : public CConditionalWrapper {
public:
	explicit CNegateConditionalWrapper(std::shared_ptr<ITreeWrapper> _wrapper)
		: wrapper(_wrapper) {}

	virtual std::shared_ptr<const IStatement> ToConditional(CLabel labelTrue, CLabel labelFalse) override;
	virtual ~CNegateConditionalWrapper() = default;
private:
	std::shared_ptr<ITreeWrapper> wrapper;
};

} // namespace IR