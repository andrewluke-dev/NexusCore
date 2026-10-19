
#pragma once

#include <string>
#include <vector>
#include "Task.hpp"

class TaskManager {
private:
    std::vector<Task> tasks;
    int nextId = 1;

public:
    void addTask(const std::string& title);
    void viewTasks() const;
    bool completeTask(int id);
    bool deleteTask(int id);
    void searchTasks(const std::string& keyword) const;
    bool sortTasks(int method);

    bool loadTasks(const std::string& filename);
    bool saveTasks(const std::string& filename) const;

    std::size_t getTaskCount() const;
};
