#include "Pixel.h"

Pixel::Pixel():r(0),g(0),b(0){}

Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b)
{
	setR(r);
	setG(r);
	setB(r);
}

unsigned char Pixel::getR() const
{
	return r;
}
unsigned char Pixel::getG() const
{
	return g;
}
unsigned char Pixel::getB() const
{
	return b;
}

void Pixel::setR(unsigned char r)
{
	if (r < 0 || r>255)
		return;
	this->r = r;
}
void Pixel::setG(unsigned char g)
{
	if (g < 0 || g>255)
		return;
	this->g = g;
}
void Pixel::setB(unsigned char b)
{
	if (b < 0 || b>255)
		return;
	this->b = b;
}
