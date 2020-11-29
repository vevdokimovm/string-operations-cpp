//
// Created by Vasiliy Evdokimov on 17.05.2020.
//

#pragma once

#include <iostream>

template<typename T>
class ISequence {
public:

    ISequence() = default;
    virtual ~ISequence() = default;


    // **** Operators ****

    //virtual ISequence<T> * operator+(ISequence<T>) = 0;
    virtual T operator[](size_t) const =  0;
    virtual T & operator[](size_t) = 0;


    // **** Getters ****

    virtual T GetFirst() const = 0;
    virtual T & GetFirst() = 0;
    virtual T GetLast() const = 0;
    virtual T & GetLast() = 0;
    virtual T GetElementData(size_t) const = 0;
    virtual T & GetElementData(size_t) = 0;
    virtual size_t GetSize() const = 0;
    //virtual ISequence<T> * GetSubSequence(size_t, size_t) const = 0;


    // **** Modifiers ****

    virtual void Prepend(T) = 0;
    virtual void InsertAt(size_t, T) = 0;
    virtual void Append(T) = 0;
    virtual void PopFirst() = 0;
    virtual void EraseAt(size_t) = 0;
    virtual void PopBack() = 0;
    virtual ISequence<T> * Concatenation(ISequence<T> *) = 0;

};
