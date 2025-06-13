cmake_minimum_required(VERSION 3.5)
project(todo_manager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(todo_manager
    src/main.cpp
    src/task_manager.cpp
)

add_executable(tests
    tests/task_manager_tests.cpp
    src/task_manager.cpp
)

target_include_directories(tests PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

enable_testing()
add_test(NAME tests COMMAND tests)