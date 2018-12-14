#pragma once

#include <IR/IRTree.h>
#include <IR/Label.h>
#include <vector>

namespace IR {

class CStatement : public ITree {
public:
	virtual ~CStatement() = default;
	virtual void Accept(IIRVisitor* visitor) override;
};

enum class TLogicOperatorType : char {
	LOT_EQ,
	LOT_NE,
	LOT_LT,
	LOT_GT,
	LOT_LE,
	LOT_GE,
};

class IExpression;

class CMoveStatement : public CStatement {
public:
	CMoveStatement(const IExpression* _destination, const IExpression* _source) : destination(_destination), source(_source) {}
	CMoveStatement(std::shared_ptr<const IExpression> _destination, std::shared_ptr<const IExpression> _source) : destination(_destination), source(_source) {}
	virtual ~CMoveStatement() = default;

	virtual void Accept(IIRVisitor* visitor) override;
	const IExpression* Destination() const { return destination.get(); }
	const IExpression* Source() const { return source.get(); }

private:
	std::shared_ptr<const IExpression> destination;
	std::shared_ptr<const IExpression> source;
};

class CExpStatement : public CStatement {
public:
	CExpStatement(const IExpression* _expression) : expression(_expression) {}
	CExpStatement(std::shared_ptr<const IExpression> _expression) : expression(_expression) {}
	virtual ~CExpStatement() = default;

	virtual void Accept(IIRVisitor* visitor) override;
	const IExpression* Expression() const { return expression.get(); }

private:
	std::shared_ptr<const IExpression> expression;
};

class CJumpStatement : public CStatement {
public:
	CJumpStatement(CLabel _target) : target(_target) {}
	virtual ~CJumpStatement() = default;

	virtual void Accept(IIRVisitor* visitor) override;
	CLabel Target() const { return target; }

private:
	CLabel target;
};

class CJumpConditionalStatement : public CStatement {
public:
	CJumpConditionalStatement(TLogicOperatorType _operation,
		const IExpression* _left, const IExpression* _right,
		CLabel _labelTrue, CLabel _labelFalse) : operation(_operation), left(_left), right(_right), labelTrue(_labelTrue),
			labelFalse(_labelFalse) {}
	CJumpConditionalStatement(TLogicOperatorType _operation,
		std::shared_ptr<const IExpression> _left, std::shared_ptr<const IExpression> _right,
		CLabel _labelTrue, CLabel _labelFalse) : operation(_operation), left(_left), right(_right), labelTrue(_labelTrue),
		labelFalse(_labelFalse) {}
	virtual ~CJumpConditionalStatement() = default;

	const IExpression* Left() const { return left.get(); }
	const IExpression* Right() const { return right.get(); }
	CLabel TrueLabel() const { return labelTrue; }
	CLabel FalseLabel() const { return labelFalse; }
	TLogicOperatorType Operation() const { return operation; }

	virtual void Accept(IIRVisitor* visitor) override;

private:
	std::shared_ptr<const IExpression> left;
	std::shared_ptr<const IExpression> right;
	CLabel labelTrue;
	CLabel labelFalse;
	TLogicOperatorType operation;
};

class CSeqStatement : public CStatement {
public:
	CSeqStatement(const CStatement* _left, const CStatement* _right) : leftStatement(_left), rightStatement(_right) {}
	CSeqStatement(std::shared_ptr<const CStatement> _left, std::shared_ptr<const CStatement> _right) : leftStatement(_left), rightStatement(_right) {}
	~CSeqStatement() = default;

	const CStatement* LeftStatement() const { return leftStatement.get(); }
	const CStatement* RightStatement() const { return rightStatement.get(); }

	virtual void Accept(IIRVisitor* visitor) override;

private:
	std::shared_ptr<const CStatement> leftStatement;
	std::shared_ptr<const CStatement> rightStatement;
};

class CLabelStatement : public CStatement {
public:
	CLabelStatement(CLabel _label) : label(_label) {}
	~CLabelStatement() = default;

	CLabel Label() const { return label; }
	virtual void Accept(IIRVisitor* visitor) override;
private:
	CLabel label;
};

class CStatementList : public CStatement {
public:
	CStatementList() = default;

	CStatementList(const CStatement* statement) { Add(statement); }
	CStatementList(std::shared_ptr<const CStatement> statement) { Add(std::move(statement)); }

	void Add(const CStatement* statement) { Add(std::shared_ptr<const CStatement>(statement)); }
	void Add(std::shared_ptr<const CStatement> statement) { statements.push_back(statement); }

	const std::vector<std::shared_ptr<const CStatement>>& Statements() const { return statements; }
	virtual void Accept(IIRVisitor* visitor) override;

private:
	std::vector<std::shared_ptr<const CStatement>> statements;
};

} // namespace IR