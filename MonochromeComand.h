#pragma once
#include"Comand.h"
class MonochromeComand :public Comand
{
	Vector<Polymorphic_Ptr<Image>>* snapshot = nullptr;

public:
	MonochromeComand(Vector<Polymorphic_Ptr<Image>>& data);
	void execute() override;

	void undo() override;

	Comand* clone() const override;
	~MonochromeComand();
};

