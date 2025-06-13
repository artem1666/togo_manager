#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/task_manager.h"

TEST_CASE("Adding and getting tasks") {
    TaskManager manager;
    manager.addTask("Test task", "01.01.2025", 1);

    CHECK(manager.getTaskCount() == 1);

    const auto& task = manager.getTask(0);
    CHECK(task.title == "Test task");
    CHECK(task.date == "01.01.2025");
    CHECK(task.priority == 1);
    CHECK(task.completed == false);
}

TEST_CASE("Marking tasks as completed") {
    TaskManager manager;
    manager.addTask("Test", "01.01.2025", 1);

    CHECK(manager.markCompleted(0) == true);
    CHECK(manager.getTask(0).completed == true);
    CHECK(manager.markCompleted(1) == false);  // Invalid index
}

TEST_CASE("Finding tasks") {
    TaskManager manager;
    manager.addTask("Buy milk", "01.01.2025", 1);
    manager.addTask("Call mom", "02.01.2025", 2);
    manager.addTask("Buy bread", "03.01.2025", 3);

    auto results = manager.findTaskIndices("Buy");
    REQUIRE(results.size() == 2);
    CHECK(results[0] == 0);
    CHECK(results[1] == 2);
}