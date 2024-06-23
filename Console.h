#pragma once
#include "Session.h"
#include "Vector.hpp"
#include "MyString.h"
#include<iostream>
class Console {
    Vector<Session> sessions;
    size_t currentSessionIndex = -1;
    int nextSessionID = 1;
   
public:
    void run();
    void processCommand(const MyString& command);
    void loadSession(const Vector<MyString>& filenames);
    void switchSession(int id);
    void executeCommand(const MyString& command);
    void undoCommand();
    void addImage(const MyString& filename);
    void collage(const MyString& direction, const MyString& image1, const MyString& image2, const MyString& outimage);
    void saveSession();
    void saveAs(const MyString& filename);
    void saveAll();
    void printSessionInfo() const;
};
//need to make help function that print all comands
//close Session