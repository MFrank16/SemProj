cmake_minimum_required(VERSION 3.17)
project(SemProj2)

set(CMAKE_CXX_STANDARD 20)

add_executable(SemProj2
        LinkedList.cpp
        LinkedListNode.cpp
        Item.cpp
        Automat.cpp
        CoinBuffer.cpp

        testyUloha_0.cpp


        GoogleTest/gtest-death-test.cc
        GoogleTest/gtest-filepath.cc
        GoogleTest/gtest-port.cc
        GoogleTest/gtest-printers.cc
        GoogleTest/gtest-test-part.cc
        GoogleTest/gtest-typed-test.cc
        GoogleTest/gtest.cc
        GoogleTest/gtest_main.cc)

include_directories(GoogleTest)

