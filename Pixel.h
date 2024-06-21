#pragma once
class Pixel
{
	int r=0;
	int g=0;
	int b=0;
public:
    Pixel();
    Pixel(unsigned char r , unsigned char g , unsigned char b );
    unsigned char getR() const;
    unsigned char getG() const;
    unsigned char getB() const;
    void setR(unsigned char r);
    void setG(unsigned char g);
    void setB(unsigned char b);
	
};

