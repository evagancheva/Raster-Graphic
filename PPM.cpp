#include "PPM.h"
Image* PPM::clone() const
{
	return new PPM(*this);
}
bool PPM::isMonochrome()const
{
	
		for (int i = 0; i < rows * colls; i++) {
			if ((data[i].getR() != 0 && data[i].getG() != 0 && data[i].getB() != 0)
				|| (data[i].getR() != 255 && data[i].getG() != 255 && data[i].getB() != 255)) {
				
				return false;
			}
		}
		
		return true;

}

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

void PPM::makeMonochrome() {
	if (isMonochrome())
		return;
	for (int i = 0; i < colls * rows; i++) {
		if (data[i].getR() != 255 || data[i].getG() != 255 || data[i].getB() != 255) {
			data[i] = Pixel(0, 0, 0);
		}
	}
}
bool PPM::isGrayscaled()const {
	for (int i = 0; i < colls * rows; i++) {
		if (data[i].getR() != data[i].getB() && data[i].getB() != data[i].getG() && data[i].getR() != data[i].getG()) {
			return false;
		}
	}
	return true;
}

PPM::PPM(const char* filename):Image(filename)
{
	load(filename);
}


void PPM::makeNegative()
{
	for (int i = 0; i < colls * rows; i++) {
		data[i].setR( colorMax- data[i].getR());
		data[i].setG(colorMax - data[i].getG());
		data[i].setB(colorMax - data[i].getB());
	}
}

void PPM::grayscale()
{
	if (isGrayscaled())
		return;
	for (int i = 0; i < colls * rows; i++) {
		int r = data[i].getR();
		data[i]=Pixel(r,r,r);
	}
}

Pixel PPM::getValueAtPosition(int row, int coll)const {
	return data[(row * colls) + coll];
}
void PPM::setValueAtPosition(int row, int coll, Pixel& value) {
	this->data[(row * colls) + coll] = value;
}

void PPM::makeHorizontalCollage(const char* imageOne, const char* imageTwo, const char* collageName)
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

	int r, g, b;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < colls1; j++) {
			if (rows1 >= i) {
				ifs1 >> r>>g>>b;
				data.pushBack(Pixel(r,g,b));
			}
			else data.pushBack(Pixel(0, 0, 0));

		}
		for (int j = colls1; j < colls; j++) {
			ifs2 >> r>>g>>b;
			data.pushBack(Pixel(r,g,b));
		}

	}

	ifs1.close();
	ifs2.close();
}

void PPM::makeVerticalCollage(const char* imageOne, const char* imageTwo, const char* collageName)
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

	colorMax = std::max(colorMax1, colorMax2);

	data.clear();

	int r, g, b;
	for (int j = 0; j < colls1 * rows1; j++) {
		ifs1 >> r >> g >> b;
		data.pushBack(Pixel(r, g, b));
	}
	for (int j = colls1 * rows1; j < colls * rows; j++) {
		ifs2 >> r >> g >> b;
		data.pushBack(Pixel(r, g, b));
	}



	ifs1.close();
	ifs2.close();
}


void PPM::rotateRight() {
	
	Vector<Pixel> newData(colls * rows);

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < colls; ++j) {
			newData[j * rows + (rows - i - 1)] = data[i * colls + j];
		}
	}

	std::swap(rows, colls);
	data = std::move(newData);
}

void PPM::rotateLeft() {
	
	Vector<Pixel> newData(colls * rows);

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < colls; ++j) {
			newData[(colls - j - 1) * rows + i] = data[i * colls + j];
		}
	}

	std::swap(rows, colls);
	data = std::move(newData);
}