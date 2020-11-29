//
// Created by Vasiliy Evdokimov on 12.05.2020.
//

#pragma once

#include <stdexcept>
#include <string>
#include "Utils.hpp"


// **** Constructors ****

template<typename T>
List<T>::List()
    : size_(0), head_(nullptr) {}

template<typename T>
List<T>::List(T const *pData, size_t size)
    : size_(size)
    {
        Node **ppCur_node = &head_;
        for (size_t i = 0; i != size; ++i){
            *ppCur_node = new Node;
            (*ppCur_node)->data_ = pData[i];
            ppCur_node = &((*ppCur_node)->next_);
        }
        if (size == 0) head_ = nullptr;
    }

// ** Copy Constructor **

template<typename T>
List<T>::List(List<T> const &rList)
    : size_(rList.size_)
    {
        Node **ppCur_node = &head_;
        Node * const *ppCur_node_copy = &rList.head_;
        for (size_t i = 0; i != size_; ++i){
            *ppCur_node = new Node;
            (*ppCur_node)->data_ = (*ppCur_node_copy)->data_;
            ppCur_node = &((*ppCur_node)->next_);
            ppCur_node_copy = &((*ppCur_node_copy)->next_);
        }
    }


// **** Operators ****

template<typename T>
List<T> operator+(List<T> a, List<T> b){
    List<T> *pNew_list = a.GetSubList(0, a.GetSize());
    typename List<T>::Node *pCur_node_a = &(pNew_list->GetNode(pNew_list->GetSize() - 1));
    typename List<T>::Node *pCur_node_b = b.GetHead();

    for (size_t i = 0; i < b.GetSize(); ++i){
        typename List<T>::Node *pNew_next = new typename List<T>::Node(pCur_node_b->GetData());
        pCur_node_a->SetNext(pNew_next);
        pCur_node_a = pCur_node_a->GetNext();
        pCur_node_b = pCur_node_b->GetNext();
    }

    pNew_list->SetSize(a.GetSize() + b.GetSize());

    return *pNew_list;
}

template<typename T>
List<T> & List<T>::operator=(List<T> const &rList){
    if (this != &rList) List<T>(rList).SwapAttributes(*this);
    return *this;
}

template<typename T>
std::istream & operator>>(std::istream &rIs, List<T> &rList){
    std::cout << "Enter number of elements in your list : ";
    ll n = 0;
    rIs >> n;
    if (n < 0) throw std::length_error(NEGATIVE_SIZE);
    std::cout << std::endl;

    rList = List<T>();
    std::cout << "--- Now enter your elements one by one each"
                 "on a separate line ---\n";
    for (size_t i = 0; i < n; ++i){
        T data = T(0);
        std::cout << "Node " << i << " : ";
        rIs >> data;
        rList.Append(data);
    }

    return rIs;
}

template<typename T>
std::ostream & operator<<(std::ostream &rOs, List<T> const &rList) {
    rOs << "**** Your list **** \n\n";
    typename List<T>::Node *pCur_node = rList.GetHead();
    for (size_t i = 0; i < rList.GetSize(); ++i){
        rOs << "Node " << i << " : " << pCur_node->GetData() << std::endl;
        pCur_node = pCur_node->GetNext();
    }
    rOs << std::endl;
    return rOs;
}

template<typename T>
T List<T>::operator[](size_t i) const { return GetElementData(i); }

template<typename T>
T & List<T>::operator[](size_t i) { return GetElementData(i); }


// **** Comparison ****

template<typename T>
bool operator==(List<T> const &rListA, List<T> const &rListB){
    if (rListA.GetSize() != rListB.GetSize()) return false;

    for (size_t i = 0; i < rListA.GetSize(); ++i){
        if (rListA[i] != rListB[i]) return false;
    }

    return true;
}

template<typename T>
bool operator!=(List<T> const &rListA, List<T> const &rListB){
    return !(rListA == rListB);
}

// **** Destructor ****

template<typename T>
List<T>::~List(){
    if (head_ != nullptr) delete head_;
    head_ = nullptr;
}


// **** Getters ****

template<typename T>
size_t List<T>::GetSize() const { return size_; }

