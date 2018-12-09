#pragma once
#include <Tree.h>
#include <DataType.h>

class CType : public ITree {
public:
	CType();
	CType(char* instance, int line);
	CType(TDataType type, int line);

	virtual void Accept(IVisitor* visitor) override;

	TDataType type;
	std::string instance;

	std::string GetLabel() override;
};