#pragma once
#include"MyQueue.hpp"
#include"MyStack.hpp"
#include"Vector.hpp"
#include"Polymorphic_Ptr.hpp"
#include"Comand.h"

class CommandExecutor
{
	MyQueue< Polymorphic_Ptr<Comand>> toBeExecuted;
	MyStack< Polymorphic_Ptr<Comand>, 64> history;

public:

	void add(Comand* c);
	void execute();
	void executeAll();
	void undo();

};

