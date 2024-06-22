#include "PGM.h"

void PGM::load(const char* fileName)
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
	ifs >> colorMax;

	data.clear();

	int num;
	for (int i = 0; i < rows; i++) {
		Vector<unsigned char> temp;
		for (int i = 0; i < colls; i++) {
			ifs >> num;
			temp.pushBack(num);
		}
		data.pushBack(temp);
	}
	ifs.close();

}

void PGM::save()
{
	std::ofstream save(filename.c_str(), std::ios::out);
	save << magicNumber << std::endl;
	save << colls << " " << rows << std::endl;
	save << colorMax << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			int value = data[i][j];
			save << value << " ";
		}
		save << std::endl;
	}
}

void PGM::saveAs(const char* fileName)
{
	std::ofstream save(fileName, std::ios::out);
	save << magicNumber << std::endl;
	save << colls << " " << rows << std::endl;
	save << colorMax << std::endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			int value = data[i][j];
			save << value << " ";
		}
		save << std::endl;
	}
}

void PGM::makeMonochrome()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colls; j++) {
			if (data[i][j] == 0) {
				data[i][j] = 0;
			}
			else
				data[i][j] = colorMax;
		}
	}
}

void PGM::makeNegative()
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < colls; j++) {

			data[i][j] = colorMax - data[i][j];
		}
	}
}

void PGM::grayscale()
{
	return;
}

void PGM::makeHorizontalCollage(const char* imageOne, const char* imageTwo, const char* collageName)
{
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
	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < colls1; j++) {
			if (rows1 >= i) {
				ifs1 >> num;
				data[i].pushBack(num);
			}
			else data[i].pushBack(0);

		}
		for (int j = colls1; j < colls; j++) {
			ifs2 >> num;
			data[i].pushBack(num);
		}

	}

	ifs1.close();
	ifs2.close();
}

void PGM::makeVerticalCollage(const char* imageOne, const char* imageTwo, const char* collageName)
{
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
	for (int i = 0; i < rows1; i++) {
		Vector<unsigned char> temp;
		for (int j = 0; j < colls; j++) {
			if (j <= colls1) {
				ifs1 >> num;
				temp.pushBack(num);
			}
			else
				temp.pushBack(0);
		}
		data.pushBack(temp);
	}
	
	for (int i = rows1; i < rows; i++) {
		Vector<unsigned char> temp;
		for (int j = 0; j < colls; j++) {
			if (j <= colls2) {
				ifs2 >> num;
				temp.pushBack(num);
			}
			else
				temp.pushBack(0);
		}
		data.pushBack(temp);
	}
	
	ifs1.close();
	ifs2.close();
}

void PGM::rotateLeft()
{
	Vector<Vector<unsigned char>> temp;
	for (int i = 0; i < colls; i++) {
		Vector<unsigned char> temp2(rows);
		temp.pushBack(temp2);
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			temp[j][i] = data[i][j];
		}
		
	}
	std::swap(rows, colls);

	data = temp;
}

void PGM::rotateRight()
{
}
