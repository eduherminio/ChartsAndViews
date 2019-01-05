cmake_minimum_required(VERSION 2.8)
project( $ENV{env_filename} )

file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
	"*.h"
	"*.cpp"
)

list(REMOVE_ITEM SOURCES "${PROJECT_NAME}.cpp")

SET(CMAKE_CXX_FLAGS "-std=c++17")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable( ${PROJECT_NAME} ${PROJECT_NAME}.cpp ${SOURCES})

target_link_libraries( ${PROJECT_NAME} Threads::Threads)