#ifndef TASKCLASS_HPP
#define TASKCLASS_HPP
#pragma once

#include <iostream>
#include <string>
class Task{
private:
    int id;
    std::string title;
    std::string content;

    static int generateId();
public:
    void printInfo() const;
    Task(const std::string& Title, const std::string& Content); //initialize the task
    int getId();
    std::string getTitle();
    std::string getContent();
    static Task readTask(std::istream& File);
    void writeTask(std::ostream& File) const;
};

#endif
