#include "Pixel.h"

Pixel::Pixel():r(0),g(0),b(0){}

Pixel::Pixel(int r, int g, int b)
{
	setR(r);
	setG(g);
	setB(b);
}

int Pixel::getR() const
{
	return r;
}
int Pixel::getG() const
{
	return g;
}
int Pixel::getB() const
{
	return b;
}

void Pixel::setR(int r)
{
	if (r < 0 || r>255)
		return;
	this->r = r;
}
void Pixel::setG(int g)
{
	if (g < 0 || g>255)
		return;
	this->g = g;
}
void Pixel::setB(int b)
{
	if (b < 0 || b>255)
		return;
	this->b = b;
}
