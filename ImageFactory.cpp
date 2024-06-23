#include "ImageFactory.h"

Polymorphic_Ptr<Image> ImageFactory::loadImage(const char* filename) const {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::invalid_argument("Failed to open file");
    }
    MyString buff;
    file >> buff;

    if (buff == "P1" || buff == "P4") {
        return new PBM(filename);
    }
    else if (buff == "P2" || buff == "P5") {
        return new PGM(filename);
    }
    else if (buff == "P3" || buff == "P6") {
        return new PPM(filename);
    }
    else {
        throw std::invalid_argument("Unsupported file format");
    }
}