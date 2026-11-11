cmake_minimum_required(VERSION 3.28)

project(bk_eq VERSION 0.1
              DESCRIPTION "Balitsky-Kovchegov eq."
              LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(rk4 src/RungeKutta4.cpp)
target_include_directories(rk4 PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

add_library(function src/function.cpp)
target_include_directories(function PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

# ejecutable "entry-point"
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE rk4 function)
target_compile_options(main PRIVATE -O3 -Wall -Wextra -Wpedantic)
