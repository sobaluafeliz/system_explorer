cmake_minimum_required(VERSION 3.22)
project(practice)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_subdirectory(client_app)
add_subdirectory(server_app)
add_subdirectory(socket)
add_subdirectory(system_manager)
add_subdirectory(test_system)
