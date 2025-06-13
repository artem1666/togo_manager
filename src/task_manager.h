cpp
/**
 * @file task_manager.h
 * @brief Заголовочный файл класса TaskManager для управления задачами.
 */

#pragma once
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

using namespace std;

/**
 * @brief Структура, описывающая задачу.
 */
struct Task {
    string title;   ///< Название задачи
    string date;    ///< Дата в формате DD.MM.YYYY
    int priority;   ///< Приоритет задачи (1-3)
    bool completed; ///< Флаг выполнения
};

/**
 * @brief Класс для управления списком задач.
 *
 * Позволяет добавлять, удалять, редактировать, искать и сортировать задачи.
 * Данные сохраняются в файл и загружаются из него.
 */
class TaskManager {
public:
    /**
     * @brief Добавляет новую задачу.
     * @param title Название задачи.
     * @param date Дата в формате DD.MM.YYYY.
     * @param priority Приоритет (1-3).
     */
    void addTask(const string& title, const string& date, int priority);

    /**
     * @brief Выводит список всех задач в консоль.
     */
    void showTasks() const;
    
    /**
     * @brief Отмечает задачу как выполненную.
     * @param index Индекс задачи в списке.
     * @return true, если операция успешна, false при неверном индексе.
     */
    bool markCompleted(size_t index);
    
    /**
     * @brief Сохраняет задачи в файл.
     * @param filename Имя файла (например, "tasks.txt").
     */
    void saveToFile(const string& filename) const;
    
    /**
     * @brief Загружает задачи из файла.
     * @param filename Имя файла (например, "tasks.txt").
     */
    void loadFromFile(const string& filename);
    
    /**
     * @brief Ищет задачи по ключевому слову.
     * @param keyword Строка для поиска (в названии или дате).
     * @return Вектор индексов подходящих задач.
     */
    vector<size_t> findTaskIndices(const string& keyword) const;
    
    /**
     * @brief Сортирует задачи по заданному критерию.
     * @param comparator Функция сравнения двух задач.
     */
    void sortTasks(function<bool(const Task&, const Task&)> comparator);
    
    /**
     * @brief Редактирует задачу.
     * @param index Индекс задачи.
     * @param newTitle Новое название (пустая строка — оставить без изменений).
     * @param newDate Новая дата (пустая строка — оставить без изменений).
     * @param newPriority Новый приоритет (-1 — оставить без изменений).
     * @return true, если операция успешна, false при неверном индексе.
     */
    bool editTask(size_t index, const string& newTitle = "", const string& newDate = "", int newPriority = -1);
    
    /**
     * @brief Удаляет задачу.
     * @param index Индекс задачи.
     * @return true, если операция успешна, false при неверном индексе.
     */
    bool deleteTask(size_t index);
    
    /**
     * @brief Возвращает количество задач.
     * @return Число задач в списке.
     */
    size_t getTaskCount() const;
    
    /**
     * @brief Возвращает задачу по индексу.
     * @param index Индекс задачи.
     * @return Константная ссылка на задачу.
     * @throw std::out_of_range Если индекс некорректен.
     */
    const Task& getTask(size_t index) const;

private:
    vector<Task> tasks; ///< Вектор для хранения задач.
};