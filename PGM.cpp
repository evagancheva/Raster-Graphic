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
	colorMax = 1;

	data.clear();

	int num;
	for (int i = 0; i < (colls * rows); i++) {
		ifs >> num;
		data.pushBack(num);
	}
	ifs.close();

}
