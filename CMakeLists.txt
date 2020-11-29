cmake_minimum_required(VERSION 3.16)
project(Polymorphism)

set(CMAKE_CXX_STANDARD 14)

add_executable(Polymorphism main.cpp DynamicArray.hpp DynamicArrayImplementation.hpp List.hpp ListImplementation.hpp Utils.cpp Utils.hpp ISequence.hpp ArraySequence.hpp ArraySequenceImplementation.hpp ListSequence.hpp ListSequenceImplementation.hpp StringVector.cpp StringVector.hpp StringList.hpp StringList.cpp Interface.cpp Interface.hpp InterfaceStringVector.cpp InterfaceStringVector.hpp InterfaceStringList.cpp InterfaceStringList.hpp)