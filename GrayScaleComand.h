#pragma once
#include"Comand.h"
class GrayScaleComand:public Comand
{
	Vector<Polymorphic_Ptr<Image>>* snapshot = nullptr;

public:
	GrayScaleComand(Vector<Polymorphic_Ptr<Image>>& data);
	void execute() override;

	void undo() override;

	Comand* clone() const override;
};

