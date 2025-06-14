#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/task_manager.h"

TEST_CASE("Adding and getting tasks") {
    TaskManager manager;

    SUBCASE("Add single task") {
        manager.addTask("Test task", "01.01.2025", 1);
        CHECK(manager.getTaskCount() == 1);

        const auto& task = manager.getTask(0);
        CHECK(task.title == "Test task");
        CHECK(task.date == "01.01.2025");
        CHECK(task.priority == 1);
        CHECK(task.completed == false);
    }

    SUBCASE("Add multiple tasks") {
        manager.addTask("Task 1", "01.01.2025", 1);
        manager.addTask("Task 2", "02.01.2025", 2);
        CHECK(manager.getTaskCount() == 2);
    }

    SUBCASE("Get task with invalid index") {
        CHECK_THROWS_AS(manager.getTask(0), std::out_of_range);
    }
}

TEST_CASE("Marking tasks as completed") {
    TaskManager manager;
    manager.addTask("Test", "01.01.2025", 1);

    SUBCASE("Mark valid task as completed") {
        CHECK(manager.markCompleted(0) == true);
        CHECK(manager.getTask(0).completed == true);
    }

    SUBCASE("Mark invalid task as completed") {
        CHECK(manager.markCompleted(1) == false);
    }
}

TEST_CASE("Finding tasks") {
    TaskManager manager;
    manager.addTask("Buy milk", "01.01.2025", 1);
    manager.addTask("Call mom", "02.01.2025", 2);
    manager.addTask("Buy bread", "03.01.2025", 3);

    SUBCASE("Find by title") {
        auto results = manager.findTaskIndices("Buy");
        REQUIRE(results.size() == 2);
        CHECK(results[0] == 0);
        CHECK(results[1] == 2);
    }

    SUBCASE("Find by date") {
        auto results = manager.findTaskIndices("02.01.2025");
        REQUIRE(results.size() == 1);
        CHECK(results[0] == 1);
    }

    SUBCASE("Find non-existent") {
        auto results = manager.findTaskIndices("Non-existent");
        CHECK(results.empty());
    }
}

TEST_CASE("Editing tasks") {
    TaskManager manager;
    manager.addTask("Original", "01.01.2025", 1);

    SUBCASE("Edit title") {
        CHECK(manager.editTask(0, "New title", "", -1));
        CHECK(manager.getTask(0).title == "New title");
        CHECK(manager.getTask(0).date == "01.01.2025");
    }

    SUBCASE("Edit date") {
        CHECK(manager.editTask(0, "", "02.01.2025", -1));
        CHECK(manager.getTask(0).date == "02.01.2025");
    }

    SUBCASE("Edit priority") {
        CHECK(manager.editTask(0, "", "", 3));
        CHECK(manager.getTask(0).priority == 3);
    }

    SUBCASE("Edit invalid task") {
        CHECK(manager.editTask(1, "New", "", -1) == false);
    }
}

TEST_CASE("Deleting tasks") {
    TaskManager manager;
    manager.addTask("Task 1", "01.01.2025", 1);
    manager.addTask("Task 2", "02.01.2025", 2);

    SUBCASE("Delete valid task") {
        CHECK(manager.deleteTask(0));
        CHECK(manager.getTaskCount() == 1);
        CHECK(manager.getTask(0).title == "Task 2");
    }

    SUBCASE("Delete invalid task") {
        CHECK(manager.deleteTask(2) == false);
        CHECK(manager.getTaskCount() == 2);
    }
}

TEST_CASE("Sorting tasks") {
    TaskManager manager;
    manager.addTask("Low", "02.01.2025", 1);
    manager.addTask("High", "01.01.2025", 3);
    manager.addTask("Medium", "03.01.2025", 2);

    SUBCASE("Sort by priority ascending") {
        manager.sortTasks([](const Task& a, const Task& b) { return a.priority < b.priority; });
        CHECK(manager.getTask(0).priority == 1);
        CHECK(manager.getTask(2).priority == 3);
    }

    SUBCASE("Sort by date descending") {
        manager.sortTasks([](const Task& a, const Task& b) { return a.date > b.date; });
        CHECK(manager.getTask(0).date == "03.01.2025");
        CHECK(manager.getTask(2).date == "01.01.2025");
    }
}

TEST_CASE("File operations") {
    TaskManager manager;
    manager.addTask("Save test", "01.01.2025", 1);
    manager.addTask("Another task", "02.01.2025", 2);
    manager.markCompleted(0);

    SUBCASE("Save and load") {
        manager.saveToFile("test_tasks.txt");

        TaskManager loadedManager;
        loadedManager.loadFromFile("test_tasks.txt");

        CHECK(loadedManager.getTaskCount() == 2);
        CHECK(loadedManager.getTask(0).title == "Save test");
        CHECK(loadedManager.getTask(0).completed == true);
        CHECK(loadedManager.getTask(1).priority == 2);
    }

    SUBCASE("Load non-existent file") {
        TaskManager emptyManager;
        emptyManager.loadFromFile("non_existent.txt");
        CHECK(emptyManager.getTaskCount() == 0);
    }
}