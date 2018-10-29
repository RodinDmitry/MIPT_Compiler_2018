#include <Statement.h>
#include <Visitor.h>
#include <Id.h>
#include <Variable.h>

void IStatement::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CStatementList::Accept(IVisitor* visitor)
{
	visitor->visit(this);
}

void CStatementList::Add(IStatement* statement)
{
	statements.push_back(statement);
}

std::string CStatementList::GetLabel()
{
	return  "statements" + labelAddings;;
}

CVisibilityStatement::CVisibilityStatement(IStatement* _statement) : statement(_statement)
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

CIfStatement::CIfStatement(IExpression* _condition, IStatement* _thenStatement, IStatement* _elseStatement) :
		condition(_condition), thenStatement(_thenStatement), elseStatement(_elseStatement)
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

CWhileStatement::CWhileStatement(IExpression* _condition, IStatement* _statement) : 
		condition(_condition), statement(_statement)
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

CPrintStatement::CPrintStatement(IExpression* _expression) : expression(_expression)
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

CEqualStatement::CEqualStatement(CLValueExpression* _left, IExpression* _right) : left(_left), right(_right)
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

CVariableStatement::CVariableStatement(CVariable* _variable) : variable(_variable)
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

