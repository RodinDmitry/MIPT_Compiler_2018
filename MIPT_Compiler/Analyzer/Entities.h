#pragma once
#include <vector>

class Tree {
public:

	void SetParent(Tree* parent);

protected:
	Tree* parent;
	std::vector<Tree*> children;
};

class Statement: public Tree {};

class Expression : public Tree {};

class Identifier : public Tree {};

class TypeIdentifier : public Tree {};

class MethodDeclaration : public Tree {};

class ClassDeclaration : public Tree {};

class MainClass : public Tree {};

class Goal : public Tree {};

class VarDeclaration : public Tree {};


