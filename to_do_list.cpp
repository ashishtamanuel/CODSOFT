
   #include <iostream>
#include <string>
#include <limits>

const int MAX_TASKS = 10;

class ToDoList {
private:
    std::string tasks[MAX_TASKS];
    int taskCount;

public:
    ToDoList() : taskCount(0) {}

    void addTask(const std::string& task) {
        if (taskCount < MAX_TASKS) {
            tasks[taskCount++] = task;
            std::cout << "Task \"" << task << "\" added successfully.\n";
        } else {
            std::cout << "To-Do list is full. Cannot add more tasks.\n";
        }
    }

    void updateTask(int taskIndex, const std::string& newTask) {
        if (taskIndex >= 0 && taskIndex < taskCount) {
            tasks[taskIndex] = newTask;
            std::cout << "Task at index " << taskIndex << " updated successfully.\n";
        } else {
            std::cout << "Invalid task index. Please enter a valid task index.\n";
        }
    }

    void deleteTask(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < taskCount) {
            std::cout << "Task \"" << tasks[taskIndex] << "\" deleted successfully.\n";
            for (int i = taskIndex; i < taskCount - 1; ++i) {
                tasks[i] = tasks[i + 1];
            }
            --taskCount;
        } else {
            std::cout << "Invalid task index. Please enter a valid task index.\n";
        }
    }

    void displayTasks() const {
        if (taskCount == 0) {
            std::cout << "No tasks available.\n";
        } else {
            std::cout << "Tasks:\n";
            for (int i = 0; i < taskCount; ++i) {
                std::cout << i + 1 << ". " << tasks[i] << "\n";
            }
        }
    }
};

int main() {
    ToDoList toDoList;

    while (true) {
        std::cout << "\n===== To-Do List Manager =====\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Update Task\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. Display Tasks\n";
        std::cout << "5. Quit\n";

        int choice;
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string newTask;
                std::cout << "Enter the new task: ";
                std::getline(std::cin, newTask);
                toDoList.addTask(newTask);
                break;
            }
            case 2: {
                int taskIndex;
                std::cout << "Enter the task index to update: ";
                std::cin >> taskIndex;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string updatedTask;
                std::cout << "Enter the updated task: ";
                std::getline(std::cin, updatedTask);
                toDoList.updateTask(taskIndex - 1, updatedTask); // Adjust for 1-based index
                break;
            }
            case 3: {
                int taskIndex;
                std::cout << "Enter the task index to delete: ";
                std::cin >> taskIndex;
                toDoList.deleteTask(taskIndex - 1); // Adjust for 1-based index
                break;
            }
            case 4:
                toDoList.displayTasks();
                break;
            case 5:
                std::cout << "Exiting the to-do list manager. Goodbye!\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    }
}

