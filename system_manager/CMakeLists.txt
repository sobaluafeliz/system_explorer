project(system_manager)

add_library(system_manager system_manager.cpp)
target_link_libraries(system_manager client_socket)
