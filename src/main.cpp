#include <cstdlib>
#include <iostream>
#include <vector>
#include "taskClass.hpp"
#include "fileHandle.hpp"
#include <algorithm>

void deleteTaskById(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to delete.\n";
        return;
    }

    // Display tasks with IDs
    std::cout << "Current tasks:\n";
    for(const auto& task : tasks) {
        task.printInfo();
    }

    int idToDelete;
    std::cout << "Enter the ID of the task to delete: ";
    std::cin >> idToDelete;

    // Remove task with matching ID
    auto it = std::remove_if(tasks.begin(), tasks.end(),
                         [idToDelete](Task& t){ return t.getId() == idToDelete; });

    if (it == tasks.end()) {
        std::cout << "No task found with ID " << idToDelete << ".\n";
    } else {
        tasks.erase(it, tasks.end());
        std::cout << "Task deleted.\n";
        saveTasksTxt(tasks);
    }

} 

void displayTasks(std::vector<Task>& tasks)
{
    
    std::cout << "\n====================\n";
    std::cout << "\n";
    
    if(tasks.empty())
    {
        std::cout << "No current tasks!\n";
        std::cout << "\n====================\n";
        return;
    }

    for(auto& task : tasks)
    {
        std::cout << "| ID: " << task.getId() 
                 << " | title: " << task.getTitle() 
                 << " | content: " << task.getContent() 
                 << " |\n";
    }

    std::cout << "\n====================\n";
}

int main() {
    std::vector<Task> tasks = getTasksTxt(); // load tasks once
    system("clear");
    while(true) {
        std::cout << "\n==Your task manager==\n";
        std::cout << "Options:\n";
        std::cout << "1. Show current tasks\n";
        std::cout << "2. Add new task\n";
        std::cout << "3. Delete task via id\n";
        std::cout << "4. Exit\n";

        int op;
        std::cout << "Enter your option:\n> ";
        std::cin >> op;
        
        system("clear");

        switch(op) {
            case 1:
                displayTasks(tasks);
                break;
            case 2: {
                Task newTask = makeNewTask();
                tasks.push_back(newTask);
                saveTasksTxt(tasks);
                break;
            }
            case 3:
                deleteTaskById(tasks);
                break;
            case 4:
                return 0;
            default:
                std::cout << "There is no such option!\n";
        }
    }

    return 0;
}

