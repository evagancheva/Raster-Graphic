#pragma once
#include"Polymorphic_Ptr.hpp"
#include "Image.h"
#include "PBM.h"
#include "PGM.h"
#include "PPM.h"
#include "MyString.h"
#include <fstream>
#include "Vector.hpp"

class ImageFactory {
public:
    Polymorphic_Ptr<Image> loadImage(const char* filename) const;
};
