# NexusCore

**A Modular C++17 Task Management System**

NexusCore is a command-line task management application developed in modern C++17. It demonstrates object-oriented programming (OOP), modular architecture, file-based persistence, STL algorithms, automated testing, and CMake-based build management.

The project is designed to showcase practical C++ software engineering skills through a structured, maintainable application.



## Features

- **Task Creation** — Create tasks with automatically generated unique IDs.
- **Task Management** — View, complete, and delete tasks.
- **Task Search** — Find tasks using title-based keyword matching.
- **Multiple Sorting Methods** — Sort tasks by title (A–Z), ID, or completion status.
- **Persistent Storage** — Save tasks to a text file and load them when the application starts.
- **Input Validation** — Handle invalid menu options, IDs, and empty titles.
- **Automated Testing** — Run C++ assertions to verify core functionality.
- **Modular Architecture** — Separate task representation, business logic, storage, and user interaction.
- **CMake Integration** — Build and test the application using standard C++ development tools.

## Technology Stack

| Technology | Purpose |
|---|---|
| C++17 | Core programming language |
| STL | Vectors, algorithms, strings, file streams |
| OOP | Encapsulation and class-based architecture |
| CMake | Build configuration |
| CTest | Automated test execution |
| GCC / G++ | C++ compilation |
| Ubuntu / WSL2 | Development environment |
| Git / GitHub | Version control |

## Project Structure

    NexusCore/
    ├── include/
    │   ├── Task.hpp
    │   ├── TaskManager.hpp
    │   └── TaskStorage.hpp
    ├── src/
    │   ├── main.cpp
    │   ├── Task.cpp
    │   ├── TaskManager.cpp
    │   └── TaskStorage.cpp
    ├── tests/
    │   └── test_taskmanager.cpp
    ├── data/
    ├── CMakeLists.txt
    ├── .gitignore
    └── README.md

## Getting Started

### Requirements

- C++17-compatible compiler
- CMake 3.16 or newer
- Linux or Ubuntu WSL2
- Git

### Clone the Repository

```bash
git clone https://github.com/andrewluke-dev/NexusCore.git
cd NexusCore


### Configure the Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
```

### Compile the Application

```bash
cmake --build build -j 4
```

### Run NexusCore

Create the local storage directory if it does not already exist:

```bash
mkdir -p data
```

Run the application from the project root:

```bash
./nexuscore
```

## Application Interface

The interactive command-line menu provides seven main options:

```text
================================
       NEXUSCORE SYSTEM
================================
1. Add Task
2. View Tasks
3. Complete Task
4. Delete Task
5. Search Task
6. Sort Tasks
7. Exit
Choose an option:
```

### Example Task List

```text
=== TASK LIST ===
Total tasks: 3
ID: 1 | Title: Learn C++ | Status: Completed
ID: 2 | Title: Build NexusCore | Status: Pending
ID: 3 | Title: Write Documentation | Status: Pending
=== END OF TASK LIST ===
```

### Sorting Options

NexusCore supports three sorting methods:

1. **Title (A–Z):** Sort tasks alphabetically.
2. **ID:** Sort tasks by their numeric identifiers.
3. **Status:** Display pending tasks before completed tasks.

## Software Architecture

### Task Class

The `Task` class represents an individual task.

Each task contains a unique identifier, a title, and a completion status.

### TaskManager Class

The `TaskManager` class manages the application's task collection and provides operations for adding, viewing, completing, deleting, searching, and sorting tasks.

### TaskStorage Class

The `TaskStorage` class handles file-based persistence.

Tasks are serialized to a local text file and restored when the application starts.

### Main Application

The `main.cpp` file provides the command-line interface, handles user input, and delegates task operations to `TaskManager`.

This separation improves maintainability and makes the project easier to extend and test.

## Automated Testing

NexusCore includes an automated C++ test suite covering eight areas:

1. Task creation
2. Task completion
3. Adding tasks
4. Completing tasks by ID
5. Deleting tasks
6. Sorting method validation
7. File saving and loading
8. Empty task manager behavior

### Run Tests

```bash
ctest --test-dir build --output-on-failure
```

The suite uses C++ assertions and is integrated with CTest.

## Data Persistence

NexusCore uses a text-based storage format.

Example:

```text
1 0 "Learn C++"
2 1 "Build NexusCore"
3 0 "Write Documentation"
```

Each entry contains a task ID, a completion flag, and a quoted title.

The local task data file is excluded from version control to avoid committing personal task data.

## Future Improvements

Potential enhancements include:

- Task priorities and deadlines
- Task categories and tags
- Editing existing tasks
- JSON-based persistence
- Case-insensitive search
- Advanced filtering
- Additional automated tests
- Continuous integration with GitHub Actions
- Cross-platform packaging

## Development Environment

NexusCore was developed using Visual Studio Code, Ubuntu WSL2, GCC/G++, and CMake.

The project follows modern C++17 practices and uses the Standard Template Library for task management and sorting.

## Author

Andrew Luke

C++ / Software Developer

GitHub: https://github.com/andrewluke-dev

## License

No license has been specified for this repository.