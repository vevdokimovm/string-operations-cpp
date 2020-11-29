//
// Created by Vasiliy Evdokimov on 20.05.2020.
//

#include "StringVector.hpp"

// **** Constructors ****

StringV::StringV()
    : string_() {}

StringV::StringV(size_t size)
    : string_(size) {}

StringV::StringV(char const *pCString)
    : string_(strlen(pCString)) {
    for (size_t i = 0; i < string_.GetSize(); ++i) string_[i] = pCString[i];
}

StringV::StringV(ArraySequence<char> const &rArray)
    : string_(rArray) {}


// ** Copy Constructor **

StringV::StringV(StringV const &rString)
    :  string_(rString.GetString()) {}


// **** Destructor ****

StringV::~StringV() = default;

// **** Getters ****

ArraySequence<char> StringV::GetString() const { return string_; }

ArraySequence<char> & StringV::GetString() { return string_; }

char StringV::GetFirst() const { return GetString().GetFirst(); }

char & StringV::GetFirst() { return GetString().GetFirst(); }

char StringV::GetLast() const { return GetString().GetLast(); }

char & StringV::GetLast() { return GetString().GetLast(); }

char * StringV::GetCString() { return GetString().GetArray().GetData(); }

size_t StringV::GetCapacity() const { return GetString().GetCapacity(); }

size_t StringV::GetSize() const { return GetString().GetSize(); }


// **** Setters ****

void StringV::SetSize(size_t newSize) { GetString().SetSize(newSize); }


// **** Comparison Operators ****

bool operator==(StringV const &rStrA, StringV const &rStrB){
    return rStrA.GetString() == rStrB.GetString();
}

bool operator!=(StringV const &rStrA, StringV const &rStrB){
    return rStrA.GetString() != rStrB.GetString();
}


// **** Operators ****

StringV StringV::operator+(const StringV &rString) { return GetString() + rString.GetString(); }

char StringV::operator[](size_t i) const { return GetString()[i]; }

char & StringV::operator[](size_t i) { return GetString()[i]; }

// ** Assigment Operator **

StringV & StringV::operator=(StringV const &rString) {
    GetString() = rString.GetString();
    return *this;
}

std::istream & operator>>(std::istream &rIs, StringV &rString) {
    char *pCString = new char[MAX_STRING_SIZE];
    rIs >> pCString;
    rString = StringV(pCString);
    return rIs;
}

std::ostream & operator<<(std::ostream &rOs, StringV const &rString) {
    rOs << "--- Your string : ";
    for (size_t i = 0; i < rString.GetSize(); ++i) rOs << rString[i];
    return rOs << std::endl;
}


// **** Modifiers ****

void StringV::Prepend(char c) { GetString().Prepend(c); }

void StringV::InsertAt(size_t i, char c) { GetString().InsertAt(i, c); }

void StringV::Append(char c) { GetString().Append(c); }

void StringV::PopFirst() { GetString().PopFirst(); }

void StringV::EraseAt(size_t i) { GetString().EraseAt(i); }

void StringV::PopBack() { GetString().PopBack(); }