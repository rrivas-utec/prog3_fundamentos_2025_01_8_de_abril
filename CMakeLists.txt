cmake_minimum_required(VERSION 3.30)
project(prog3_fundamentos_2025_01_8_de_abril)

set(CMAKE_CXX_STANDARD 20)

add_executable(prog3_fundamentos_2025_01_8_de_abril main.cpp
        figura.cpp
        figura.h
        canvas.cpp
        canvas.h)

# Supón que este es tu archivo fuente
set(SOURCE_FILE "${CMAKE_SOURCE_DIR}/draw.txt")

# Y quieres copiarlo al build
set(DESTINATION_FILE "${CMAKE_BINARY_DIR}/draw.txt")

# Copia literal
configure_file(${SOURCE_FILE} ${DESTINATION_FILE} COPYONLY)

