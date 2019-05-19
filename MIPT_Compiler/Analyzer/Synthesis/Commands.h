#pragma once

#include <Synthesis/Node.h>
#include <string>
#include <vector>
#include <IR/IRExpression.h>

namespace Synthesis {

	class ICommand : public INode
	{
	public:
		virtual ~ICommand() = default;
		void Accept(IVisitor* visitor) const override;
	};

	class IExpression : public ICommand 
	{
	public:
		virtual ~IExpression() = default;
	};

	class CNullExpression : public IExpression 
	{
	public:
		CNullExpression() = default;
		~CNullExpression() = default;
		void Accept(IVisitor* visitor) const override;
	};

	class CTempExpression : public IExpression {
	public:
		CTempExpression(std::string _name) : name(_name) {}
		~CTempExpression() = default;

		void Accept(IVisitor* visitor) const override;
		const std::string& Name() const { return name; }

	private:
		std::string name;
	};

	class CAddCommand : public IExpression {
	public:
		CAddCommand(const IExpression* _leftOperand, const IExpression* _rightOperand) :
			leftOperand(_leftOperand), rightOperand(_rightOperand) {}
		~CAddCommand() = default;

		void Accept(IVisitor* visitor) const override;

		const IExpression* LeftOperand() const { return leftOperand; }
		const IExpression* RightOperand() const { return rightOperand; }

	private:
		const IExpression* leftOperand;
		const IExpression* rightOperand;
	};

	class CAddConstCommand : public IExpression {
	public:
		CAddConstCommand(const IExpression* _expression, const int _constant) :
			expression(_expression),
			constant(_constant) {}
		~CAddConstCommand() {}

		void Accept(IVisitor* visitor) const override;

		const IExpression* Expression() const { return expression; }
		int Constant() const { return constant; }

	private:
		const IExpression* expression;
		const int constant;
	};

	class CSubCommand : public IExpression {
	public:
		CSubCommand(const IExpression* _leftOperand, const IExpression* _rightOperand) :
			leftOperand(_leftOperand), rightOperand(_rightOperand) {}
		~CSubCommand() {}

		void Accept(IVisitor* visitor) const override;

		const IExpression* LeftOperand() const { return leftOperand; }
		const IExpression* RightOperand() const { return rightOperand; }

	private:
		const IExpression* leftOperand;
		const IExpression* rightOperand;
	};

	class CSubConstCommand : public IExpression {
	public:
		CSubConstCommand(const IExpression* _expression, const int _constant) :
			expression(_expression),
			constant(_constant) {}
		~CSubConstCommand() {}

		void Accept(IVisitor* visitor) const override;

		const IExpression* Expression() const { return expression; }
		int Constant() const { return constant; }

	private:
		const IExpression* expression;
		const int constant;
	};

	class CMultCommand : public IExpression {
	public:
		CMultCommand(const IExpression* _leftOperand, const IExpression* _rightOperand) :
			leftOperand(_leftOperand), rightOperand(_rightOperand) {}
		~CMultCommand() {}

		void Accept(IVisitor* visitor) const override;

		const IExpression* LeftOperand() const { return leftOperand; }
		const IExpression* RightOperand() const { return rightOperand; }

	private:
		const IExpression* leftOperand;
		const IExpression* rightOperand;
	};

	class CDivCommand : public IExpression {
	public:
		CDivCommand(const IExpression* _leftOperand, const IExpression* _rightOperand) :
			leftOperand(_leftOperand), rightOperand(_rightOperand) {}
		~CDivCommand() {}

		void Accept(IVisitor* visitor) const override;

		const IExpression* LeftOperand() const { return leftOperand; }
		const IExpression* RightOperand() const { return rightOperand; }

	private:
		const IExpression* leftOperand;
		const IExpression* rightOperand;
	};

	class CLoadCommand : public IExpression {
	public:
		CLoadCommand(const IExpression* _source, const int _offset) :
			source(_source),
			offset(_offset) {}

		~CLoadCommand() {}

