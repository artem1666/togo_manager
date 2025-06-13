#include "task_manager.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void TaskManager::addTask(const string& title, const string& date, int priority) {
    tasks.push_back({ title, date, priority, false });
}

void TaskManager::showTasks() const {
    if (tasks.empty()) {
        cout << "Task list is empty.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        const auto& task = tasks[i];
        cout << i + 1 << ". " << (task.completed ? "[x] " : "[ ] ") << task.title << " (" << task.date << ", priority: " << task.priority << ")\n";
    }
}

bool TaskManager::markCompleted(size_t index) {
    if (index >= tasks.size()) return false;
    tasks[index].completed = true;
    return true;
}

void TaskManager::saveToFile(const string& filename) const {
    ofstream file(filename);
    for (const auto& task : tasks) {
        file << task.title << "," << task.date << "," << task.priority << "," << task.completed << "\n";
    }
}

void TaskManager::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) return;

    tasks.clear();
    string line;
    while (getline(file, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        size_t pos3 = line.find(',', pos2 + 1);

        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos)
            continue;

        Task task;
        task.title = line.substr(0, pos1);
        task.date = line.substr(pos1 + 1, pos2 - pos1 - 1);
        task.priority = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
        task.completed = (line.substr(pos3 + 1) == "1");
        tasks.push_back(task);
    }
}

vector<size_t> TaskManager::findTaskIndices(const string& keyword) const {
    vector<size_t> indices;
    for (size_t i = 0; i < tasks.size(); ++i) {
        if (tasks[i].title.find(keyword) != string::npos || tasks[i].date.find(keyword) != string::npos) {
            indices.push_back(i);
        }
    }
    return indices;
}

void TaskManager::sortTasks(function<bool(const Task&, const Task&)> comparator) {
    sort(tasks.begin(), tasks.end(), comparator);
}

bool TaskManager::editTask(size_t index, const string& newTitle,
    const string& newDate, int newPriority) {
    if (index >= tasks.size()) return false;

    if (!newTitle.empty()) tasks[index].title = newTitle;
    if (!newDate.empty()) tasks[index].date = newDate;
    if (newPriority != -1) tasks[index].priority = newPriority;

    return true;
}

bool TaskManager::deleteTask(size_t index) {
    if (index >= tasks.size()) return false;
    tasks.erase(tasks.begin() + index);
    return true;
}

size_t TaskManager::getTaskCount() const {
    return tasks.size();
}

const Task& TaskManager::getTask(size_t index) const {
    return tasks.at(index);
}