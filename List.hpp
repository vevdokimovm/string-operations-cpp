//
// Created by Vasiliy Evdokimov on 12.05.2020.
//

#pragma once

#include <iostream>


template<typename T>
class List {
public:

    // **** Constructors ****

    List();
    List(T const *, size_t);

    // ** Copy Constructor

    List(List<T> const &);


    // **** Operators ****

    template<typename TT>
    friend List<TT> operator+(List<TT>, List<TT>);

    List<T> & operator=(List<T> const &);

    template<typename TT>
    friend std::istream & operator>>(std::istream &, List<TT> &);

    template<typename TT>
    friend std::ostream & operator<<(std::ostream &, List<TT> const &);

    T operator[](size_t) const;
    T & operator[](size_t);


    // **** Destructor ****

    ~List();


    // **** Getters ****

    size_t GetSize() const;

    T GetFirst() const;
    T & GetFirst();
    T GetLast() const;
    T & GetLast();
    T GetElementData(size_t) const;
    T & GetElementData(size_t);

    List<T> * GetSubList(size_t, size_t);


    // **** Setters ****

    void SetSize(size_t);


    // **** Modifiers ****

    void Prepend(T);
    void InsertAt(size_t, T);
    void Append(T);
    void PopFirst();
    void EraseAt(size_t);
    void PopBack();

private:

    struct Node;

    // ****** Private Methods ******


    // **** Getters ****

    Node * GetHead() const;
    Node GetNode(size_t) const;
    Node & GetNode(size_t);


    // **** Setters ****

    void SetHead(Node *);


    // **** Utils ****

    void SwapAttributes(List<T> &);


    // **** Member Variables ****

    struct Node {

        // **** Constructors ****

        Node()
            : data_(T(0)), next_(nullptr) {}

        explicit Node(T data, Node *next = nullptr)
            : data_(data), next_(next) {}


        // **** Destructor ****
        // If I uncomment this than program will free \
        nodes twice. First in List destructor then \
        in Node destructor which will cause error

        ~Node(){
            //if (GetNext() != nullptr) delete next_;
            next_ = nullptr;
        }


        // **** Output ****

//        template<typename TT>
//        friend std::ostream & List<T>::operator<<(std::ostream &, List<TT>);


        // **** Getters ****

        T GetData() const { return data_; }
        T & GetData() { return data_; }
        Node * GetNext() { return next_; }


        // **** Setters ****

        void SetNext(Node *pNewNext) {
            //if (next_ != nullptr) delete next_;
            next_ = pNewNext;
        }


        // **** Member Variables ****

        T data_;
        Node *next_;
    };


    size_t size_;
    Node *head_;
};


#include "ListImplementation.hpp"