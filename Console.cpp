#include "Console.h"
#include<iostream>
#include<fstream>
#include <sstream>

bool isPrefix(const char* pattern, const char* text)
{
    while (*text != '\0' && *pattern != '\0')
    {
        if (*text != *pattern)
            return false;
        text++;
        pattern++;
    }
    return *pattern == '\0';
}

void Console::run() {
   char buff[1024]="\0";
    while (strcmp(buff,"exit")!=0) {
        std::cin.getline(buff, 1024, '\n');
        processCommand(MyString(buff));
    }
}

void Console::processCommand(const MyString& command) {
    
    std::stringstream ss (command.c_str());
    char buff[1024];
    ss >> buff;
    if (isPrefix("load",buff)){
        Vector<MyString> filenames;
        while (!ss.eof()) {
            ss >> buff;
            filenames.pushBack(buff);
        }
        loadSession(filenames);
    }
    else if (isPrefix("add", buff)) {
        MyString filename;
        ss >> filename;
        addImage(filename);
    }
    else if (isPrefix("save", buff)) {
        MyString filename;
        ss >> buff;
        if (isPrefix("as", buff)) {
            ss>>filename;
            saveAs(filename);
        }
        else if (isPrefix("all", buff)) {
            saveAll();
        }
        else {
            saveSession();
        }
    }
    else if (isPrefix("undo", buff)) {
        undoCommand();
    }
    else if (isPrefix("session", buff)) {
        ss >> buff;
        if (isPrefix("info", buff)) {
            printSessionInfo();
        }
    }
    else if (isPrefix("switch", buff)) {
        int sesionid;
        ss >> sesionid;
        switchSession(sesionid);
    }
    else if (isPrefix("collage", buff)) {
        MyString direction;
        MyString im1;
        MyString im2;
        MyString outim;
        ss >> direction >> im1 >> im2 >> outim;
        collage(direction, im1, im2, outim);
    }
    else if (isPrefix("grayscale", buff) || isPrefix("monochrome", buff) ||
             isPrefix("negative", buff) || isPrefix("rotate", buff)) 
    {
        executeCommand(command);
    }
}

void Console::loadSession(const Vector<MyString>& filenames) {
    Session newSession(nextSessionID++);
    for (int i = 0; i < filenames.getSize();i++) {
        newSession.loadImage(filenames[i]);
    }
    sessions.pushBack(std::move(newSession));
    currentSessionIndex = sessions.getSize() - 1;
    std::cout << "Session with ID: " << sessions[currentSessionIndex].getID() << " started" << std::endl;
}

void Console::switchSession(int id) {
    for (size_t i = 0; i < sessions.getSize(); ++i) {
        if (sessions[i].getID() == id) {
            currentSessionIndex = i;
            std::cout << "Switched to session with ID: " << id << std::endl;
            return;
        }
    }
    std::cout << "No session with ID: " << id << std::endl;
}

void Console::executeCommand(const MyString& command) {
    if (currentSessionIndex != -1) {
        sessions[currentSessionIndex].executeCommand(command);
    }
    else {
        std::cout << "No active session" << std::endl;
    }
}

void Console::undoCommand() {
    if (currentSessionIndex != -1) {
        sessions[currentSessionIndex].undo();
    }
    else {
        std::cout << "No active session" << std::endl;
    }
}

void Console::addImage(const MyString& filename) {
    if (currentSessionIndex != -1) {
        sessions[currentSessionIndex].loadImage(filename);
        std::cout << "Image " << filename << " added" << std::endl;

    }
    else {
        std::cout << "No active session" << std::endl;
    }
}

void Console::collage(const MyString& direction, const MyString& image1, const MyString& image2, const MyString& outimage) {
    if (currentSessionIndex != -1) {
        sessions[currentSessionIndex].collage(direction, image1, image2, outimage);
    }
    else {
        std::cout << "No active session" << std::endl;
    }
}

void Console::saveSession() {
    if (currentSessionIndex != -1) {
        sessions[currentSessionIndex].save();
        std::cout << "Save done" << std::endl;
    }
    else {
        std::cout << "No active session" << std::endl;
    }
}

void Console::saveAs(const MyString& filename) {
    if (currentSessionIndex != -1) {
        sessions[currentSessionIndex].saveAs(filename.c_str());
        std::cout << "Save done" << std::endl;
    }
    else {
        std::cout << "No active session" << std::endl;
    }
}

void Console::saveAll()
{
    for (size_t i = 0; i < sessions.getSize(); ++i) {
        sessions[i].save();
       std::cout << "All active sessions saved"  << std::endl;
        
    }

    
}

void Console::printSessionInfo() const {
    if (currentSessionIndex != -1) {
        sessions[currentSessionIndex].printInfo();
    }
    else {
        std::cout << "No active session" << std::endl;
    }
}