		void Accept(IVisitor* visitor) const override;

		const IExpression* Source() const { return source; }
		int Offset() const { return offset; }

	private:
		const IExpression* source;
		const int offset;
	};

	class CStatement : public ICommand 
	{
	public:
		void Accept(IVisitor* visitor) const override;
	};

	class CMemoryStatement : public CStatement 
	{
	public:
		void Accept(IVisitor* visitor) const override;
	};

	class CStoreCommand : public CMemoryStatement {
	public:
		CStoreCommand(const IExpression* _destination, const int _offset, const IExpression* _source) :
			destination(_destination),
			offset(_offset),
			source(_source) {}

		~CStoreCommand() {}

		void Accept(IVisitor* visitor) const override;

		const IExpression* Destination() const { return destination; }
		int Offset() const { return offset; }
		const IExpression* Source() const { return source; }

	private:
		const IExpression* destination;
		const int offset;
		const IExpression* source;
	};

	class CMoveRegisterCommand : public CStatement {
	public:
		CMoveRegisterCommand(const CTempExpression* _destination, const IExpression* _source) :
			destination(_destination),
			source(_source) {}

		~CMoveRegisterCommand() {}

		const CTempExpression* Destination() const { return destination; }
		const IExpression* Source() const { return source; }

		void Accept(IVisitor* visitor) const override;
	private:
		const CTempExpression* destination;
		const IExpression* source;
	};

	class CLabelDeclarationCommand : public ICommand {
	public:
		CLabelDeclarationCommand(std::string _name) :
			name(_name) {}
		~CLabelDeclarationCommand() {}

		void Accept(IVisitor* visitor) const override;

		const std::string& Name() const { return name; }

	private:
		std::string name;
	};

	class CCallFunctionCommand : public IExpression {
	public:
		CCallFunctionCommand(const std::string& _function,
			const std::vector<const IExpression*>& _arguments) :
			function(_function),
			arguments(_arguments) {}

		~CCallFunctionCommand() {}

		void Accept(IVisitor* visitor) const override;

		const std::string& Function() const { return function; }
		const std::vector<const Synthesis::IExpression*>& Arguments() const { return arguments; }

	private:
		const std::string function;
		const std::vector<const Synthesis::IExpression*> arguments;
	};

	class CJumpCommand : public CStatement {
	public:
		CJumpCommand(std::string _labelName) : labelName(_labelName) {}
		~CJumpCommand() {}

		void Accept(IVisitor* visitor) const override;

		const std::string& LabelName() const { return labelName; }

	private:
		std::string labelName;
	};

	class CConditionalJumpCommand : public CStatement {
	public:
		CConditionalJumpCommand(const IExpression* _leftPart, const IExpression* _rightPart,
			IR::TLogicOperatorType _cmp, std::string _positiveLabelName, std::string _negativeLabelName) :
			leftPart(_leftPart),
			rightPart(_rightPart),
			cmp(_cmp),
			positiveLabelName(_positiveLabelName),
			negativeLabelName(_negativeLabelName) {}
		~CConditionalJumpCommand() {}

		void Accept(IVisitor* visitor) const override;

		const IExpression* LeftPart() const { return leftPart; }
		const IExpression* RightPart() const { return rightPart; }
		IR::TLogicOperatorType Cmp() const { return cmp; }
		const std::string& PositiveLabelName() const { return positiveLabelName; }
		const std::string& NegativeLabelName() const { return negativeLabelName; }

	private:
		const IExpression* leftPart;
		const IExpression* rightPart;
		IR::TLogicOperatorType cmp;
		std::string positiveLabelName;
		std::string negativeLabelName;
	};

	class CExpStatementCommand : public CStatement {
	public:
		CExpStatementCommand(const IExpression* _expression) :
			expression(_expression) {}
		~CExpStatementCommand() {}

		void Accept(IVisitor* visitor) const override;
		const IExpression* Expression() const { return expression; }

	private:
		const IExpression* expression;
	};

} // namespace Synthesis