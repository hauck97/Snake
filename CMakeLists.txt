cmake_minimum_required(VERSION 3.22)

project(Snake_Cpp VERSION 1.0.0 LANGUAGES C CXX)

option(ENABLE_TESTING "Enable a Unit Testing Build" ON)
set(CMAKE_BUILD_TYPE Debug)
set(EXECUTABLE_NAME Executable)
set(LIBRARY_NAME snake_lib)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2
    GIT_TAG v2.13.9
    GIT_SHALLOW TRUE)
FetchContent_MakeAvailable(Catch2)


add_subdirectory(app)
add_subdirectory(src)


find_package(Curses REQUIRED)
target_include_directories(${EXECUTABLE_NAME} PRIVATE ${CURSES_INCLUDE_DIRS})
target_link_libraries(${EXECUTABLE_NAME} PRIVATE
${MAIN}
${CURSES_LIBRARIES}
Catch2::Catch2
)
add_subdirectory(tests)
