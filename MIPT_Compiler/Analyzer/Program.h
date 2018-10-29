#pragma once

#include <Tree.h>
#include <Class.h>
#include <MainClass.h>

class CProgram : public ITree {
public:
	CProgram(CMain* main, CClassList* classes);
	virtual void Accept(IVisitor* visitor) override;

	CMain* main;
	CClassList* classes;

	std::string GetLabel() override;

};