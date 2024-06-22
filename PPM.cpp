#include "PPM.h"

void PPM::load(const char* fileName)
{
	this->filename = fileName;
	std::ifstream ifs(fileName, std::ios::in);
	if (!ifs.is_open()) {
		throw std::runtime_error("fail to open fail");
	}

	char buff[3];
	int _colls, _rows;

	ifs >> buff;
	ifs >> _colls >> _rows;
	ifs >> colorMax;

	magicNumber = buff;
	colls = _colls;
	rows = _rows;
	

	data.clear();

	int red, green, blue;
	for (int i = 0; i < (colls * rows); i++) {
		ifs >> red>>green>>blue;
		data.pushBack(Pixel(red,green,blue));
	}
	ifs.close();

}

void PPM::save()
{
	std::ofstream save(filename.c_str(), std::ios::out);
	save << magicNumber << std::endl;
	save << colls << " " << rows << std::endl;
	save << colorMax << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			Pixel value = getValueAtPosition(i, j);
			save << value.getR() << " " << value.getG() << " " << value.getB() << std::endl;
		}
		
	}
}

void PPM::saveAs(const char* filename)
{
	std::ofstream save(filename, std::ios::out);
	save << magicNumber << std::endl;
	save << colls << " " << rows << std::endl;
	save << colorMax << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			Pixel value = getValueAtPosition(i, j);
			save << value.getR() << " " << value.getG() << " " << value.getB() << std::endl;
		}

	}
}

void PPM::makeMonochrome()
{
}

void PPM::makeNegative()
{
}

void PPM::grayscale()
{
}

Pixel PPM::getValueAtPosition(int row, int coll) {
	return data[(row * colls) + coll];
}
void PPM::setValueAtPosition(int row, int coll, Pixel value) {
	this->data[(row * colls) + coll] = value;
}

void PPM::makeHorizontalCollage(const char* imageOne, const char* imageTwo, const char* collageName)
{
}

void PPM::makeVerticalCollage(const char* imageOne, const char* imageTwo, const char* collageName)
{
}

void PPM::rotateLeft()
{
}

void PPM::rotateRight()
{
}
