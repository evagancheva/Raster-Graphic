
#include <iostream>
#include"Pixel.h"
#include"PBM.h"
#include"PGM.h"
#include"PPM.h"
#include"Session.h"
#include "Console.h"

int main()
{
    try {
        Console con;
        con.run();
    }
    catch (std::invalid_argument) {
        std::cout << "Invalid argument (probably invalid file format)";
    }
    catch (...) {
        std::cout << "Something go wrong";
    }
    
}
