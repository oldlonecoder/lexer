cmake_minimum_required(VERSION 3.13..3.26 FATAL_ERROR)
project(lexer-test.app VERSION 0.1.0 LANGUAGES CXX)

message("Entering ${PROJECT_NAME} project configuration:")

set(TargetName ${PROJECT_NAME})

add_executable(${TargetName} main.cc)

target_link_libraries(${TargetName} chrtools logbook lexer)
