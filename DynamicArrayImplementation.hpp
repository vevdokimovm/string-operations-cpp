//
// Created by Vasiliy Evdokimov on 10.05.2020.
//

#pragma once

#include <stdexcept>
#include <string>
#include "Utils.hpp"


// **** Constructors ****

template<typename T>
DynamicArray<T>::DynamicArray()
    : size_(0), capacity_(DEFAULT_CAPACITY), data_(nullptr) {}

template<typename T>
DynamicArray<T>::DynamicArray(size_t size)
    : size_(size), capacity_(std::max(size_ + DEFAULT_CAPACITY, size_ * 2)), data_(new T[capacity_]) {
        IsExceptionLength(size_);
    }

template<typename T>
DynamicArray<T>::DynamicArray(T* data, size_t numOfElements)
    : size_(numOfElements), capacity_(std::max(size_ + DEFAULT_CAPACITY, size_ * 2)), data_(data) {
        IsExceptionLength(size_);
    }


// ** Copy Constructor **

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T> const &rDarr)
    : size_(rDarr.size_), capacity_(rDarr.capacity_), data_(new T[rDarr.size_])
    {
        IsExceptionLength(size_);
        for (size_t i = 0; i != size_; ++i) GetData()[i] = rDarr[i];
    }


// **** Comparison Operators ****

template<typename T>
bool operator==(DynamicArray<T> const &rDarrA, DynamicArray<T> const &rDarrB){
    if (rDarrA.GetSize() != rDarrB.GetSize()) return false;

    size_t n = rDarrA.GetSize();
    for (size_t i = 0; i < n; ++i) if (rDarrA[i] != rDarrB[i]) return false;

    return true;
}

template<typename T>
bool operator!=(DynamicArray<T> const &rDarrA, DynamicArray<T> const &rDarrB){
    return !(rDarrA == rDarrB);
}


// **** Operators ****

template<typename T>
DynamicArray<T> operator+(DynamicArray<T> const &rDarrA, DynamicArray<T> const &rDarrB){
    DynamicArray<T> Darr(rDarrA.GetSize() + rDarrB.GetSize());
    for (size_t i = 0; i < rDarrA.GetSize(); ++i) Darr[i] = rDarrA[i];
    for (size_t i = 0; i < rDarrB.GetSize(); ++i) Darr[i + rDarrA.GetSize()] = rDarrB[i];

    return Darr;
}

// ** Assignment Operator **

template<typename T>
DynamicArray<T> & DynamicArray<T>::operator=(DynamicArray const &rDarr){
    if (this != &rDarr) DynamicArray(rDarr).SwapAttributes(*this);
    return *this;
}

// ** [] Operator const and non-const version **

template<typename T>
T DynamicArray<T>::operator[](size_t i) const {
    IsExceptionOutOfRange(i, GetSize());
    return data_[i];
}

template<typename T>
T & DynamicArray<T>::operator[](size_t i) {
    IsExceptionOutOfRange(i, GetSize());
    return data_[i];
}

template<typename T>
std::istream & operator>>(std::istream &rIs, DynamicArray<T> &rArray){
    ll size = 0;
    std::cout << "Enter size of your array : ";
    rIs >> size;
    if (size < 0) throw std::length_error(NEGATIVE_SIZE);
    std::cout << std::endl;

    rArray = DynamicArray<T>(size);
    std::cout << "--- Now enter your elements one by one each"
                 "on a separate line ---\n";
    for (size_t i = 0; i < size; ++i){
        T data = T(0);
        std::cout << "Element " << i << " : ";
        rIs >> data;
        rArray[i] = data;
    }

    return rIs;
}

template<typename T>
std::ostream & operator<<(std::ostream &rOs, DynamicArray<T> const &rArray){
    rOs << "**** Your array **** \n\n";
    for (size_t i = 0; i < rArray.GetSize(); ++i) rOs << "[" << i << "] = " << rArray[i] << std::endl;
    rOs << std::endl;
    return rOs;
}