template<typename T>
T List<T>::GetElementData(size_t i) const {
    IsExceptionOutOfRange(i, GetSize());

    Node *pCur_node = GetHead();
    for (size_t iElem = 0; iElem < i; ++iElem){
        pCur_node = pCur_node->GetNext();
    }

    return pCur_node->GetData();
}

template<typename T>
T & List<T>::GetElementData(size_t i) {
    IsExceptionOutOfRange(i, GetSize());

    Node *pCur_node = GetHead();
    for (size_t iElem = 0; iElem < i; ++iElem){
        pCur_node = pCur_node->GetNext();
    }

    return pCur_node->GetData();
}

template<typename T>
T List<T>::GetFirst() const {
    IsExceptionLength(GetSize(), 1);
    return GetElementData(0);
}

template<typename T>
T & List<T>::GetFirst() {
    IsExceptionLength(GetSize(), 1);
    return GetElementData(0);
}

template<typename T>
T List<T>::GetLast() const {
    IsExceptionLength(GetSize(), 1);
    return GetElementData(GetSize() - 1);
}

template<typename T>
T & List<T>::GetLast() {
    IsExceptionLength(GetSize(), 1);
    return GetElementData(GetSize() - 1);
}


// Creates unique list so that changing one of them \
doesn't affect the other (I tested this)

template<typename T>
List<T> * List<T>::GetSubList(size_t start, size_t end) {
    IsEndBiggerStart(start + 1, end);
    IsExceptionOutOfRange(start, GetSize());
    IsExceptionOutOfRange(end, GetSize() + 1);

    List<T> *pNew_list = new List;
    Node *pCur_node = &GetNode(start);
    for (size_t i = 0; i < end - start; ++i){
        pNew_list->Append(pCur_node->GetData());
        pCur_node = pCur_node->GetNext();
    }

    return pNew_list;
}

// **** Setters ****

template<typename T>
void List<T>::SetSize(size_t newSize) { size_ = newSize; }


// **** Modifiers ****

template<typename T>
void List<T>::InsertAt(size_t i, T data){
    IsExceptionOutOfRange(i, GetSize() + 1);

    if (i == 0){
        Node *pNew_head = new Node(data, GetHead());
        SetHead(pNew_head);
    }
    else {
        Node *pCur_node = &GetNode(i - 1);
        Node *pNext_node = pCur_node->GetNext();
        pCur_node->SetNext(new Node(data, pNext_node));
        //pCur_node->next_ = new Node(data, pNext_node);
    }

    SetSize(GetSize() + 1);
}

template<typename T>
void List<T>::Prepend(T data) { InsertAt(0, data); }

template<typename T>
void List<T>::Append(T data) { InsertAt(GetSize(), data); }

template<typename T>
void List<T>::EraseAt(size_t i){
    IsExceptionOutOfRange(i, GetSize());

    if (i == 0 || GetSize() == 1) {
        SetHead(GetHead()->GetNext());
    }
    else {
        Node *pCur_node = &GetNode(i - 1);
        pCur_node->SetNext(pCur_node->GetNext()->GetNext());
        //pCur_node->GetNext()->~Node();
    }

    SetSize(GetSize() - 1);
}

template<typename T>
void List<T>::PopFirst() { EraseAt(0); }

template<typename T>
void List<T>::PopBack() { EraseAt(GetSize() - 1); }

// ****** Private Methods ******


// **** Getters ****

template<typename T>
typename List<T>::Node * List<T>::GetHead() const { return head_; }

template<typename T>
typename List<T>::Node & List<T>::GetNode(size_t i){
    IsExceptionOutOfRange(i, GetSize());

    Node *pCur_node = GetHead();
    for (size_t iElem = 0; iElem < i; ++iElem){
        pCur_node = pCur_node->GetNext();
    }

    return *pCur_node;
}

template<typename T>
typename List<T>::Node List<T>::GetNode(size_t i) const {
    IsExceptionOutOfRange(i, GetSize());

    Node *pCur_node = GetHead();
    for (size_t iElem = 0; iElem < i; ++iElem){
        pCur_node = pCur_node->GetNext();
    }

    return *pCur_node;
}


// **** Setters ****

template<typename T>
void List<T>::SetHead(Node *pNewHead) {
    head_ = pNewHead;
}


// **** Utils ****

template<typename T>
void List<T>::SwapAttributes(List<T> &rList) {
    std::swap(head_, rList.head_);
    std::swap(size_, rList.size_);
}