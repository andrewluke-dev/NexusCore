
#pragma once

#include <string>

class Task {
private:
    int id;
    std::string title;
    bool completed;

public:
    Task(int taskId, const std::string& taskTitle);

    int getId() const;
    const std::string& getTitle() const;
    bool isCompleted() const;

    void markCompleted();
    void setCompleted(bool status);
    void display() const;
};