// **** Destructor ****

template<typename T>
DynamicArray<T>::~DynamicArray(){
    delete [] data_;
    data_ = nullptr;
}

template<typename T>
void DynamicArray<T>::FreeData(){
    if (GetData()) {
        delete [] GetData();
        data_ = nullptr;
    }
}


// **** Getters ****

template<typename T>
T DynamicArray<T>::GetFirst() const { return GetElem(0); }

template<typename T>
T & DynamicArray<T>::GetFirst() { return GetElem(0); }

template<typename T>
T DynamicArray<T>::GetLast() const { return GetElem(GetSize() - 1); }

template<typename T>
T & DynamicArray<T>::GetLast() { return GetElem(GetSize() - 1); }

template<typename T>
size_t DynamicArray<T>::GetSize() const { return size_; }

template<typename T>
size_t DynamicArray<T>::GetCapacity() const { return capacity_; }

template<typename T>
T* DynamicArray<T>::GetData() { return data_; }

template<typename T>
T DynamicArray<T>::GetElem(size_t i) const {
    IsExceptionOutOfRange(i, GetSize());
    return data_[i];
}

template<typename T>
T & DynamicArray<T>::GetElem(size_t i) {
    IsExceptionOutOfRange(i, GetSize());
    return data_[i];
}


// **** Setters ****

template<typename T>
void DynamicArray<T>::Resize(size_t const newSize){
    IsExceptionLength(newSize);
    if (newSize > GetCapacity()) ExpandCapacity(newSize / GetCapacity() + 1);
    else SetSize(newSize);
}

template<typename T>
void DynamicArray<T>::SetSize(size_t const newSize) { size_ = newSize; }

template<typename T>
void DynamicArray<T>::SetCapacity(size_t const newCapacity) { capacity_ = newCapacity; }

template<typename T>
void DynamicArray<T>::SetData(T* newData) {
    FreeData();
    data_ = newData;
}

template<typename T>
void DynamicArray<T>::SetElement(size_t i, T value) { GetElem(i) = value; }


// **** Modifiers ****

template<typename T>
void DynamicArray<T>::InsertAt(size_t i, T data) {
    IsExceptionOutOfRange(i, GetSize() + 1);

    if (GetSize() + 1 > GetCapacity()) ExpandCapacity();

    SetSize(GetSize() + 1);
    T store = data;
    for (size_t iElem = i; iElem < GetSize(); ++iElem){
        T temp = GetElem(iElem);
        GetElem(iElem) = store;
        store = temp;
    }
}

template<typename T>
void DynamicArray<T>::Prepend(T data) { InsertAt(0, data); }

template<typename T>
void DynamicArray<T>::Append(T data) { InsertAt(GetSize(), data); }

template<typename T>
void DynamicArray<T>::EraseAt(size_t i) {
    IsExceptionOutOfRange(i, GetSize());

    if (GetSize() == 0) return;

    for (size_t iElem = i; iElem < GetSize() - 1; ++iElem){
        T store = GetElem(iElem + 1);
        GetElem(iElem) = store;
    }
    SetSize(GetSize() - 1);
}

template<typename T>
void DynamicArray<T>::PopFirst() { EraseAt(0); }

template<typename T>
void DynamicArray<T>::PopBack() { EraseAt(GetSize() - 1); }


// **** Private Methods ****

template<typename T>
void DynamicArray<T>::SwapAttributes(DynamicArray &rDarr){
    std::swap(size_, rDarr.size_);
    std::swap(capacity_, rDarr.capacity_);
    std::swap(data_, rDarr.data_);
}

template<typename T>
void DynamicArray<T>::ExpandCapacity(size_t koeff){
    SetCapacity(GetCapacity() * std::max(koeff, 2UL));
    T *pNew_data = new T[GetCapacity()];
    for (size_t iElem = 0; iElem != GetSize(); ++iElem)
        pNew_data[iElem] = GetElem(iElem);

    SetData(pNew_data);
}