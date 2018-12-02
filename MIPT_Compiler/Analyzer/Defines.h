#pragma once
#include <PrettyPrinter.h>
#include <StackBuilder.h>
#include <MalformedProgramChecker.h>
#include <ErrorTable.h>
#include <string>

extern int yylex();
extern int yyparse(ITree**);
extern FILE* yyin;

std::vector<std::string> goodSamples{ "BinarySearch.java", "BinaryTree.java", "BubbleSort.java",
	"Factorial.java", "LinearSearch.java", "LinkedList.java", "QuickSort.java", "TreeVisitor.java"  };

std::vector<std::string> badSamples{ "LC_1.java", "TC_1a.java", "TC_2a.java", "TC_3a.java", "TC_3b.java",
	"TC_4a.java", "TC_4b.java", "TC_5a.java", "TC_6a.java", "TC_7b.java", "TC_7c.java", "TC_8a.java", "TC_9a.java", "TC_9a_2.java",
	"TC_11a.java", "TC_12b.java", "TC_13a.java", "TC_13b.java", "TC_13c.java", "TC_13d(optional).java", "TC_bonus_1.java", };
