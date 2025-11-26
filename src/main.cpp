#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include "taskClass.hpp"
#include "fileHandle.hpp"

void deleteTaskByNum(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to delete.\n";
        return;
    }

    // Display tasks with IDs
    std::cout << "Current tasks:\n";
    printTasksList(tasks);

    size_t num;
    std::cout << "Enter the index of the task to delete: ";
    std::cin >> num;
    if(num >= tasks.size())
    {
        std::cout << "No such index!\n";
        return;
    }
    tasks.erase(tasks.begin() + num);
    std::cout << "Task removed!\n";

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
        std::time_t t = std::chrono::system_clock::to_time_t(task.getDeadline());
        std::tm* tm = std::localtime(&t);

        char buffer[20];
        std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", tm);

        std::cout 
            << " | title: " << task.getTitle() 
            << " | content: " << task.getContent() 
            << " | status: " << (task.isDone() ? "finished" : "unfinished")
            << " | deadline: " << buffer
            << " |\n";
    }

    std::cout << "\n====================\n";
}

void taskMarkAsDone(std::vector<Task>& tasks)
{
    size_t num;
    printTasksList(tasks);
    std::cout << "Type in the index of the task you wish to tag as finished:\n";
    std::cout << "> ";
    std::cin >> num;
    if(num > tasks.size()){ std::cout << "No such index\n"; return; }
    tasks[num].markDone();
    std::cout << " Marked as done!\n";

}

int main() {
    std::vector<Task> tasks = getTasksTxt(); // load tasks once
    system("clear");
    while(true) {
        std::cout << "\n==Your task manager==\n";
        std::cout << "Options:\n";
        std::cout << "1. Show current tasks\n";
        std::cout << "2. Add new task\n";
        std::cout << "3. Delete task via index\n";
        std::cout << "4. Mark a task as finished\n";
        std::cout << "5. Exit\n";

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
                deleteTaskByNum(tasks);
                saveTasksTxt(tasks);
                break;
            case 4:
                taskMarkAsDone(tasks);
                saveTasksTxt(tasks);
                break;
            case 5:
                return 0;
            default:
                std::cout << "There is no such option!\n";
                return -1;
        }
    }

    return 0;
}

