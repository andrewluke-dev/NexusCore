
#pragma once

#include <string>
#include <vector>
#include "Task.hpp"

class TaskStorage {
public:
    static bool save(
        const std::vector<Task>& tasks,
        const std::string& filename
    );

    static std::vector<Task> load(
        const std::string& filename
    );
};
