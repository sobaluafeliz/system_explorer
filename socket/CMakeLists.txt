project(socket)

add_library(client_socket client_socket.cpp)

add_library(server_socket server_socket.cpp)
target_link_libraries(server_socket client_socket)
