#ifndef FILEHANDLE_HPP
#define FILEHANDLE_HPP

#pragma once

#include <vector>
#include "taskClass.hpp"

std::vector<Task> getTasksTxt();
int saveTasksTxt(const std::vector<Task>& tasks);
Task makeNewTask();
void printTasksList(std::vector<Task>& tasks);

#endif
