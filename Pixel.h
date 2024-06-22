#pragma once
class Pixel
{
	int r=0;
	int g=0;
	int b=0;
public:
    Pixel();
    Pixel(int  r , int g , int b );
    int getR() const;
    int getG() const;
    int getB() const;
    void setR(int r);
    void setG(int g);
    void setB(int b);
	
};

