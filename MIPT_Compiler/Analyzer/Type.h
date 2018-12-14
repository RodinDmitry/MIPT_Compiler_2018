#pragma once
#include <Tree.h>
#include <DataType.h>

class CType : public ITree {
public:
	CType();
	CType(const char* instance, int line = -1);
	CType(TDataType type, int line = -1);

	virtual void Accept(IVisitor* visitor) override;

	TDataType type;
	std::string instance;

	const std::string& GetLabel() const override;
};