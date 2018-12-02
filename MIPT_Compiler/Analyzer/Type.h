#pragma once
#include <Tree.h>
#include <DataType.h>

class CType : public ITree {
public:
	CType();
	CType(const char* instance);
	CType(TDataType type);

	virtual void Accept(IVisitor* visitor) override;

	TDataType type;
	std::string instance;

	std::string GetLabel() override;
};