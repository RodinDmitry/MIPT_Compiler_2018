%{
#include <stdio.h>
#include <stdlib.h>
extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char* s);
%}

%union {
	int integerValue;
	bool logicalValue;
	std::strnig stringValue;
}

// ����
%token PT_Void
%token<stringValue> PT_String 
%token<integerValue> PT_Integer PT_Number
%token<logicalValue> PT_Boolean
//���������� ���������
%token<logicalValue> PT_True PT_False
// ����� ��� �������
%token PT_Class PT_Static PT_Public PT_Private
//����� �����
%token PT_Main
// ������ 
%token PT_LeftRoundBracket PT_LeftSquareBracket PT_LeftBrace 
%token PT_RightRoundBracket PT_RightSquareBracket PT_RightBrace
// �����
%token PT_Print
//�������� ���������
%token PT_If PT_While PT_Else
// ���-��
%token PT_Length
// �������� �����
%token PT_This PT_New
// ���������� ��������
%token PT_Negation PT_And PT_Or
// ���������
%token PT_More PT_Less
// ��������������� ��������
%token PT_Plus PT_Minus
%token PT_Multiplication PT_Division PT_IntegerDivision PT_Equal
// ����� � �������
%token PT_Semicolon
// ����������
%token PT_ID

%start calculation

%%

calculation: 
	   | 
;

%%
