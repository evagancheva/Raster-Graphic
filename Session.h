#pragma once
#include"Vector.hpp"
#include"Image.h"
#include "Polymorphic_Ptr.hpp"
#include"ComandExecutor.h"
class Session
{
private:
    int session_id;
    Vector<Polymorphic_Ptr<Image>> images;
    CommandExecutor command_executor;

public:
    Session(int id) : session_id(id),command_executor() {}

    void addImage(const Polymorphic_Ptr<Image>& image);
    void loadImage(const MyString& filename);
    void executeCommand(const MyString& command);
    void undo();
    void collage(const MyString& direction, const MyString& image1, const MyString& image2, const MyString& outimage);
    void save();
    void saveAs(const MyString& filename);

    void printInfo() const;
    int getID() const;
};
