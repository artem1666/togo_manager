/**
 * @file main.cpp
 * @brief Консольный интерфейс для менеджера задач.
 */

#include <iostream>
#include <string>
#include "task_manager.h"

using namespace std;

/**
 * @brief Выводит главное меню в консоль.
 */
void showMenu() {
    cout << "\n=============================";
    cout << "\n|        Task Manager       |";
    cout << "\n=============================\n";
    cout << "|         1.Add task        |\n";
    cout << "|      2.Show all tasks     |\n"; 
    cout << "|        3.Sort tasks       |\n"; 
    cout << "|        4.Find task        |\n";
    cout << "|        5.Edit task        |\n";
    cout << "|       6.Delete task       |\n";
    cout << "|     7.Mark as completed   |\n";
    cout << "|      8.Exit and save      |\n";
    cout << "=============================\n";
    cout << " > ";
}

/**
 * @brief Добавляет задачу через пользовательский ввод.
 * @param manager Ссылка на объект TaskManager.
 */
void addTask(TaskManager& manager) {
    string title, date;
    int priority;

    cout << "Title: ";
    getline(cin, title);

    cout << "Date (DD.MM.YYYY): ";
    getline(cin, date);

    cout << "Priority (1-3): ";
    cin >> priority;
    cin.ignore();

    manager.addTask(title, date, priority);
    cout << "Task added!\n";
}

/**
 * @brief Сортирует задачи по выбранному критерию.
 * @param manager Ссылка на объект TaskManager.
 */

void showSortedTasks(TaskManager& manager) {
    cout << "\nSort tasks\n";
    cout << "1. By priority (v)\n";
    cout << "2. By priority (^)\n";
    cout << "3. By date (^)\n";
    cout << "4. By date (v)\n";
    cout << "> ";

    int choice;
    cin >> choice;
    cin.ignore();

    switch (choice) {
    case 1: manager.sortTasks([](const Task& a, const Task& b) { return a.priority < b.priority; }); break;
    case 2: manager.sortTasks([](const Task& a, const Task& b) { return a.priority > b.priority; }); break;
    case 3: manager.sortTasks([](const Task& a, const Task& b) { return a.date < b.date; }); break;
    case 4: manager.sortTasks([](const Task& a, const Task& b) { return a.date > b.date; }); break;
    default: cout << "Invalid choice!\n"; return;
    }

    cout << "\nSorted tasks:\n";
    manager.showTasks();
}

/**
 * @brief Редактирует задачу по индексу.
 * @param manager Ссылка на объект TaskManager.
 */
void editTask(TaskManager& manager) {
    manager.showTasks();
    cout << "Enter task number: ";
    size_t index;
    cin >> index;
    cin.ignore();

    string title, date;
    int priority;

    cout << "New title (Enter to keep): ";
    getline(cin, title);

    cout << "New date (Enter to keep): ";
    getline(cin, date);

    cout << "New priority (1-3, 0 to keep): ";
    cin >> priority;
    cin.ignore();

    if (manager.editTask(index - 1, title, date, priority == 0 ? -1 : priority))
        cout << "Task updated!\n";
    else cout << "Edit error!\n";
}

int main() {
    TaskManager manager;
    manager.loadFromFile("tasks.txt");

    while (true) {
        showMenu();
        int choice;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: addTask(manager); break;
        case 2: manager.showTasks(); break;
        case 3: showSortedTasks(manager); break;
        case 4: {
            string keyword;
            cout << "Search: ";
            cin >> keyword;

            auto indices = manager.findTaskIndices(keyword);
            if (indices.empty()) {
                cout << "No tasks found\n";
            }
            else {
                for (auto i : indices) {
                    const auto& task = manager.getTask(i);
                    cout << i + 1 << ". " << task.title << " (" << task.date << ")\n";
                }
            }
            break;
        }
        case 5: editTask(manager); break;
        case 6: {
            manager.showTasks();
            cout << "Enter task number: ";
            size_t index;
            cin >> index;
            cin.ignore();

            if (manager.deleteTask(index - 1)) 
                cout << "Task deleted!\n";
            else cout << "Invalid number!\n";
            break;
        }
        case 7: {
            manager.showTasks();
            cout << "Enter task number: ";
            size_t index;
            cin >> index;
            cin.ignore();

            if (manager.markCompleted(index - 1))
                cout << "Task marked as completed!\n";
            else cout << "Invalid number!\n";
            break;
        }
        case 8:
            manager.saveToFile("tasks.txt");
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}