
#include <iostream>
#include"Pixel.h"
#include"PBM.h"
#include"PGM.h"

int main()
{
    PBM pic;
    pic.load("1.pbm.txt");
    pic.makeHorizontalCollage("1.pbm.txt", "2.pbm.txt", "3.pbm.txt");
    pic.save();

}
