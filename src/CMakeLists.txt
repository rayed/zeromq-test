cmake_minimum_required(VERSION 3.6)

project(ZeroMQ)

include_directories("${PROJECT_SOURCE_DIR}/zmq")
MESSAGE("project_SOURCE_DIR is '${PROJECT_SOURCE_DIR}'")


find_package(PkgConfig)
pkg_check_modules(ZMQ libzmq)
include_directories("${ZMQ_INCLUDE_DIRS}")
link_directories("${ZMQ_LIBRARY_DIRS}")

add_executable(server
    server.cc
)
target_link_libraries(server "${ZMQ_LIBRARIES}")

add_executable(client
    client.cc
)
target_link_libraries(client "${ZMQ_LIBRARIES}")
