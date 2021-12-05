cmake_minimum_required(VERSION 3.21)
project(UniquePtr)


set(FILES resource.cpp)
add_executable(${PROJECT_NAME} ${FILES})
target_compile_options(${PROJECT_NAME} PRIVATE -Wextra -Wpedantic -Werror -Wall)
