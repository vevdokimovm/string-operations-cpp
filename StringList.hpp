//
// Created by Vasiliy Evdokimov on 20.05.2020.
//

#pragma once

#include "ListSequence.hpp"

class StringL {
public:

    // **** Constructors ****

    StringL();
    //explicit StringL(size_t);
    StringL(char const *);
    StringL(ListSequence<char> const &);


    // ** Copy Constructor **

    StringL(StringL const &);


    // **** Destructor ****

    ~StringL() = default;


    // **** Getters ****

    ListSequence<char> GetString() const;
    ListSequence<char> & GetString();
    char GetFirst() const;
    char & GetFirst();
    char GetLast() const;
    char & GetLast();
    size_t GetSize() const;


    // **** Setters ****

    void SetSize(size_t);


    // **** Operators ****

    StringL operator+(StringL const &);
    char operator[](size_t) const;
    char & operator[](size_t);

    // **** Boolean Operators ****

    friend bool operator==(StringL const &, StringL const &);
    friend bool operator!=(StringL const &, StringL const &);


    // ** Assignment Operator **

    StringL & operator=(StringL const &);

    friend std::istream & operator>>(std::istream &, StringL &);
    friend std::ostream & operator<<(std::ostream &, StringL const &);


    // **** Modifiers ****

    void Prepend(char);
    void InsertAt(size_t, char);
    void Append(char);
    void PopFirst();
    void EraseAt(size_t);
    void PopBack();


private:

    ListSequence<char> string_;

};
