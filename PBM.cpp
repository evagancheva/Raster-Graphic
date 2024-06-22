#include "PBM.h"
PBM::PBM(const char* fileName) : Image(fileName)
{

}

PBM::PBM(const char* fileName, size_t rows, const std::size_t colls)
	: Image(fileName, rows, colls) {}

PBM::PBM(const PBM& other)
	: Image(other) {}

void PBM::load(const char* fileName)
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

	magicNumber = buff;
	colls = _colls;
	rows = _rows;
	colorMax = 1;

	data.clear();

	int num;
	for (int i = 0; i < (colls * rows); i++) {
		ifs >> num;
		data.pushBack(num);
	}
	ifs.close();

}

int PBM::getValueAtPosition(int row, int coll) {
	return data[(row * colls) + coll];
}
void PBM::setValueAtPosition(int row, int coll, int value) {
	this->data[(row * colls) + coll] = value;
}

void PBM::save()
{
	std::ofstream save(filename.c_str(), std::ios::out);
	save << magicNumber << std::endl;
	save << colls << " " << rows << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			int value = getValueAtPosition(i, j);
			save << value << " ";
		}
		save << std::endl;
	}

}

void PBM::saveAs(const char* filename)
{
	std::ofstream save(filename, std::ios::out);
	save << magicNumber << std::endl;
	save << colls << " " << rows << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			int value = getValueAtPosition(i, j);
			save << value << " ";
		}
		save << std::endl;
	}
}

void PBM::makeMonochrome()
{
	return;
}

void PBM::makeNegative()
{
	for (int i = 0; i < rows * colls; i++) {
		int temp = data[i];
		data[i] = 1 - temp;
	}
}

void PBM::grayscale()
{
	return;
}
void PBM::makeHorizontalCollage(const char* imageOne, const char* imageTwo, const char* collageName) {
	filename = collageName;

	std::ifstream ifs1(imageOne, std::ios::in);
	if (!ifs1.is_open()) {
		throw std::runtime_error("fail to open fail");
	}
	std::ifstream ifs2(imageTwo, std::ios::in);
	if (!ifs2.is_open()) {
		throw std::runtime_error("fail to open fail");
	}
	char buff1[3];
	char buff2[3];
	int colls1, rows1, colorMax1, colls2, rows2, colorMax2;

	ifs1 >> buff1;
	ifs1 >> colls1 >> rows1;
	ifs1 >> colorMax1;

	ifs2 >> buff2;
	ifs2 >> colls2 >> rows2;
	ifs2 >> colorMax2;

	magicNumber = buff1;
	colls = colls1 + colls2;
	if (rows1 > rows2) {
		rows = rows1;
	}
	else {
		rows = rows2;
	}
	colorMax1 = std::max(colorMax1, colorMax2);

	data.clear();

	int num;
	for (int i = 0; i < colls * rows; i++) {
		for (int j = 0; j < colls1; j++) {
			if (rows1 >= i) {
				ifs1 >> num;
				data.pushBack(num);
			}
			else data.pushBack(0);

		}
		for (int j = colls1; j < colls; j++) {
			ifs2 >> num;
			data.pushBack(num);
		}

	}

	ifs1.close();
	ifs2.close();
}
void PBM::makeVerticalCollage(const char* imageOne, const char* imageTwo, const char* collageName) {
	filename = collageName;

	std::ifstream ifs1(imageOne, std::ios::in);
	if (!ifs1.is_open()) {
		throw std::runtime_error("fail to open fail");
	}
	std::ifstream ifs2(imageTwo, std::ios::in);
	if (!ifs2.is_open()) {
		throw std::runtime_error("fail to open fail");
	}
	char buff1[3];
	char buff2[3];
	int colls1, rows1, colorMax1, colls2, rows2, colorMax2;

	ifs1 >> buff1;
	ifs1 >> colls1 >> rows1;
	ifs1 >> colorMax1;

	ifs2 >> buff2;
	ifs2 >> colls2 >> rows2;
	ifs2 >> colorMax2;

	magicNumber = buff1;
	rows = rows1 + rows2;
	if (colls1 > colls2)
		colls = colls1;
	else
		colls = colls2;

	colorMax = colorMax1;

	data.clear();

	int num;
	for (int j = 0; j < colls1 * rows1; j++) {
		ifs1 >> num;
		data.pushBack(num);
	}
	for (int j = colls1 * rows1; j < colls * rows; j++) {
		ifs2 >> num;
		data.pushBack(num);
	}



	ifs1.close();
	ifs2.close();
}
void PBM::rotateLeft() {
	
}
void PBM::rotateRight() {

}



