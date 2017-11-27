cmake_minimum_required(VERSION 3.8)
project(ReversiTests)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES src/BasicRules.cpp src/BasicRules.h src/Board.cpp src/Board.h src/ConsoleBoard.cpp
        src/ConsoleBoard.h src/HumanPlayer.cpp src/HumanPlayer.h src/Player.h
        src/Point.cpp src/Point.h src/Rules.cpp src/Rules.h src/PointsList.cpp
        src/PointsList.h src/AiPlayer.cpp src/AiPlayer.h )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(TEST_FILES test/JustATest.cpp test/TestBoard.h test/TestPlayer.h test/TestPlayer.cpp test/TestRules.cpp test/TestRules.h)

add_executable(ReversiTests ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
add_executable(Reversi ${SOURCE_FILES} src/main.cpp)
target_link_libraries(ReversiTests gtest gtest_main pthread)
add_test(ReversiTests ReversiTests)