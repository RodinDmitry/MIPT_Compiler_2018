#pragma once

extern "C++" int yylex();

enum ParserTokens {
	// ����
	PT_Void,
	PT_String,
	PT_Integer,
	PT_Boolean,
	PT_Number,
	// ����� ��� �������
	PT_Class,
	PT_Static,
	PT_Public,
	PT_Private,
	//����� �����
	PT_Main,
	// ������ 
	PT_LeftRoundBracket,
	PT_RightRoundBracket,
	PT_LeftSquareBracket,
	PT_RightSquareBracket,
	PT_LeftBrace,
	PT_RightBrace,
	// �����
	PT_Print,
	//�������� ���������
	PT_If,
	PT_While,
	// ���-��
	PT_Length,
	//���������� ���������
	PT_True,
	PT_False,
	// �������� �����
	PT_This,
	PT_New,
	// ���������� ��������
	PT_Negation,
	PT_And,
	PT_Or,
	// ���������
	PT_More,
	PT_Less,
	// ��������������� ��������
	PT_Plus,
	PT_Minus,
	PT_Multiplication,
	PT_Division,
	PT_IntegerDivision,
	PT_Equal,
	// ����� � �������
	PT_Semicolon,
	// ����������
	PT_ID
};