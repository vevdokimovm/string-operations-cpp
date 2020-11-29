//
// Created by Vasiliy Evdokimov on 20.05.2020.
//

#include "StringList.hpp"

// **** Constructors ****

StringL::StringL()
    : string_() {}

StringL::StringL(char const *pCString)
    : string_(pCString, strlen(pCString)) {}

StringL::StringL(ListSequence<char> const &rList)
    : string_(rList) {}


// ** Copy Constructor **

StringL::StringL(StringL const &rString)
    : string_(rString.GetString()) {}


// **** Destructor ****

// Set to default


// **** Getters ****

ListSequence<char> StringL::GetString() const { return string_; }

ListSequence<char> & StringL::GetString() { return string_; }

char StringL::GetFirst() const { return GetString().GetFirst(); }

char & StringL::GetFirst() { return GetString().GetFirst(); }

char StringL::GetLast() const { return GetString().GetLast(); }

char & StringL::GetLast() { return GetString().GetLast(); }

size_t StringL::GetSize() const { return GetString().GetSize(); }


// **** Setters ****

void StringL::SetSize(size_t newSize) { GetString().SetSize(newSize); }


// **** Operators ****

StringL StringL::operator+(const StringL &rString) { return GetString() + rString.GetString(); }

char StringL::operator[](size_t i) const { return GetString()[i]; }

char & StringL::operator[](size_t i) { return GetString()[i]; }


// **** Comparison ****

bool operator==(StringL const &rStrA, StringL const &rStrB){
    return rStrA.GetString() == rStrB.GetString();
}

bool operator!=(StringL const &rStrA, StringL const &rStrB){
    return rStrA.GetString() != rStrB.GetString();
}

// ** Assignment Operator **

StringL & StringL::operator=(StringL const &rString){
    GetString() = rString.GetString();
    return *this;
}

std::istream & operator>>(std::istream &rIs, StringL &rString){
    char *pCString = new char[MAX_STRING_SIZE + 100];
    rIs >> pCString;
    rString = StringL(pCString);
    return rIs;
}

std::ostream & operator<<(std::ostream &rOs, StringL const &rString){
    rOs << "--- Your string : ";
    for (size_t i = 0; i < rString.GetSize(); ++i) rOs << rString[i];
    return rOs << std::endl;
}


// **** Modifiers ****

void StringL::Prepend(char c) { GetString().Prepend(c); }

void StringL::InsertAt(size_t i, char c) { GetString().InsertAt(i, c); }

void StringL::Append(char c) { GetString().Append(c); }

void StringL::PopFirst() { GetString().PopFirst(); }

void StringL::EraseAt(size_t i) { GetString().EraseAt(i); }

void StringL::PopBack() { GetString().PopBack(); }