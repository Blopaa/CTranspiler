cmake_minimum_required(VERSION 3.29)
project(untitled14 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled14 src/main.c
        src/lexer/lexer.h
        src/lexer/lexer.c
        src/parser/parser.h
        src/parser/parser.c
        src/generator/generator.c
        src/generator/generator.h
)
