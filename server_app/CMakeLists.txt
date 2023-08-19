project(server_app)

add_executable(server_app server_app.cpp)
target_link_libraries(server_app server_socket system_manager)
