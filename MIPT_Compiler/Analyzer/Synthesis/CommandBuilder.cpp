#include <Synthesis/CommandBuilder.h>
#include <Synthesis/AsmCommand.h>
#include <Synthesis/Commands.h>
#include <string>
#include <cassert>

int CAsmCommand::registerCounter = 0;

namespace Synthesis {
	
CCommandBuilder::CCommandBuilder()
{
	tempToRegister["$fp"] = "EBP";
}

void CCommandBuilder::visit(const INode * node)
{
	assert(false);
}

void CCommandBuilder::visit(const ICommand * node)
{
	assert(false);
}

void CCommandBuilder::visit(const IExpression * node)
{
	assert(false);
}

void CCommandBuilder::visit(const CExpStatementCommand* node) 
{
	node->Expression()->Accept(this);
}

void CCommandBuilder::visit(const CConditionalJumpCommand* node)
{
	const IExpression* left = node->LeftPart();
	const IExpression* right = node->RightPart();

	left->Accept(this);
	std::string leftRegister = lastRegisterValue;
	right->Accept(this);
	std::string rightRegister = lastRegisterValue;

	auto cmp = node->Cmp();
	std::string ret;
	if (cmp == IR::TLogicOperatorType::LOT_EQ) {
		ret = "JE";
	} else if (cmp == IR::TLogicOperatorType::LOT_NE) {
		ret = "JNE";
	} else if (cmp == IR::TLogicOperatorType::LOT_LT) {
		ret = "JL";
	} else if (cmp == IR::TLogicOperatorType::LOT_GT) {
		ret = "JG";
	} else {
		assert(false);
	}

	commands.push_back(CAsmCommand(ret + " " + node->PositiveLabelName(), { leftRegister, rightRegister }));
}

void CCommandBuilder::visit(const CJumpCommand* node) 
{
	commands.push_back(CAsmCommand("JMP " + node->LabelName(), {}));
}

void CCommandBuilder::visit(const CCallFunctionCommand* node) 
{
	const std::vector<const IExpression*>& arguments = node->Arguments();

	for (int i = 0; i < arguments.size(); i++) {
		arguments[i]->Accept(this);
		commands.push_back(CAsmCommand("PUSH", { lastRegisterValue }));
	}

	commands.push_back(CAsmCommand("CALL " + node->Function(), {}));
}

void CCommandBuilder::visit(const CLabelDeclarationCommand* node)
{
	commands.push_back(CAsmCommand(node->Name() + ":", {}));
}

void CCommandBuilder::visit(const CMoveRegisterCommand* node) 
{
	const IExpression* source = node->Source();
	const IExpression* destination = node->Destination();

	source->Accept(this);
	std::string sourceRegister = lastRegisterValue;
	destination->Accept(this);
	std::string destinationRegister = lastRegisterValue;

	commands.push_back(CAsmCommand("MOV " + destinationRegister + "," + sourceRegister,
		{ sourceRegister, destinationRegister }));
}

void CCommandBuilder::visit(const CTempExpression* node) 
{
	std::string tempValue = node->Name();

	auto pos = tempToRegister.find(tempValue);
	if (pos == tempToRegister.end()) {
		tempToRegister[tempValue] = CAsmCommand::NewRegister();
	}

	lastRegisterValue = tempToRegister[tempValue];
}

void CCommandBuilder::visit(const CAddCommand* node)
{
	const IExpression* leftOperand = node->LeftOperand();
	const IExpression* rightOperand = node->RightOperand();

	leftOperand->Accept(this);
	std::string leftRegister = lastRegisterValue;
	rightOperand->Accept(this);
	std::string rightRegister = lastRegisterValue;

	std::string resultRegister = CAsmCommand::NewRegister();

	commands.push_back(CAsmCommand("MOV " + resultRegister + "," + leftRegister,
		{ leftRegister, resultRegister }));
	commands.push_back(CAsmCommand("ADD " + resultRegister + "," + rightRegister,
		{ resultRegister, rightRegister }));

	lastRegisterValue = resultRegister;
}

void CCommandBuilder::visit(const CAddConstCommand* node) 
{
	const IExpression* expression = node->Expression();
	const int constant = node->Constant();

	expression->Accept(this);
	std::string expressionRegister = lastRegisterValue;

	std::string resultRegister = CAsmCommand::NewRegister();

	commands.push_back(CAsmCommand("MOV " + resultRegister + "," + expressionRegister,
		{ expressionRegister, resultRegister }));
	commands.push_back(CAsmCommand("ADD " + resultRegister + "," + std::to_string(constant),
		{ resultRegister }));

	lastRegisterValue = resultRegister;
}

void CCommandBuilder::visit(const CSubCommand* node)
{
	const IExpression* leftOperand = node->LeftOperand();
	const IExpression* rightOperand = node->RightOperand();

	leftOperand->Accept(this);
	std::string leftRegister = lastRegisterValue;
	rightOperand->Accept(this);
	std::string rightRegister = lastRegisterValue;

	std::string resultRegister = CAsmCommand::NewRegister();

	commands.push_back(CAsmCommand("MOV " + resultRegister + "," + leftRegister,
		{ leftRegister, resultRegister }));
	commands.push_back(CAsmCommand("SUB " + resultRegister + "," + rightRegister,
		{ resultRegister, rightRegister }));

	lastRegisterValue = resultRegister;
}

void CCommandBuilder::visit(const CSubConstCommand* node)
{
	const IExpression* expression = node->Expression();
	const int constant = node->Constant();

	expression->Accept(this);
	std::string expressionRegister = lastRegisterValue;

	std::string resultRegister = CAsmCommand::NewRegister();

	commands.push_back(CAsmCommand("MOV " + resultRegister + "," + expressionRegister,
		{ expressionRegister, resultRegister }));
	commands.push_back(CAsmCommand("SUB " + resultRegister + "," + std::to_string(constant),
		{ resultRegister }));

	lastRegisterValue = resultRegister;
}

void CCommandBuilder::visit(const CMultCommand* node) {
	const IExpression* leftOperand = node->LeftOperand();
	const IExpression* rightOperand = node->RightOperand();

	leftOperand->Accept(this);
	std::string leftRegister = lastRegisterValue;
	rightOperand->Accept(this);
	std::string rightRegister = lastRegisterValue;

	std::string resultRegister = CAsmCommand::NewRegister();

	commands.push_back(CAsmCommand("MOV AL," + leftRegister, { leftRegister }));
	commands.push_back(CAsmCommand("DIV " + rightRegister, { rightRegister }));
	commands.push_back(CAsmCommand("MOV " + resultRegister + ",AX", { resultRegister }));

	lastRegisterValue = resultRegister;
}

void CCommandBuilder::visit(const CDivCommand* node) {
	const IExpression* leftOperand = node->LeftOperand();
	const IExpression* rightOperand = node->RightOperand();

	leftOperand->Accept(this);
	std::string leftRegister = lastRegisterValue;
	rightOperand->Accept(this);
	std::string rightRegister = lastRegisterValue;

	std::string resultRegister = CAsmCommand::NewRegister();

	commands.push_back(CAsmCommand("MOV AX," + leftRegister, { leftRegister }));
	commands.push_back(CAsmCommand("DIV " + rightRegister, { rightRegister }));
	commands.push_back(CAsmCommand("MOV " + resultRegister + ",AL", { resultRegister }));

	lastRegisterValue = resultRegister;
}

void CCommandBuilder::visit(const CNullExpression* node) {
	std::string reg = CAsmCommand::NewRegister();

	commands.push_back(CAsmCommand("MOV " + reg + ",0", { reg }));

	lastRegisterValue = reg;
}

void CCommandBuilder::visit(const CLoadCommand* node) {
	const int offset = node->Offset();
	const IExpression* expr = node->Source();

	expr->Accept(this);
	std::string lastRegister = lastRegisterValue;

	std::string addressRegister = CAsmCommand::NewRegister();
	commands.push_back(CAsmCommand("MOV " + addressRegister + "," + lastRegister, { addressRegister, lastRegister }));
	commands.push_back(CAsmCommand("ADD " + addressRegister + "," + std::to_string(offset), { addressRegister }));

	std::string targetRegister = lastRegisterValue;

	commands.push_back(CAsmCommand("MOV " + targetRegister + "," + "[" + addressRegister + "]", { targetRegister, addressRegister }));
	lastRegisterValue = targetRegister;
}

void CCommandBuilder::visit(const CStoreCommand* node) {
	const int offset = node->Offset();
	const IExpression* source = node->Source();
	const IExpression* destination = node->Destination();


	destination->Accept(this);
	std::string destinationRegister = lastRegisterValue;
	source->Accept(this);
	std::string sourceRegister = lastRegisterValue;

	std::string addressRegister = CAsmCommand::NewRegister();
	commands.push_back(CAsmCommand("MOV " + addressRegister + "," + destinationRegister, { addressRegister, destinationRegister }));
	commands.push_back(CAsmCommand("ADD " + addressRegister + "," + std::to_string(offset), { addressRegister }));

	commands.push_back(CAsmCommand("MOV [" + destinationRegister + "]," + sourceRegister, { destinationRegister, sourceRegister }));
}

}