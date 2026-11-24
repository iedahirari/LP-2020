cmake_minimum_required(VERSION 3.16)
project(LP2020 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(vetores "Vetores Parte 01/ieda_e_thainara/ieda_e_thainara.cpp")
add_executable(strings "String/ieda_e_thainara/ieda_e_thainara.cpp")
add_executable(consolidacao "Consolidação dos Conteúdos/main.cpp")

foreach(target vetores strings consolidacao)
    if(MSVC)
        target_compile_options(${target} PRIVATE /W4 /utf-8)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic)
    endif()
endforeach()
