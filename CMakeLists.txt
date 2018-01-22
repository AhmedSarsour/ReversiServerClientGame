cmake_minimum_required(VERSION 3.8)
project(Reversi)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES client/BasicRules.cpp client/BasicRules.h client/Board.cpp client/Board.h client/ConsoleBoard.cpp
        client/ConsoleBoard.h client/HumanPlayer.cpp client/HumanPlayer.h client/Player.h
        client/Point.cpp client/Point.h client/Rules.h client/PointsList.cpp
        client/PointsList.h client/AiPlayer.cpp client/AiPlayer.h)

set(SERVER_FILES server/Server.cpp server/Server.h server/main.cpp server/GameCollection.cpp server/GameCollection.h
        server/Command.h server/CommandsManager.cpp server/CommandsManager.h
        server/JoinCommand.h server/ListCommand.h server/StartCommand.h server/GameInfo.h server/JoinCommand.cpp server/GameInfo.cpp
        server/ListCommand.cpp server/StartCommand.cpp server/Task.h server/ThreadPool.cpp server/ThreadPool.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(TEST_FILES test/TestBoard.h test/TestBoard.cpp
        test/TestPoint.cpp test/TestPoint.h test/TestPointList.cpp test/TestPointList.h
        test/TestPlayer.cpp test/TestPlayer.h test/TestRules.h test/TestRules.cpp)

add_executable(ReversiTests ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
add_executable(Client ${SOURCE_FILES} client/main.cpp client/Client.cpp client/Client.h client/RemotePlayer.cpp client/RemotePlayer.h)
add_executable(Server ${SOURCE_FILES} ${SERVER_FILES} server/main.cpp)
target_link_libraries(ReversiTests gtest gtest_main pthread)
add_test(ReversiTests ReversiTests)