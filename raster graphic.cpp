
#include <iostream>
#include"Pixel.h"
#include"PBM.h"
#include"PGM.h"
#include"PPM.h"

int main()
{
    PPM pic;
    pic.load("1.ppm.txt");
    pic.rotateLeft();
    pic.save();

}
