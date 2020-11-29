//
// Created by Vasiliy Evdokimov on 20.05.2020.
//

#pragma once

#include "ArraySequence.hpp"


class StringV {
public:

    // **** Constructors ****

    StringV();
    explicit StringV(size_t);
    StringV(char const *);
    StringV(ArraySequence<char> const &);

    // ** Copy Constructor **

    StringV(StringV const &);


    // **** Destructor ****

    ~StringV();


    // **** Getters ****

    ArraySequence<char> GetString() const;
    ArraySequence<char> & GetString();
    char GetFirst() const;
    char & GetFirst();
    char GetLast() const;
    char & GetLast();
    char * GetCString();
    size_t GetCapacity() const;
    size_t GetSize() const;


    // **** Setters ****

    void SetSize(size_t);


    // **** Comparison Operators ****

    friend bool operator==(StringV const &, StringV const &);

    friend bool operator!=(StringV const &, StringV const &);


    // **** Operators ****

    StringV operator+(StringV const &);
    char operator[](size_t) const;
    char & operator[](size_t);


    // ** Assigment Operator **

    StringV & operator=(StringV const &);

    friend std::istream & operator>>(std::istream &, StringV &);
    friend std::ostream & operator<<(std::ostream &, StringV const &);


    // **** Modifiers ****

    void Prepend(char);
    void InsertAt(size_t, char);
    void Append(char);
    void PopFirst();
    void EraseAt(size_t);
    void PopBack();


private:

    ArraySequence<char> string_;

};
