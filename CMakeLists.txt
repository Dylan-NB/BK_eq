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
target_link_libraries(rk4 PUBLIC function bk)

add_library(function src/function.cpp)
target_include_directories(function PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

add_library(trapezoid src/trapezoid.cpp)
target_include_directories(trapezoid PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )
target_link_libraries(trapezoid PUBLIC function)

add_library(dipole src/dipole.cpp)
target_include_directories(dipole PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

add_library(bk src/BKec.cpp)
target_include_directories(bk PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  )
target_link_libraries(bk PUBLIC dipole trapezoid)

# ejecutable "entry-point"
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE rk4 function trapezoid)
target_compile_options(main PRIVATE -O3 -Wall -Wextra -Wpedantic)

# segundo ejecutable: prueba de la integral 1D de BK
add_executable(main2 src/main2.cpp)
target_link_libraries(main2 PRIVATE function trapezoid)
target_compile_options(main2 PRIVATE -O3 -Wall -Wextra -Wpedantic)

add_executable(main3 src/main3.cpp)
target_link_libraries(main3 PRIVATE function trapezoid)
target_compile_options(main3 PRIVATE -O3 -Wall -Wextra -Wpedantic)

# cuarto ejecutable: evolución en y con Dipole y RK4
add_executable(main4 src/main4.cpp)
target_link_libraries(main4 PRIVATE rk4 dipole)
target_compile_options(main4 PRIVATE -O3 -Wall -Wextra -Wpedantic)
