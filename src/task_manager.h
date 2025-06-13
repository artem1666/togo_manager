#pragma once
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

struct Task {
    string title;   
    string date;    
    int priority;   
    bool completed; 
};
class TaskManager {
public:
    void addTask(const string& title, const string& date, int priority);
    void showTasks() const;   
    bool markCompleted(size_t index);    
    void saveToFile(const string& filename) const;    
    void loadFromFile(const string& filename);    
    vector<size_t> findTaskIndices(const string& keyword) const;
    void sortTasks(function<bool(const Task&, const Task&)> comparator);    
    bool editTask(size_t index, const string& newTitle = "", const string& newDate = "", int newPriority = -1);    
    bool deleteTask(size_t index);
    size_t getTaskCount() const;
    const Task& getTask(size_t index) const;

private:
    vector<Task> tasks; 
};