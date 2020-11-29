//
// Created by Vasiliy Evdokimov on 18.05.2020.
//

#pragma once

// **** Constructor ****

template<typename T>
ArraySequence<T>::ArraySequence()
    : array_() {}

template<typename T>
ArraySequence<T>::ArraySequence(size_t size)
    : array_(size) {}

template<typename T>
ArraySequence<T>::ArraySequence(T *pData, size_t size)
    : array_(pData, size) {}

template<typename T>
ArraySequence<T>::ArraySequence(DynamicArray<T> const &rDArray)
    : array_(rDArray) {}


// ** Copy Constructor **

template<typename T>
ArraySequence<T>::ArraySequence(ArraySequence<T> const &rArray)
    : array_(rArray.GetArray()) {}


// **** Destructor ****

template<typename T>
ArraySequence<T>::~ArraySequence() = default;


// **** Comparison Operators ****

template<typename T>
bool operator==(ArraySequence<T> const &rArrA, ArraySequence<T> const &rArrB){
    return rArrA.GetArray() == rArrB.GetArray();
}

template<typename T>
bool operator!=(ArraySequence<T> const &rArrA, ArraySequence<T> const &rArrB){
    return rArrA.GetArray() != rArrB.GetArray();
}


// **** Operators ****

template<typename T>
ArraySequence<T> operator+(ArraySequence<T> const &rArrayA, ArraySequence<T> const &rArrayB) {
    return rArrayA.GetArray() + rArrayB.GetArray();
}

template<typename T>
ArraySequence<T> & ArraySequence<T>::operator=(ArraySequence<T> const &rArray){
    GetArray() = rArray.GetArray();
    return *this;
}

template<typename T>
T ArraySequence<T>::operator[](size_t i) const { return GetArray()[i]; }

template<typename T>
T & ArraySequence<T>::operator[](size_t i) { return GetArray()[i]; }

template<typename T>
std::istream & operator>>(std::istream &rIs, ArraySequence<T> &rArray) { return std::cin >> rArray.GetArray(); }

template<typename T>
std::ostream & operator<<(std::ostream &rOs, ArraySequence<T> const &rArray) { return std::cout << rArray.GetArray(); }


// **** Getters ****

template<typename T>
DynamicArray<T> ArraySequence<T>::GetArray() const { return array_; }

template<typename T>
DynamicArray<T> & ArraySequence<T>::GetArray() { return array_; }

template<typename T>
T ArraySequence<T>::GetFirst() const { return GetArray().GetFirst(); };

template<typename T>
T & ArraySequence<T>::GetFirst() { return GetArray().GetFirst(); }

template<typename T>
T ArraySequence<T>::GetLast() const { return GetArray().GetLast(); }

template<typename T>
T & ArraySequence<T>::GetLast() { return GetArray().GetLast(); }

template<typename T>
T ArraySequence<T>::GetElementData(size_t i) const { return GetArray().GetElem(i); }

template<typename T>
T & ArraySequence<T>::GetElementData(size_t i) { return GetArray().GetElem(i); }

template<typename T>
size_t ArraySequence<T>::GetSize() const { return GetArray().GetSize(); }

template<typename T>
size_t ArraySequence<T>::GetCapacity() const { return GetArray().GetCapacity(); }

template<typename T>
ArraySequence<T> * ArraySequence<T>::GetSubSequence(size_t start, size_t end) const {
    return new ArraySequence<T>;
}


// **** Setters ****

template<typename T>
void ArraySequence<T>::Resize(size_t newSize) { GetArray().Resize(newSize); }

template<typename T>
void ArraySequence<T>::SetSize(size_t newSize) { GetArray().SetSize(newSize); }

template<typename T>
void ArraySequence<T>::SetCapacity(size_t newCapacity) { GetArray().SetCapacity(newCapacity); }

template<typename T>
void ArraySequence<T>::SetData(T *pNewData) { GetArray().SetData(pNewData); }

template<typename T>
void ArraySequence<T>::SetElement(size_t i, T data) { GetArray().SetElement(i, data); }


// **** Modifiers ****

template<typename T>
void ArraySequence<T>::Prepend(T data) { GetArray().Prepend(data); }

template<typename T>
void ArraySequence<T>::InsertAt(size_t i, T data) { GetArray().InsertAt(i, data); }

template<typename T>
void ArraySequence<T>::Append(T data) { GetArray().Append(data); }

template<typename T>
void ArraySequence<T>::PopFirst() { GetArray().PopFirst(); }

template<typename T>
void ArraySequence<T>::EraseAt(size_t i) {
    GetArray().EraseAt(i);
}

template<typename T>
void ArraySequence<T>::PopBack() { GetArray().PopBack(); }

template<typename T>
ArraySequence<T> * ArraySequence<T>::Concatenation(ISequence<T> *pArray) { return new ArraySequence<T>; }


// **** Utils ****

//