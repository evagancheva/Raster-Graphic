#pragma once
#include"Comand.h"
class NegativeComand : public Comand
{
	bool isExecute=0;

public:
	NegativeComand(Vector<Polymorphic_Ptr<Image>>& data);

	void execute() override;
	void undo() override;
	Comand* clone()const override;

};

