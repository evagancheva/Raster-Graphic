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
    helpCommand();
   char buff[1024]="\0";
    while (strcmp(buff,"exit")!=0) {
        std::cin.getline(buff, 1024, '\n');
        processCommand(MyString(buff));
    }
}

void Console::helpCommand() const
{
    std::cout <<"You need to type all comands exactly as in menu with spaces between "<<std::endl<<
                "comand and filename, and also let each new comand be written on a "<<std::endl
              <<"new line with enter All possible commands are : "<<std::endl
              << "load <filename1> <filename2>...----> create new Session"<<std::endl
              << "add <filename> ----> adds image to current session" << std::endl
              << "session info ----> gives information on current session" << std::endl
              << "switch <id> ----> switches to another session" << std::endl
              << "save ----> saves changes in the file" << std::endl
              << "save as <filename> ----> saves changes in new file" << std::endl
              << "save all  ----> saves changes from all sessions" << std::endl
              << "monochrome ----> does monochrome on current session of images" << std::endl
              << "grayscale ----> does grayscale on current session of images" << std::endl
              << "negative ----> does negative on current session of images" << std::endl
              << "rotate left ----> rotates left all images on current session" << std::endl
              << "rotate right ----> rotates right all images on current session" << std::endl
              << "undo ----> undoes last change on current session" << std::endl
              <<"colage <direction(horizontal/vertical)> <filename1> <filename2> <outfileName> ----> make colage of two pictures"<<std::endl
              << "exit ----> end program"<<std::endl;
}

void Console::processCommand(const MyString& command) {
    
    std::stringstream ss (command.c_str());
    char buff[1024];
    ss >> buff;
    if (isPrefix("load", buff)) {
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
            ss >> filename;
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
    else if (isPrefix("help", buff)) {
        helpCommand();
    }
    else if (isPrefix("exit", buff)) {
        return;
    }
    else
        std::cout << "Invalid command" << std::endl;
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