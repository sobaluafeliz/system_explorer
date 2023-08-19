project(client_app)

add_executable(client_app client_app.cpp)
target_link_libraries(client_app client_socket)
