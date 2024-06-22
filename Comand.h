#pragma once
#include"Vector.hpp"
#include "Polymorphic_Ptr.hpp"
#include "Image.h"

class Comand
{
protected:
	Vector<Polymorphic_Ptr<Image>> &data;
public:
	Comand(Vector<Polymorphic_Ptr<Image>>& data) : data(data) {}

	virtual void execute() = 0;
	virtual void undo() = 0;

	virtual ~Comand() = default;
	virtual Comand* clone() const = 0;
};

