#pragma once

extern "C++" int yylex();

enum ParserTokens {
	// Типы
	PT_Void,
	PT_String,
	PT_Integer,
	PT_Boolean,
	PT_Number,
	// Части для классов
	PT_Class,
	PT_Static,
	PT_Public,
	PT_Private,
	//Точка входа
	PT_Main,
	// Скобки 
	PT_LeftRoundBracket,
	PT_RightRoundBracket,
	PT_LeftSquareBracket,
	PT_RightSquareBracket,
	PT_LeftBrace,
	PT_RightBrace,
	// Принт
	PT_Print,
	//Условные операторы
	PT_If,
	PT_While,
	// Что-то
	PT_Length,
	//Логические константы
	PT_True,
	PT_False,
	// Ключевые слова
	PT_This,
	PT_New,
	// Логические операции
	PT_Negation,
	PT_And,
	PT_Or,
	// Сравнения
	PT_More,
	PT_Less,
	// Арифмметические операции
	PT_Plus,
	PT_Minus,
	PT_Multiplication,
	PT_Division,
	PT_IntegerDivision,
	PT_Equal,
	// Точка с запятой
	PT_Semicolon,
	// Переменная
	PT_ID
};