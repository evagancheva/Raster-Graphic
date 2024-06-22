#include "Image.h"

Image::Image(const char* filename, unsigned int rows, unsigned int colls)
	:filename(filename), colls(colls),rows(rows)
{
}

int Image::getRows() const
{
	return rows;
}

int Image::getColls() const
{
	return colls;
}

const MyString& Image::getFileName() const
{
	return filename;
}
