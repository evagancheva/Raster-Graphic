#pragma once
#include <fstream>
#include "MyString.h"
#include "Vector.hpp"
#include "Image.h"

class PGM : public Image {

	Vector<Vector<unsigned char>> data;

public:
	PGM(void) = default;
	void load(const char* filename) override;

	void save() override;
	void saveAs(const char* filename)override;

	void makeMonochrome() override;
	void makeNegative()override;
	void grayscale()override;


	void makeHorizontalCollage(const char* imageOne, const char* imageTwo, const char* collageName);
	void makeVerticalCollage(const char* imageOne, const char* imageTwo, const char* collageName);

	void rotateLeft() override;
	void rotateRight()override;
};



