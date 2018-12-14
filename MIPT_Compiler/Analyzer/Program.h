#pragma once

#include <Tree.h>
#include <Class.h>
#include <MainClass.h>
#include <iostream>

class CProgram : public ITree {
public:
	CProgram(CMain* main, CClassList* classes, int line);
	virtual void Accept(IVisitor* visitor) override;

	std::unique_ptr<CMain> main;
	std::unique_ptr<CClassList> classes;

	const std::string& GetLabel() const override;
};