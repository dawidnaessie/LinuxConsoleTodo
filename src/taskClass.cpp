
#include "taskClass.hpp"
#include <iostream>
#include <string>
int Task::generateId()
{
    static int n = 0;
    return n++;
}
void Task::printInfo() const
{
    std::cout   << "id: " << id 
                << ", title: " << title
                << ", content:\n" << content;
    std::cout << "\n";
}
Task::Task(const std::string& Title, const std::string& Content) : //initialize the task
id(generateId()), title(Title), content(Content) {}

int Task::getId()
{
    return id;
}

std::string Task::getTitle()
{
    return title;
}

std::string Task::getContent()
{
    return content;
}
Task Task::readTask(std::istream& File)
{
    std::string Title, Content;
    std::string temp;
    if (std::getline(File, temp, ';'))
        Title = temp;
    else Title = "unknown";
    if (std::getline(File, temp, ';'))
        Content = temp;
    else Content = "unknown";
    return Task(Title, Content);
}
void Task::writeTask(std::ostream& File) const
{
    File << title << ";" << content << ";\n";
}

