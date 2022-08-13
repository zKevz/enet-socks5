cmake_minimum_required(VERSION 3.8)
project(enet-socks5-test)

set(CMAKE_C_STANDARD 11)

add_subdirectory(enet)
add_executable(${PROJECT_NAME} test.c)
target_link_libraries(${PROJECT_NAME} enet)
