//
// Created by Vasiliy Evdokimov on 20.04.2020.
//

#pragma once

#include <iostream>

static size_t const DEFAULT_CAPACITY = 300;

template<typename T>
class DynamicArray {
public:

    // **** Constructors ****

    DynamicArray();
    explicit DynamicArray(size_t);
    DynamicArray(T *, size_t);

    // ** Copy Constructor **

    DynamicArray(DynamicArray<T> const &);


    // **** Operators ****

    template<typename TT>
    friend DynamicArray<TT> operator+(DynamicArray<TT> const &, DynamicArray<TT> const &);
    DynamicArray<T> & operator=(DynamicArray<T> const &);
    T operator[](size_t) const;
    T & operator[](size_t);

    template<typename TT>
    friend std::istream & operator>>(std::istream &, DynamicArray<TT> &);

    template<typename TT>
    friend std::ostream & operator<<(std::ostream &, DynamicArray<TT> const &);


    // **** Destructor ****

    ~DynamicArray();
    void FreeData();


    // **** Getters ****

    T GetFirst() const;
    T & GetFirst();
    T GetLast() const;
    T & GetLast();
    size_t GetSize () const;
    size_t GetCapacity() const;
    T * GetData();
    T GetElem(size_t) const;
    T & GetElem(size_t);


    // **** Setters ****

    void Resize(size_t);
    void SetSize(size_t);
    void SetCapacity(size_t);
    void SetData(T *);
    void SetElement(size_t, T);


    // **** Modifiers ****

    void Prepend(T);
    void InsertAt(size_t, T);
    void Append(T);
    void PopFirst();
    void EraseAt(size_t);
    void PopBack();

private:

    // ****** Private Methods ******

    // Needed to make it easier to implement public interface \
       but they are dangerous to make public cause user \
       can by mistake change invariants

    // **** Private Utils ****

    void SwapAttributes(DynamicArray &);
    void ChangeCapacity();
    void ExpandCapacity(size_t = 2);


    // **** Member Variables ****

    size_t size_;
    size_t capacity_;
    T *data_;
};

#include "DynamicArrayImplementation.hpp"
