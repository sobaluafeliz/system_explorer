project(test_system)

add_executable(test_system test_system.cpp)
target_link_libraries(test_system server_socket)