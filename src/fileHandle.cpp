#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "taskClass.hpp"
#include "fileHandle.hpp"

std::vector<Task> getTasksTxt()
{
    std::vector<Task> tasks;
    std::ifstream File("tasks.txt");
    if (!File.is_open()) {
        std::cerr << "Failed to open tasks.txt\n";
        return {};
    }
    while(File.peek() != EOF)
    {
        if (File.peek() == '\n') 
            {File.get(); continue;}
        tasks.push_back(Task::readTask(File));
    }

    File.close();

    return tasks; 
}

int saveTasksTxt(const std::vector<Task>& tasks)
{
    std::ofstream File("tasks.txt");
    if(!File.is_open()){
        std::cerr << "Failed to open tasks.txt\n";
        return -1;
    }
    for (const auto& task : tasks)
    {
        task.writeTask(File);
    }

    File.close();
   
    return 0;
}

Task makeNewTask()
{
    std::string t,c;

    std::cout << "Enter a new tasks title:\n";
    std::cout << "> ";
    std::getline(std::cin >> std::ws, t);

    std::cout << "Enter a new tasks description:\n";
    std::cout << "> ";
    std::getline(std::cin >> std::ws, c);

    return Task(t,c);
}

