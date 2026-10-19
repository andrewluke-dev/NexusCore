
#include <iostream>
#include <string>
#include <limits>
#include <exception>

#include "TaskManager.hpp"

int main() {
    // ============================================
    // NEXUSCORE SYSTEM - MAIN APPLICATION
    // ============================================

    const std::string filename = "data/tasks.txt";

    TaskManager manager;

    // ============================================
    // LOAD TASKS
    // ============================================

    if (!manager.loadTasks(filename)) {
        std::cerr << "Loading failed!\n";
        return 1;
    }

    int choice = 0;

    std::cout << "DEBUG: Loaded "
              << manager.getTaskCount()
              << " tasks from storage.\n";

    // ============================================
    // MAIN APPLICATION LOOP
    // ============================================

    while (true) {

        // ========================================
        // MAIN MENU
        // ========================================

        std::cout << "\n================================\n";
        std::cout << "       NEXUSCORE SYSTEM\n";
        std::cout << "================================\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Complete Task\n";
        std::cout << "4. Delete Task\n";
        std::cout << "5. Search Task\n";
        std::cout << "6. Sort Tasks\n";
        std::cout << "7. Exit\n";
        std::cout << "Choose an option: " << std::flush;

        // ========================================
        // VALIDATE MENU INPUT
        // ========================================

        if (!(std::cin >> choice)) {
            if (std::cin.eof()) {
                break;
            }

            std::cin.clear();

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            std::cout << "Invalid input!\n";
            continue;
        }

        std::cout << "DEBUG: You selected "
                  << choice << std::endl;

        // ========================================
        // OPTION 1 - ADD TASK
        // ========================================

        if (choice == 1) {

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            std::string title;

            std::cout << "Task title: " << std::flush;
            std::getline(std::cin, title);

            if (!std::cin) {
                std::cout << "Input interrupted!\n";
                break;
            }

            if (title.empty()) {
                std::cout << "Title cannot be empty!\n";
                continue;
            }

            manager.addTask(title);

        // ========================================
        // OPTION 2 - VIEW TASKS
        // ========================================

        } else if (choice == 2) {

            manager.viewTasks();

        // ========================================
        // OPTION 3 - COMPLETE TASK
        // ========================================

        } else if (choice == 3) {

            int id;

            std::cout << "Enter task ID: "
                      << std::flush;

            if (!(std::cin >> id)) {
                if (std::cin.eof()) {
                    break;
                }

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                std::cout << "Invalid ID!\n";
                continue;
            }

            if (manager.completeTask(id)) {
                std::cout << "Task completed!\n";
            } else {
                std::cout << "Task not found!\n";
            }

        // ========================================
        // OPTION 4 - DELETE TASK
        // ========================================

        } else if (choice == 4) {

            int id;

            std::cout << "Enter task ID to delete: "
                      << std::flush;

            if (!(std::cin >> id)) {
                if (std::cin.eof()) {
                    break;
                }

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                std::cout << "Invalid ID!\n";
                continue;
            }

            if (manager.deleteTask(id)) {
                std::cout << "Task deleted successfully!\n";
            } else {
                std::cout << "Task not found!\n";
            }

        // ========================================
        // OPTION 5 - SEARCH TASK
        // ========================================

        } else if (choice == 5) {

            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n'
            );

            std::string keyword;

            std::cout << "Enter task name to search: "
                      << std::flush;

            std::getline(std::cin, keyword);

            if (!std::cin) {
                std::cout << "Input interrupted!\n";
                break;
            }

            if (keyword.empty()) {
                std::cout << "Search cannot be empty!\n";
                continue;
            }

            manager.searchTasks(keyword);

        // ========================================
        // OPTION 6 - SORT TASKS
        // ========================================

        } else if (choice == 6) {

            if (manager.getTaskCount() == 0) {
                std::cout << "No tasks to sort!\n";
                continue;
            }

            int sortChoice = 0;

            std::cout << "\nSORT TASKS\n";
            std::cout << "1. Sort by title (A-Z)\n";
            std::cout << "2. Sort by ID\n";
            std::cout << "3. Sort by status\n";
            std::cout << "Choose sorting method: "
                      << std::flush;

            if (!(std::cin >> sortChoice)) {
                if (std::cin.eof()) {
                    break;
                }

                std::cin.clear();

                std::cin.ignore(
                    std::numeric_limits<std::streamsize>::max(),
                    '\n'
                );

                std::cout << "Invalid input!\n";
                continue;
            }

            if (sortChoice < 1 || sortChoice > 3) {
                std::cout << "Invalid sorting method!\n";
                continue;
            }

            if (manager.sortTasks(sortChoice)) {

                std::cout
                    << "\nTasks sorted successfully!\n";

                manager.viewTasks();

            } else {

                std::cout
                    << "Invalid sorting method!\n";
            }

        // ========================================
        // OPTION 7 - SAVE AND EXIT
        // ========================================

        } else if (choice == 7) {

            if (manager.saveTasks(filename)) {

                std::cout
                    << "Tasks saved successfully!\n";

                std::cout << "Goodbye!\n";
                break;
            }

            std::cout
                << "Saving failed. Please try again!\n";

        // ========================================
        // INVALID OPTION
        // ========================================

        } else {

            std::cout << "Invalid option!\n";
        }
    }

    return 0;
}
