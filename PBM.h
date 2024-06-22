#pragma once
#include <iostream>
#include <fstream>
#include "MyString.h"
#include "Vector.hpp"
#include "Image.h"

class PBM : public Image {

	Vector<bool> data;
public:
	PBM(const char* fileName);
	PBM(const char* fileName, const std::size_t newHeight, const std::size_t newWidth);
	PBM(const PBM& other);
	PBM(void) = default;
	void load(const char* filename) override;

	void save() override;
	void saveAs(const char* filename)override;

	void makeMonochrome() override;
	void makeNegative()override;
	void grayscale()override;

	int getValueAtPosition(int row, int column);
	void setValueAtPosition(int row, int column, int value);

	void makeHorizontalCollage(const char* imageOne, const char* imageTwo, const char* collageName);
	void makeVerticalCollage(const char* imageOne, const char* imageTwo, const char* collageName);
	
	void rotateLeft() override;
	void rotateRight()override;
};

