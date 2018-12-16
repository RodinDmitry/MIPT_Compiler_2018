#include <FrameVistor.h>
#include <SymbolTable.h>
#include <Frame.h>

void CFrameVisitor::AddFrames(ITree* root, const std::string& _tableName)
{
	tableName = _tableName;
	nodes.clear();
	nodes.push_front(root);
	while (nodes.size() > 0) {
		ITree* current = nodes.front();
		nodes.pop_front();
		current->Accept(this);
	}
}

void CFrameVisitor::visit(CArgumentList* node)
{
	
}

void CFrameVisitor::visit(CClassInternals* node)
{	
	pushIfNotNull(node->function.get());
}

void CFrameVisitor::visit(CClassInternalsList* node)
{
	for (int i = 0; i < node->internals.size(); i++) {
		pushIfNotNull(node->internals[i].get());
	}
}

void CFrameVisitor::visit(CClass* node)
{
	currentClass = CSymbol::GetSymbol(node->declaration->name->name);
	//const CClassInfo* info = CSymbolTable::FindClass(tableName, currentClass);
	pushIfNotNull(node->internals.get());
}

void CFrameVisitor::visit(CClassList* node)
{
	for (int i = static_cast<int>(node->classes.size()) - 1; i >= 0; i--) {
		pushIfNotNull(node->classes[i].get());
	}
}

void CFrameVisitor::visit(CExpressionList* node)
{
}

void CFrameVisitor::visit(CBinaryExpression* node)
{
	
}

void CFrameVisitor::visit(CArrayExpression* node)
{
	
}

void CFrameVisitor::visit(CCallExpression* node)
{
	
}

void CFrameVisitor::visit(CNewArrayExpression* node)
{
	
}

void CFrameVisitor::visit(CNewExpression* node)
{
	
}

void CFrameVisitor::visit(CNotExpression* node)
{
	
}

void CFrameVisitor::visit(CBracketsExpression* node)
{
}

void CFrameVisitor::visit(CFunction* node)
{
	const std::string& funcName = node->name->name;
	const CClassInfo* info = CSymbolTable::FindClass(tableName, currentClass);
	const CFunctionInfo* funcInfo = info->FindMethod(CSymbol::GetSymbol(funcName));
	node->SetFrame(std::make_shared<CMiniJavaMethodFrame>(info, funcInfo));
}

void CFrameVisitor::visit(CMainFunction* node)
{
	const CClassInfo* info = CSymbolTable::FindClass(tableName, currentClass);
	const CFunctionInfo* funcInfo = new CFunctionInfo(CSymbol::GetSymbol("main"), new CType(), info, VMT_Public);
	node->SetFrame(std::make_shared<CMiniJavaMethodFrame>(info, funcInfo));
}

void CFrameVisitor::visit(CMain* node)
{
	currentClass = CSymbol::GetSymbol(node->name->name);
	pushIfNotNull(node->mainFunction.get());
}

void CFrameVisitor::visit(CProgram* node)
{
	pushIfNotNull(node->classes.get());
	pushIfNotNull(node->main.get());
}

void CFrameVisitor::visit(IStatement *)
{
	assert(false);
}

void CFrameVisitor::visit(CStatementList* node)
{
	
}

void CFrameVisitor::visit(CVisibilityStatement* node)
{	
}

void CFrameVisitor::visit(CIfStatement* node)
{	
}

void CFrameVisitor::visit(CWhileStatement* node)
{	
}

void CFrameVisitor::visit(CPrintStatement* node)
{	
}

void CFrameVisitor::visit(CAssignStatement* node)
{
}

void CFrameVisitor::visit(CVariableStatement* node)
{
}

void CFrameVisitor::visit(CVariable* node)
{
}

void CFrameVisitor::visit(CFunctionVisibilityEnd*)
{
}

void CFrameVisitor::visit(CClassVisibilityEnd*)
{
}

void CFrameVisitor::visit(CVisibilityBlockStart*)
{
}

void CFrameVisitor::visit(CVisibilityBlockEnd*)
{
}

void CFrameVisitor::pushIfNotNull(ITree* node)
{
	if (node != nullptr) {
		nodes.push_front(node);
	}
}
