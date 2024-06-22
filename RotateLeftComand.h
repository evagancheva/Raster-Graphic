#pragma once
#include"Comand.h"
class RotateLeftComand :public Comand
{

	Vector<Polymorphic_Ptr<Image>>* snapshot = nullptr;

public:
	RotateLeftComand(Vector<Polymorphic_Ptr<Image>>& data);
	void execute() override;

	void undo() override;

	Comand* clone() const override;
	~RotateLeftComand();
};

