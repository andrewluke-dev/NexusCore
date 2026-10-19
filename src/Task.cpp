
#include "Task.hpp"
#include <iostream>
#include <string>

// ==========================================
// NEXUSCORE - TASK IMPLEMENTATION
// C++17
// ==========================================

// Constructor
Task::Task(int taskId, const std::string& taskTitle)
    : id(taskId),
      title(taskTitle),
      completed(false) {
}

// Get task ID
int Task::getId() const {
    return id;
}

// Get task title
const std::string& Task::getTitle() const {
    return title;
}

// Check completion status
bool Task::isCompleted() const {
    return completed;
}

// Mark task as completed
void Task::markCompleted() {
    completed = true;
}

// Set completion status
// Used when loading tasks from storage
void Task::setCompleted(bool status) {
    completed = status;
}

// Display task information
void Task::display() const {
    std::cout << "[" << id << "] "
              << title
              << " - "
              << (completed ? "Completed" : "Pending")
              << "\n";
}
