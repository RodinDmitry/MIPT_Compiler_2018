#pragma once

#include <Tree.h>
#include <Class.h>
#include <MainClass.h>

class CProgramm : public ITree {
public:
	CProgramm(CMain* main, CClassList* classes);
	virtual void Accept(IVisitor* visitor) override;

	CMain* main;
	CClassList* classes;

};