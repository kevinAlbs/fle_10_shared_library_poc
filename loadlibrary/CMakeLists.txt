cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(dlopen_examples LANGUAGES C)
add_library (example_library SHARED example_library.c)
add_executable (main.out main.c)