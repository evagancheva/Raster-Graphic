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
	CommandExecutor() = default;
	~CommandExecutor() = default;

	void add(Comand* c);
	void execute();
	void executeAll();
	void undo();

	CommandExecutor(const CommandExecutor&) = delete;
	CommandExecutor& operator=(const CommandExecutor&) = delete;
};

