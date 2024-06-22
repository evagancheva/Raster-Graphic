#include "NegativeComand.h"

NegativeComand::NegativeComand(Vector<Polymorphic_Ptr<Image>>& data) :Comand(data),isExecute(false){}

void NegativeComand::execute()
{
	for (unsigned i = 0; i < data.getSize(); i++)
	{
		data[i]->makeNegative();
	}
	isExecute = true;
}

void NegativeComand::undo()
{
	if (isExecute) {
		for (unsigned i = 0; i < data.getSize(); i++)
		{
			data[i]->makeNegative();
		}
	}
	isExecute = false;
}

Comand* NegativeComand::clone() const
{
	return  new NegativeComand(*this);
}
