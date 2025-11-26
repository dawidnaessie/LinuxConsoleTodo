#include "taskClass.hpp"
#include <iomanip>
#include <sstream>

Task::Task(const std::string& Title,
           const std::string& Content,
           const bool& Done,
           const std::chrono::system_clock::time_point& Deadline)
    : title(Title), content(Content), done(Done), deadline(Deadline) {}

std::string Task::getTitle() const { return title; }
std::string Task::getContent() const { return content; }
bool Task::isDone() const { return done; }
std::chrono::system_clock::time_point Task::getDeadline() const { return deadline; }

void Task::markDone() { done = true; }

std::chrono::system_clock::time_point Task::parseDate(const std::string& s)
{
    std::tm tm = {};
    std::istringstream ss(s);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M");
    if (ss.fail()) return std::chrono::system_clock::now();
    return std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

void Task::printInfo() const
{
    std::cout
                << "\n| title: " << title
                << "\n| content: " << content 
                << "\n| status: "
                << (done ? "finished" : "unfinished")
                << "\n==========================\n";

    auto now = std::chrono::system_clock::now();
    auto diff = deadline - now;

    auto h = std::chrono::duration_cast<std::chrono::hours>(diff).count();
    auto m = std::chrono::duration_cast<std::chrono::minutes>(diff).count() % 60;

    if (!done)
    {
        if (diff < std::chrono::seconds(0))
            std::cout << " (overdue)";
        else
            std::cout << " (" << h << "h " << m << "m remaining)";
    }

    std::cout << "\n";
}

Task Task::readTask(std::istream& File)
{
    std::string Title, Content, Date, Status;
    std::getline(File, Title, ';');
    std::getline(File, Content, ';');
    std::getline(File, Date, ';');
    std::getline(File, Status, ';');


    if (Title.empty()) Title = "unknown";
    if (Content.empty()) Content = "unknown";
    if (Date.empty()) Date = "2025-01-01 00:00";
    if (Status.empty()) Status = "unfinished";

    bool Isdone = (Status=="finished" ? true : false);

    return Task(Title, Content, Isdone, parseDate(Date));
}

void Task::writeTask(std::ostream& File) const
{
    std::time_t t = std::chrono::system_clock::to_time_t(deadline);
    std::tm* tm = std::localtime(&t);

    File << title << ";"
         << content << ";"
         << done << ";"
         << std::put_time(tm, "%Y-%m-%d %H:%M")
         << ";\n";
}

