#pragma once


#include <Expressions.h>
#include <Argument.h>
#include <Class.h>
#include <Function.h>
#include <Id.h>
#include <MainClass.h>
#include <Modifier.h>
#include <Program.h>
#include <Statement.h>
#include <Tree.h>
#include <Type.h>
#include <Value.h>
#include <Variable.h>


template<class T>
inline T* To(ITree* node)
{
	return static_cast<T*>(node);
}