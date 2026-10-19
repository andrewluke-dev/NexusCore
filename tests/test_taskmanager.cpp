
#include <cassert>
#include <iostream>
#include <string>
#include <filesystem>

#include "Task.hpp"
#include "TaskManager.hpp"

// ============================================
// NEXUSCORE AUTOMATED TEST SUITE
// ============================================

namespace fs = std::filesystem;

// ============================================
// TEST 1 - TASK CREATION
// ============================================

void testTaskCreation() {
    Task task(1, "Learn C++");

    assert(task.getId() == 1);
    assert(task.getTitle() == "Learn C++");
    assert(task.isCompleted() == false);

    std::cout << "[PASS] Task creation\n";
}

// ============================================
// TEST 2 - TASK COMPLETION
// ============================================

void testTaskCompletion() {
    Task task(2, "Build NexusCore");

    assert(!task.isCompleted());

    task.markCompleted();

    assert(task.isCompleted());

    std::cout << "[PASS] Task completion\n";
}

// ============================================
// TEST 3 - ADD TASK
// ============================================

void testAddTask() {
    TaskManager manager;

    assert(manager.getTaskCount() == 0);

    manager.addTask("First task");
    manager.addTask("Second task");

    assert(manager.getTaskCount() == 2);

    std::cout << "[PASS] Add tasks\n";
}

// ============================================
// TEST 4 - COMPLETE TASK
// ============================================

void testCompleteTask() {
    TaskManager manager;

    manager.addTask("Complete this task");

    assert(manager.completeTask(1));
    assert(!manager.completeTask(999));

    std::cout << "[PASS] Complete task by ID\n";
}

// ============================================
// TEST 5 - DELETE TASK
// ============================================

void testDeleteTask() {
    TaskManager manager;

    manager.addTask("Delete this task");
    manager.addTask("Keep this task");

    assert(manager.getTaskCount() == 2);

    assert(manager.deleteTask(1));

    assert(manager.getTaskCount() == 1);

    assert(!manager.deleteTask(999));

    std::cout << "[PASS] Delete task\n";
}

// ============================================
// TEST 6 - SORT TASKS
// ============================================

void testSortTasks() {
    TaskManager manager;

    manager.addTask("Zebra");
    manager.addTask("Apple");
    manager.addTask("Moon");

    assert(manager.sortTasks(1));
    assert(manager.sortTasks(2));
    assert(manager.sortTasks(3));

    assert(!manager.sortTasks(99));

    std::cout << "[PASS] Sort methods\n";
}

// ============================================
// TEST 7 - SAVE AND LOAD TASKS
// ============================================

void testStorage() {
    const std::string filename =
        "nexuscore_test_tasks.txt";

    TaskManager manager;

    manager.addTask("Persistent task");

    assert(manager.saveTasks(filename));

    TaskManager loadedManager;

    assert(loadedManager.loadTasks(filename));

    assert(loadedManager.getTaskCount() == 1);

    assert(loadedManager.completeTask(1));

    // Remove temporary test file
    fs::remove(filename);

    std::cout << "[PASS] Save and load tasks\n";
}

// ============================================
// TEST 8 - EMPTY TASK MANAGER
// ============================================

void testEmptyManager() {
    TaskManager manager;

    assert(manager.getTaskCount() == 0);

    assert(!manager.completeTask(1));
    assert(!manager.deleteTask(1));
    assert(!manager.sortTasks(1));

    std::cout << "[PASS] Empty manager\n";
}

// ============================================
// RUN ALL TESTS
// ============================================

int main() {
    std::cout << "\n================================\n";
    std::cout << "    NEXUSCORE AUTOMATED TESTS\n";
    std::cout << "================================\n\n";

    testTaskCreation();
    testTaskCompletion();
    testAddTask();
    testCompleteTask();
    testDeleteTask();
    testSortTasks();
    testStorage();
    testEmptyManager();

    std::cout << "\n================================\n";
    std::cout << "       ALL TESTS PASSED!\n";
    std::cout << "================================\n";

    return 0;
}
