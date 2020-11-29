//
// Created by Vasiliy Evdokimov on 12.05.2020.
//

#pragma once

#include <iostream>
#include <stdexcept>


// **** Macros ****

// Helps me debug my code. Yeah I know... There is a debugger \
but I don't know how to use him so this is much easier

#define INFO(msg) std::cout << (#msg) << " = " << (msg) <<  std::endl;
#define PRINT(msg) std::cout << (msg) << std::endl;


// **** TypeDefs ****

using ull = unsigned long long;
using ll = long long;


// **** Constants ****

extern std::string const INDEX_OUT_OF_RANGE;
extern std::string const NEGATIVE_SIZE;
extern std::string const EMPTY_CONTAINER;
extern std::string const START_BIGGER_THAN_END;

extern size_t const MAX_STRING_SIZE;


// **** Error Handling ****

void IsExceptionOutOfRange(size_t, size_t);
void IsExceptionLength(size_t, size_t = 0);
void IsEndBiggerStart(size_t, size_t);

// **** Input Features ****
