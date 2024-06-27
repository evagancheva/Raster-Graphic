#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include "MyString.h"
#include "Vector.hpp"
#include "Image.h"
#include"Pixel.h"
class PPM:public Image
{
	Vector<Pixel> data;
	bool isMonochrome()const;
	bool isGrayscaled() const;
public:
	PPM(const char* filename);
	PPM() = default;
	Image* clone() const;
	void load(const char* filename) override;

	void save() override;
	void saveAs(const char* filename)override;

	void makeMonochrome() override;
	void makeNegative()override;
	void grayscale()override;

	Pixel getValueAtPosition(int row, int column)const;
	void setValueAtPosition(int row, int column, Pixel& value);

	void makeHorizontalCollage(const char* imageOne, const char* imageTwo, const char* collageName);
	void makeVerticalCollage(const char* imageOne, const char* imageTwo, const char* collageName);

	void rotateLeft() override;
	void rotateRight()override;
};

