
#include "TaskManager.hpp"
#include "TaskStorage.hpp"

#include <algorithm>
#include <iostream>
#include <exception>
#include <string>
#include <vector>

// ADD TASK
void TaskManager::addTask(const std::string& title) {
    tasks.emplace_back(nextId++, title);
    std::cout << "Task added successfully!\n";
}

// VIEW TASKS
void TaskManager::viewTasks() const {
    std::cout << "\n=== TASK LIST ===\n";
    std::cout << "Total tasks: " << tasks.size() << "\n";

    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
    } else {
        for (const auto& task : tasks) {
            std::cout << "ID: " << task.getId()
                      << " | Title: " << task.getTitle()
                      << " | Status: "
                      << (task.isCompleted() ? "Completed" : "Pending")
                      << "\n";
        }
    }

    std::cout << "=== END OF TASK LIST ===\n";
    std::cout.flush();
}

// COMPLETE TASK
bool TaskManager::completeTask(int id) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.markCompleted();
            return true;
        }
    }

    return false;
}

// DELETE TASK
bool TaskManager::deleteTask(int id) {
    auto newEnd = std::remove_if(
        tasks.begin(),
        tasks.end(),
        [id](const Task& task) {
            return task.getId() == id;
        }
    );

    if (newEnd == tasks.end()) {
        return false;
    }

    tasks.erase(newEnd, tasks.end());
    return true;
}

// SEARCH TASKS
void TaskManager::searchTasks(
    const std::string& keyword
) const {
    bool found = false;

    for (const auto& task : tasks) {
        if (task.getTitle().find(keyword) != std::string::npos) {
            task.display();
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching tasks found!\n";
    }
}

// SORT TASKS
// 1 = Title (A-Z)
// 2 = ID
// 3 = Status
bool TaskManager::sortTasks(int method) {
    if (tasks.empty()) {
        return false;
    }

    if (method == 1) {
        std::sort(
            tasks.begin(),
            tasks.end(),
            [](const Task& a, const Task& b) {
                return a.getTitle() < b.getTitle();
            }
        );

    } else if (method == 2) {
        std::sort(
            tasks.begin(),
            tasks.end(),
            [](const Task& a, const Task& b) {
                return a.getId() < b.getId();
            }
        );

    } else if (method == 3) {
        std::stable_sort(
            tasks.begin(),
            tasks.end(),
            [](const Task& a, const Task& b) {
                return a.isCompleted() < b.isCompleted();
            }
        );

    } else {
        return false;
    }

    return true;
}

// LOAD TASKS
bool TaskManager::loadTasks(
    const std::string& filename
) {
    try {
        tasks = TaskStorage::load(filename);

        nextId = 1;

        for (const auto& task : tasks) {
            if (task.getId() >= nextId) {
                nextId = task.getId() + 1;
            }
        }

        return true;

    } catch (const std::exception& e) {
        std::cerr << "Loading failed: "
                  << e.what() << "\n";
        return false;
    }
}

// SAVE TASKS
bool TaskManager::saveTasks(
    const std::string& filename
) const {
    return TaskStorage::save(tasks, filename);
}

// GET TASK COUNT
std::size_t TaskManager::getTaskCount() const {
    return tasks.size();
}
