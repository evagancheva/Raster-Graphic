#include "PBM.h"
PBM::PBM(const char* filename, const char* magicNumber, unsigned int rows, 
    unsigned int cols, unsigned int colorMax)
    : Image(filename, magicNumber, rows, cols, colorMax), data(rows* cols) {}

void PBM::load(const char* fileName)
{
	this->filename = fileName;
	std::ifstream ifs(fileName, std::ios::in);
	if (!ifs.is_open()) {
		throw std::runtime_error("fail to open fail");
	}

	char buff[3];
	int _colls,_rows;

	ifs >> buff;
	ifs >> _colls >> _rows;

	magicNumber = buff;
	colls = _colls;
	rows = _rows;
	colorMax=1;

	data.clear();

	int num;
	for (int i = 0; i < colls * rows; i++) {
		ifs >> num;
		data.push_back(num);
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
	for (int i = 0; i < colls; i++) {
		for (int j = 0; j < rows; j++) {
			int value = getValueAtPosition(j, i);
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
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls; j++) {
			setValueAtPosition(j, i, 1 - getValueAtPosition(j, i));
		}
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
	ifs1>> colorMax1;

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
	for (int i = 0; i <  rows; i++) {
		for (int j = 0; j < colls1; j++) {
			if (rows1 <= i) {
				ifs1 >> num;
				data.push_back(num);
			}
			else data.push_back(0);

		}
		for (int j = 0; j < colls2; j++) {
			if (rows2 <= i) {
				ifs2 >> num;
				data.push_back(num);
			}
			else data.push_back(0);

		}

	}

	ifs1.close();
	ifs2.close();
}

/*void PBM::makeVerticalCollage(const char* imageOne, const char* imageTwo, const char* collageName) {
	imageName = new char[strlen(collageName) + 1];
	for (int i = 0; i < strlen(collageName) + 1; i++) {
		imageName[i] = collageName[i];
	}

	ifstream loadImageOne(imageOne, ios::in);
	if (loadImageOne.fail()) { cout << "Error"; return; }
	ifstream loadImageTwo(imageTwo, ios::in);
	if (loadImageTwo.fail()) { cout << "Error"; return; }

	string _magicNumOne, _magicNumTwo;
	int _widthOne, _heightOne, _rangeOne, _widthTwo, _heightTwo, _rangeTwo;

	loadImageOne >> _magicNumOne;
	loadImageOne >> _widthOne >> _heightOne;
	loadImageOne >> _rangeOne;

	loadImageTwo >> _magicNumTwo;
	loadImageTwo >> _widthTwo >> _heightTwo;
	loadImageTwo >> _rangeTwo;

	magicNum = _magicNumOne;
	height = _heightOne + _heightTwo;
	if (_widthOne > _widthTwo) width = _widthOne;
	else width = _widthTwo;
	range = _rangeOne;

	value.clear();

	int num;
	for (int j = 0; j < _widthOne * _heightOne; j++) {
		loadImageOne >> num;
		value.push_back(num);
	}
	for (int j = _widthOne * _heightOne; j < width * height; j++) {
		loadImageTwo >> num;
		value.push_back(num);
	}



	loadImageOne.close();
	loadImageTwo.close();
}*/



