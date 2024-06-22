#pragma once
#include"Comand.h"
class RotateRightComand :public Comand
{

	Vector<Polymorphic_Ptr<Image>>* snapshot = nullptr;

public:
	class RotateRightComand(Vector<Polymorphic_Ptr<Image>>& data);
	void execute() override;

	void undo() override;

	Comand* clone() const override;
	~RotateRightComand();
};

