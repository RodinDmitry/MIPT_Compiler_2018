#include <Statement.h>
#include <Visitor.h>
#include <Id.h>
#include <Variable.h>

IStatement::IStatement(int _line) : ITree(_line) {}

void IStatement::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

CStatementList::CStatementList() : ITree(-1) {}

void CStatementList::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CStatementList::Add(IStatement* statement)
{
	std::shared_ptr<IStatement> ptr(statement);
	statements.push_back(ptr);
}

std::string CStatementList::GetLabel()
{
	return  "statements" + labelAddings;;
}

CVisibilityStatement::CVisibilityStatement(IStatement* _statement, int _line) : statement(_statement), IStatement(_line)
{
}

void CVisibilityStatement::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CVisibilityStatement::GetLabel()
{
	return  "visibility" + labelAddings;;
}

CIfStatement::CIfStatement(IExpression* _condition, IStatement* _thenStatement, IStatement* _elseStatement, int _line) :
		condition(_condition), thenStatement(_thenStatement), elseStatement(_elseStatement), IStatement(_line)
{
}

void CIfStatement::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CIfStatement::GetLabel()
{
	return  "if" + labelAddings;;
}

CWhileStatement::CWhileStatement(IExpression* _condition, IStatement* _statement, int _line) : 
		condition(_condition), statement(_statement), IStatement(_line)
{
}

void CWhileStatement::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CWhileStatement::GetLabel()
{
	return  "while" + labelAddings;;
}

CPrintStatement::CPrintStatement(IExpression* _expression, int _line) : expression(_expression), IStatement(_line)
{
}

void CPrintStatement::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

std::string CPrintStatement::GetLabel()
{
	return  "print" + labelAddings;;
}

CEqualStatement::CEqualStatement(CLValueExpression* _left, IExpression* _right, int _line) : left(_left), right(_right), IStatement(_line)
{
}

void CEqualStatement::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

std::string CEqualStatement::GetLabel()
{
	return "assign" + labelAddings;;
}

CVariableStatement::CVariableStatement(CVariable* _variable, int _line) : variable(_variable), IStatement(_line)
{
}

void CVariableStatement::Accept(IVisitor * visitor)
{
	visitor->visit(this);
}

std::string CVariableStatement::GetLabel()
{
	return "variable" + labelAddings;
}

