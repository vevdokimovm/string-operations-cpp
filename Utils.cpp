//
// Created by Vasiliy Evdokimov on 12.05.2020.
//

#include "Utils.hpp"


std::string const INDEX_OUT_OF_RANGE = "ERROR: Index out of range asdfasf \n";
std::string const NEGATIVE_SIZE = "ERROR : Size can't be negative \n";
std::string const EMPTY_CONTAINER = "ERROR : Empty container \n";
std::string const START_BIGGER_THAN_END = "ERROR : Start bigger than end \n";

size_t const MAX_STRING_SIZE = 1000;


// **** Error Handling ****

void IsExceptionOutOfRange(size_t i, size_t size){
    if (i < 0 || i >= size) throw std::out_of_range(INDEX_OUT_OF_RANGE);
}

void IsExceptionLength(size_t size, size_t pivot){
    if (size < pivot){
        if (pivot == 0) throw std::length_error(NEGATIVE_SIZE);
        else if (pivot == 1) throw std::length_error(EMPTY_CONTAINER);
    }
}

void IsEndBiggerStart(size_t start, size_t end){
    if (start > end) throw std::logic_error(START_BIGGER_THAN_END);
}