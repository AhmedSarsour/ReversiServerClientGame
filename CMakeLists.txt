cmake_minimum_required(VERSION 3.8)
project(UnitTests)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES src/BasicRules.cpp src/BasicRules.h src/Board.cpp src/Board.h src/ConsoleBoard.cpp
        src/ConsoleBoard.h src/HumanPlayer.cpp src/HumanPlayer.h src/Player.h
        src/Point.cpp src/Point.h src/Rules.cpp src/Rules.h src/PointsList.cpp
        src/PointsList.h src/AiPlayer.cpp src/AiPlayer.h src/main.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(TEST_FILES test/BoardTest.cpp test/BoardTest.h)

add_executable(UnitTests ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
add_executable(Reversi ${SOURCE_FILES} src/main.cpp)
target_link_libraries(UnitTests gtest gtest_main pthread)
add_test(UnitTests UnitTests)