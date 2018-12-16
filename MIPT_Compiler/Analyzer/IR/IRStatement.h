#pragma once

#include <IR/IRTree.h>
#include <IR/Label.h>
#include <ErrorTable.h>
#include <vector>

namespace IR {

class IStatement : public ITree {
public:
	virtual ~IStatement() = default;
	virtual void Accept(IIRVisitor* visitor) const override;
};

enum class TLogicOperatorType : char {
	LOT_EQ,
	LOT_NE,
	LOT_LT,
	LOT_GT
};

class IExpression;

class CMoveStatement : public IStatement {
public:
	CMoveStatement(const IExpression* _destination, const IExpression* _source) : destination(_destination), source(_source) {}
	CMoveStatement(std::shared_ptr<const IExpression> _destination, std::shared_ptr<const IExpression> _source) : destination(_destination), source(_source) {}
	virtual ~CMoveStatement() = default;

	virtual void Accept(IIRVisitor* visitor) const override;
	const IExpression* Destination() const { return destination.get(); }
	const IExpression* Source() const { return source.get(); }

private:
	std::shared_ptr<const IExpression> destination;
	std::shared_ptr<const IExpression> source;
};

class CExpStatement : public IStatement {
public:
	explicit CExpStatement(const IExpression* _expression) : expression(_expression) {}
	explicit CExpStatement(std::shared_ptr<const IExpression> _expression) : expression(_expression) {}
	virtual ~CExpStatement() = default;

	virtual void Accept(IIRVisitor* visitor) const override;
	const IExpression* Expression() const { return expression.get(); }

private:
	std::shared_ptr<const IExpression> expression;
};

class CJumpStatement : public IStatement {
public:
	explicit CJumpStatement(const CLabel& _target) : target(_target) {}
	virtual ~CJumpStatement() = default;

	virtual void Accept(IIRVisitor* visitor) const override;
	CLabel Target() const { return target; }

private:
	CLabel target;
};

class CJumpConditionalStatement : public IStatement {
public:
	CJumpConditionalStatement(TLogicOperatorType _operation,
		const IExpression* _left, const IExpression* _right,
		const CLabel& _labelTrue, const CLabel& _labelFalse) : operation(_operation), left(_left), right(_right), labelTrue(_labelTrue),
			labelFalse(_labelFalse) {}
	CJumpConditionalStatement(TLogicOperatorType _operation,
		std::shared_ptr<const IExpression> _left, std::shared_ptr<const IExpression> _right,
		const CLabel& _labelTrue, const CLabel& _labelFalse) : operation(_operation), left(_left), right(_right), labelTrue(_labelTrue),
		labelFalse(_labelFalse) {}
	virtual ~CJumpConditionalStatement() = default;

	const IExpression* Left() const { return left.get(); }
	const IExpression* Right() const { return right.get(); }
	CLabel TrueLabel() const { return labelTrue; }
	CLabel FalseLabel() const { return labelFalse; }
	TLogicOperatorType Operation() const { return operation; }

	virtual void Accept(IIRVisitor* visitor) const override;

private:
	std::shared_ptr<const IExpression> left;
	std::shared_ptr<const IExpression> right;
	CLabel labelTrue;
	CLabel labelFalse;
	TLogicOperatorType operation;
};

class CSeqStatement : public IStatement {
public:
	CSeqStatement(const IStatement* _left, const IStatement* _right) : leftStatement(_left), rightStatement(_right) {}
	CSeqStatement(std::shared_ptr<const IStatement> _left, std::shared_ptr<const IStatement> _right) : leftStatement(_left), rightStatement(_right) {}
	~CSeqStatement() = default;

	const IStatement* LeftStatement() const { return leftStatement.get(); }
	const IStatement* RightStatement() const { return rightStatement.get(); }

	virtual void Accept(IIRVisitor* visitor) const override;

private:
	std::shared_ptr<const IStatement> leftStatement;
	std::shared_ptr<const IStatement> rightStatement;
};

class CLabelStatement : public IStatement {
public:
	explicit CLabelStatement(const CLabel& _label) : label(_label) {}
	~CLabelStatement() = default;

	CLabel Label() const { return label; }
	virtual void Accept(IIRVisitor* visitor) const override;
private:
	CLabel label;
};

class CStatementList : public IStatement {
public:
	CStatementList() = default;

	explicit CStatementList(const IStatement* statement) { Add(statement); }
	explicit CStatementList(std::shared_ptr<const IStatement> statement) { Add(statement); }

	void Add(const IStatement* statement) { Add(std::shared_ptr<const IStatement>(statement)); }
	void Add(std::shared_ptr<const IStatement> statement) { statements.push_back(statement); }

	const std::vector<std::shared_ptr<const IStatement>>& Statements() const { return statements; }
	virtual void Accept(IIRVisitor* visitor) const override;

private:
	std::vector<std::shared_ptr<const IStatement>> statements;
};

} // namespace IR