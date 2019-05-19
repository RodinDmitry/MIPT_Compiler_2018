#pragma once

#include <map>
#include <tuple>
#include <memory>

#include <IR/IRTree.h>
#include <Synthesis/Node.h>
#include <Synthesis/Commands.h>

namespace Synthesis {

	using Dynamic = std::map<const IR::ITree*, std::pair<int, std::shared_ptr<const ICommand>>>;

	class CPattern 
	{
	public:
		CPattern(Dynamic* _dynamic) : dynamic(_dynamic) {}
		virtual void Consume(const IR::ITree* node) = 0;

	protected:
		template<typename T>
		class ValidAndValue {
		public:
			ValidAndValue(bool _valid, const T& _value) : valid(_valid), value(_value) {}
			T operator->() const { return value; }
			T operator*() const { return value; }
			bool IsValid() const { return valid; }
		private:
			bool valid;
			T value;
		};

		template <typename Command>
		void ConsumeBinaryOperation(const IR::ITree* node, IR::TOperator operation);

		template<typename T>
		ValidAndValue<const T*> GetTypedNode(const IR::ITree* node);
		int GetDynamicPrice(const IR::ITree* node);
		const Synthesis::IExpression* GetDynamicValue(const IR::ITree* node);

		Dynamic* dynamic;
	};

	class CTempPattern : public CPattern 
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CLabelPattern : public CPattern 
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CAddPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CSubPattern : public CPattern 
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CMultPattern : public CPattern 
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CDivPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CSubConstPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CAddConstLeftPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CAddConstRightPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};


	class CConstPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CLoadMemoryPattern : public CPattern 
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	// M[C]
	class CLoadConstMemoryPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CLoadMemoryLeftOffsetPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CLoadMemoryRightOffsetPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CStoreMemoryPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CStoreConstMemoryPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CStoreMemoryLeftOffsetPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CStoreMemoryRightOffsetPattern : public CPattern 
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CStoreRegisterPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CCallFunctionPattern : public CPattern 
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CJumpPattern : public CPattern 
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CConditionalJumpPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

	class CExpStatementPattern : public CPattern
	{
	public:
		using CPattern::CPattern;
		void Consume(const IR::ITree* node) override;
	};

}