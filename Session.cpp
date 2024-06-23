#include "Session.h"
#include "GrayScaleComand.h"
#include "MonochromeComand.h"
#include "NegativeComand.h"
#include "RotateLeftComand.h"
#include "RotateRightComand.h"
#include"ImageFactory.h"
#include <iostream>

Session::Session(int id) : session_id(id) {}

int Session::getID() const {
    return session_id;
}

void Session::addImage(const Polymorphic_Ptr<Image>& image) {
    images.pushBack(image);
}

void Session::loadImage(const MyString& filename) {
    
    ImageFactory factory;
    Polymorphic_Ptr<Image> img(factory.loadImage(filename.c_str()));
    images.pushBack(std::move(img));
}

void Session::executeCommand(const MyString& command) {
    if (command == "grayscale") {
        command_executor.add(new GrayScaleComand(images));
    }
    else if (command == "monochrome") {
        command_executor.add(new MonochromeComand(images));
    }
    else if (command == "negative") {
        command_executor.add(new NegativeComand(images));
    }
    else if (command == "rotate left") {
        command_executor.add(new RotateLeftComand(images));
    }
    else if (command == "rotate right") {
        command_executor.add(new RotateRightComand(images));
    }
   // command_executor.execute();
}

void Session::undo() {
    command_executor.undo();
}

void Session::collage(const MyString& direction, const MyString& image1, const MyString& image2, const MyString& outimage) {
    ImageFactory factory;
    Polymorphic_Ptr<Image> img1(factory.loadImage(image1.c_str()));
    Polymorphic_Ptr<Image> img2(factory.loadImage(image2.c_str()));

    if (direction == "horizontal") {
        
        Polymorphic_Ptr<Image> result;
        (*result) .makeHorizontalCollage(image1.c_str(), image2.c_str(), outimage.c_str());
        images.pushBack(result);
    }
    else if (direction == "vertical") {
        Polymorphic_Ptr<Image> result;
        (*result).makeVerticalCollage(image1.c_str(), image2.c_str(), outimage.c_str());
        images.pushBack(result);
    }
}

void Session::save() {
    command_executor.executeAll();
    for (size_t i = 0; i < images.getSize(); ++i) {
        
        images[i]->save();
    }
}

void Session::saveAs(const MyString& filename) {
    command_executor.executeAll();
    for (size_t i = 0; i < images.getSize(); ++i) {
       
        images[i]->saveAs(filename.c_str());
    }
}

void Session::printInfo() const {

    std::cout << "Session ID: " << session_id << "\n";
    std::cout << "Number of images: " << images.getSize() << "\n";
    for (size_t i = 0; i < images.getSize(); ++i) {
        std::cout << "Image " << i + 1 << ": " << (*images[i]).getFileName().c_str() << "\n";
    }
    //print pending transformation
}