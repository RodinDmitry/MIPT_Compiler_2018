#pragma once

#include <Tree.h>
#include <Class.h>
#include <MainClass.h>

class CProgram : public ITree {
public:
	CProgram(CMain* main, CClassList* classes);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CMain> main;
	std::unique_ptr<CClassList> classes;

	std::string GetLabel() override;

};