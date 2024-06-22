#include "ComandExecutor.h"

void CommandExecutor::add(Comand* c)
{
	toBeExecuted.push(Polymorphic_Ptr<Comand>(c));
}

void CommandExecutor::execute()
{
	if (!toBeExecuted.isEmpty()) {
		Polymorphic_Ptr<Comand> temp = toBeExecuted.peek();
		toBeExecuted.pop();
		temp->execute();
		history.push(std::move(temp));
	}
}

void CommandExecutor::executeAll()
{
	while (!toBeExecuted.isEmpty()) {
		execute();
	}
}

void CommandExecutor::undo()
{
	if (!history.isEmpty()) {
		Polymorphic_Ptr<Comand> temp = history.peek();
		temp->undo();

		history.pop();
	}
}