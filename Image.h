#pragma once
#include"MyString.h"

class Image
{
protected:
	MyString filename="";
	MyString magicNumber="";
	int rows=0;
	int colls=0;
	unsigned int colorMax=0;

public:
	Image() = default;
	Image(const char* filename) :filename(filename){}
	Image(const char* filename, unsigned int rows , unsigned int colls );
	virtual ~Image() = default;

	virtual void load(const char* filename) = 0;
	
	virtual void save() = 0;
	virtual void saveAs(const char*filename) = 0;

	virtual void makeMonochrome() = 0;
	virtual void makeNegative() = 0;
	virtual void grayscale() = 0;

	virtual void makeHorizontalCollage(const char*, const char*, const char*) = 0;
	virtual void makeVerticalCollage(const char*, const char*, const char*) = 0;
	
	virtual void rotateLeft() = 0;
	virtual void rotateRight() = 0;
};

