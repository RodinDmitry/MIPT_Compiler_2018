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

const std::string& CStatementList::GetLabel() const
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

const std::string& CVisibilityStatement::GetLabel() const
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

const std::string& CIfStatement::GetLabel() const
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

const std::string& CWhileStatement::GetLabel() const
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

const std::string& CPrintStatement::GetLabel() const
{
	return  "print" + labelAddings;;
}

CAssignStatement::CAssignStatement(CLValueExpression* _left, IExpression* _right, int _line) : left(_left), right(_right), IStatement(_line)
{
}

void CAssignStatement::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

const std::string& CAssignStatement::GetLabel() const
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

const std::string& CVariableStatement::GetLabel() const
{
	return "variable" + labelAddings;
}

