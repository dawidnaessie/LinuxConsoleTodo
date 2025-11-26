#ifndef TASKCLASS_HPP
#define TASKCLASS_HPP
#pragma once

#include <iostream>
#include <string>
#include <chrono>
class Task{
private:

    std::string title;
    std::string content;
    bool done;
    std::chrono::system_clock::time_point deadline;

public:
    Task(const std::string& Title,
        const std::string& Content,
        const bool& Done,
        const std::chrono::system_clock::time_point& Deadline); //initialize the task
    std::string getTitle() const;
    std::string getContent() const;
    bool isDone() const;
    std::chrono::system_clock::time_point getDeadline() const;
    void markDone();
    void printInfo() const;
    static Task readTask(std::istream& File);
    void writeTask(std::ostream& File) const;

    static std::chrono::system_clock::time_point parseDate(const std::string& str);
};

#endif
