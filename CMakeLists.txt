cmake_minimum_required(VERSION 4.1)
project(expression_evaluator)

set(CMAKE_CXX_STANDARD 20)

add_executable(expression_evaluator main.cpp
        ArrayStack.h)
