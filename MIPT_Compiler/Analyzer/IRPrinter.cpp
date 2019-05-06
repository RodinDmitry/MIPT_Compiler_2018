#include <IRPrinter.h>
#include <IR/IRExpression.h>
#include <cassert>

void IR::CIRPrinterVisitor::PrintTree(const ITree* root)
{
	root->Accept(this);
}

IR::CIRPrinterVisitor::CIRPrinterVisitor(const std::string & name)
{
	output.open(name, std::ofstream::out);
	output << "strict graph {" << std::endl;
}

void IR::CIRPrinterVisitor::close()
{
	output << "}" << std::endl;
	output.flush();
}

void IR::CIRPrinterVisitor::visit(const ITree* node)
{
	assert(false);
}

void IR::CIRPrinterVisitor::visit(const IExpression* node)
{
	assert(false);
}

void IR::CIRPrinterVisitor::visit(const CExpressionList* node)
{
	std::string name = labelNode("ExpressionList","");
	for (int i = 0; i < node->Get().size(); ++i) {
		visitIfNotNull(node->Get()[i].get(), name);
	}
	nodes.push_front(name);
}

void IR::CIRPrinterVisitor::visit(const CConstExpression* node)
{
	std::string name = labelNode("Const_" ,std::to_string(node->Get()));
	nodes.push_front(name);
}

void IR::CIRPrinterVisitor::visit(const CNameExpression* node)
{
	std::string name = labelNode("Name_" ,node->Get().GetLabel());
	nodes.push_front(name);
}

void IR::CIRPrinterVisitor::visit(const CTempExpression* node)
{
	std::string name = labelNode("Temp_",node->Temporary().Get());
	nodes.push_front(name);
}

void IR::CIRPrinterVisitor::visit(const CBinaryExpression* node)
{
	std::string name = labelNode("BINOP_",operatorName(node->Operation()));
	visitIfNotNull(node->LeftOperand(), name);
	visitIfNotNull(node->RightOperand(), name);
	nodes.push_front(name);
}

void IR::CIRPrinterVisitor::visit(const CMemExpression* node)
{
	std::string name = labelNode("Mem","");
	visitIfNotNull(node->Get(), name);
	nodes.push_front(name);
}

void IR::CIRPrinterVisitor::visit(const CCallExpression* node)
{
	std::string name = labelNode("Call","");
	visitIfNotNull(node->Arguments(), name);
	visitIfNotNull(node->Function(), name);
	nodes.push_front(name);
}

void IR::CIRPrinterVisitor::visit(const CEseqExpression* node)
{
	std::string name = labelNode("ESEQ","");
	visitIfNotNull(node->Expression().get(), name);
	visitIfNotNull(node->Statement().get(), name);
	nodes.push_front(name);
}

void IR::CIRPrinterVisitor::visit(const IStatement* node)
{
	assert(false);
}

void IR::CIRPrinterVisitor::visit(const CMoveStatement* node)
{
	std::string name = labelNode("Move","");
	visitIfNotNull(node->Source(), name);
	visitIfNotNull(node->Destination(), name);
	nodes.push_front(name);
}

void IR::CIRPrinterVisitor::visit(const CExpStatement* node)
{
	std::string name = labelNode("ExpStatement","");
	visitIfNotNull(node->Expression(), name);
	nodes.push_front(name);
}

void IR::CIRPrinterVisitor::visit(const CJumpStatement* node)
{
	std::string name = labelNode("Jump_",node->Target().GetLabel());
	nodes.push_front(name);
}

void IR::CIRPrinterVisitor::visit(const CJumpConditionalStatement* node)
{
	std::string name = labelNode("CJump_", node->TrueLabel().GetLabel() + "_" 
		+ node->FalseLabel().GetLabel() + "_" + operationName(node->Operation()));
	visitIfNotNull(node->Left(), name);
	visitIfNotNull(node->Right(), name);
	nodes.push_front(name);
}

void IR::CIRPrinterVisitor::visit(const CSeqStatement* node)
{
	std::string name = labelNode("SEQ","");
	visitIfNotNull(node->LeftStatement(), name);
	visitIfNotNull(node->RightStatement(), name);
	nodes.push_front(name);
}

void IR::CIRPrinterVisitor::visit(const CLabelStatement* node)
{
	std::string name = labelNode("Label_",node->Label().GetLabel());
	nodes.push_front(name);
}

void IR::CIRPrinterVisitor::visit(const CStatementList* node)
{
	std::string name = labelNode("StatementList", "");
	for (int i = 0; i < node->Get().size(); ++i) {
		visitIfNotNull(node->Get()[i].get(), name);
	}
	nodes.push_front(name);
}

int IR::CIRPrinterVisitor::lastId = 0;

void IR::CIRPrinterVisitor::visitIfNotNull(const ITree* node, const std::string& currentNode)
{
	if (node != nullptr) {
		node->Accept(this);
		output << currentNode << " -- " << nodes.front() << std::endl;
		nodes.pop_front();
	}
}

std::string IR::CIRPrinterVisitor::labelNode(const std::string& name, const std::string& adding)
{
	std::string nodeName = name + std::to_string(lastId++);
	output << nodeName << " [ label = \"" << name+adding << "\"]" << std::endl;
	return nodeName;
}

std::string IR::CIRPrinterVisitor::operationName(TLogicOperatorType type)
{
	switch (type)
	{
	case IR::TLogicOperatorType::LOT_EQ:
		return "==";
	case IR::TLogicOperatorType::LOT_NE:
		return "!=";
	case IR::TLogicOperatorType::LOT_LT:
		return "<";
	case IR::TLogicOperatorType::LOT_GT:
		return ">";
	default:
		break;
	}
	return "";
}

std::string IR::CIRPrinterVisitor::operatorName(TOperator type)
{
	switch (type)
	{
	case IR::O_Plus:
		return "+";
	case IR::O_Minus:
		return "-";
	case IR::O_Division:
		return "/";
	case IR::O_IntegerDivision:
		return "%";
	case IR::O_And:
		return "&&";
	case IR::O_Or:
		return "||";
	case IR::O_Multiplication:
		return "*";
	case IR::O_Less:
		return "<";
	case IR::O_More:
		return ">";
	default:
		break;
	}
	return "";
}
