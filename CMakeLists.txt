cmake_minimum_required(VERSION 3.4)
project(pythoncc)
add_subdirectory(pybind11)
pybind11_add_module(pythoncc src/main.cpp)