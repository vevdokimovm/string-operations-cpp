//
// Created by Vasiliy Evdokimov on 20.05.2020.
//

#pragma once


// **** Constructors ****

template<typename T>
ListSequence<T>::ListSequence()
    : list_() {}

template<typename T>
ListSequence<T>::ListSequence(T const *pData, size_t size)
    : list_(pData, size) {}

template<typename T>
ListSequence<T>::ListSequence(List<T> const &rList)
    : list_(rList) {}


// ** Copy Constructor **

template<typename T>
ListSequence<T>::ListSequence(ListSequence<T> const &rList)
    : list_(rList.GetList()) {}


// **** Operators ****

template<typename T>
ListSequence<T> operator+(ListSequence<T> const &rListA, ListSequence<T> const &rListB){ return rListA.GetList() + rListB.GetList(); }


// ** Operator[] **

template<typename T>
T ListSequence<T>::operator[](size_t i) const { return GetList()[i]; }

template<typename T>
T & ListSequence<T>::operator[](size_t i) { return GetList()[i]; }

template<typename T>
ListSequence<T> & ListSequence<T>::operator=(ListSequence<T> const &rList){
    GetList() = rList.GetList();
    return *this;
}

// ** Input and Output

template<typename T>
std::istream & operator>>(std::istream &rIs, ListSequence<T> &rList) { return rIs >> rList.GetList(); }

template<typename T>
std::ostream & operator<<(std::ostream &rOs, ListSequence<T> const &rList) { return rOs << rList.GetList(); }


// **** Comparison ****

template<typename T>
bool operator==(ListSequence<T> const &rListA, ListSequence<T> const &rListB){
    return rListA.GetList() == rListB.GetList();
}

template<typename T>
bool operator!=(ListSequence<T> const &rListA, ListSequence<T> const &rListB){
    return !(rListA == rListB);
}

// **** Getters ****

template<typename T>
List<T> ListSequence<T>::GetList() const { return list_; }

template<typename T>
List<T> & ListSequence<T>::GetList() { return list_; }

template<typename T>
T ListSequence<T>::GetFirst() const { return GetList().GetFirst(); }

template<typename T>
T & ListSequence<T>::GetFirst() { return GetList().GetFirst(); }

template<typename T>
T ListSequence<T>::GetLast() const { return GetList().GetLast(); }

template<typename T>
T & ListSequence<T>::GetLast() {  return GetList().GetLast(); }

template<typename T>
T ListSequence<T>::GetElementData(size_t i) const { return GetList()[i]; }

template<typename T>
T & ListSequence<T>::GetElementData(size_t i) { return GetList()[i]; }

template<typename T>
size_t ListSequence<T>::GetSize() const { return GetList().GetSize(); }


// **** Setters ****

template<typename T>
void ListSequence<T>::SetSize(size_t newSize) { GetList().SetSize(newSize); }


// **** Modifiers ****

template<typename T>
void ListSequence<T>::Prepend(T data) { GetList().Prepend(data); }

template<typename T>
void ListSequence<T>::InsertAt(size_t i, T data) { GetList().InsertAt(i, data); }

template<typename T>
void ListSequence<T>::Append(T data) { GetList().Append(data); }

template<typename T>
void ListSequence<T>::PopFirst() { GetList().PopFirst(); }

template<typename T>
void ListSequence<T>::EraseAt(size_t i) { GetList().EraseAt(i); }

template<typename T>
void ListSequence<T>::PopBack() { GetList().PopBack(); }

template<typename T>
ListSequence<T> * ListSequence<T>::Concatenation(ISequence<T> *pList) { return new ListSequence<T>; }


