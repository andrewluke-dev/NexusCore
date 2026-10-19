
#include "TaskStorage.hpp"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>

bool TaskStorage::save(
    const std::vector<Task>& tasks,
    const std::string& filename
) {
    std::ofstream file(filename, std::ios::trunc);

    if (!file.is_open()) {
        std::cerr << "Error opening file for saving!\n";
        return false;
    }

    for (const auto& task : tasks) {
        file << task.getId() << " "
             << task.isCompleted() << " "
             << std::quoted(task.getTitle()) << "\n";
    }

    file.flush();

    if (!file.good()) {
        std::cerr << "Error writing task data!\n";
        return false;
    }

    return true;
}

std::vector<Task> TaskStorage::load(
    const std::string& filename
) {
    std::vector<Task> tasks;
    std::ifstream file(filename);

    if (!file.is_open()) {
        return tasks;
    }

    int id;
    int completed;
    std::string title;

    while (file >> id >> completed >> std::quoted(title)) {
        if (id <= 0 || (completed != 0 && completed != 1)) {
            throw std::runtime_error("Invalid task data!");
        }

        Task task(id, title);
        task.setCompleted(completed == 1);

        tasks.push_back(task);
    }

    if (!file.eof()) {
        throw std::runtime_error("Corrupted task file!");
    }

    return tasks;
}
