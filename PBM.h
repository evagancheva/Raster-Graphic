#pragma once
#include <iostream>
#include <fstream>
#include "MyString.h"
#include "Vector.hpp"
#include "Image.h"

class PBM : public Image {
	MyVector<bool> data;

public:
	PBM() = default;
	PBM(const char* filename, const char* magicNumber, unsigned int rows, unsigned int cols, unsigned int colorMax);

	void load(const char* filename) override;

	void save() override;
	void saveAs(const char* filename)override;

	void makeMonochrome() override;
	void makeNegative()override;
	void grayscale()override;

	int getValueAtPosition(int row, int column);
	void setValueAtPosition(int row, int column, int value);

	void makeHorizontalCollage(const char*, const char*, const char*);
	//void makeVerticalCollage(const char*, const char*, const char*);
};

