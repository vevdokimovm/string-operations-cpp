#include "StringVector.hpp"
#include "StringList.hpp"
#include <cassert>
#include <iostream>


void test_dynamic_array_basics()
{
    DynamicArray<int> arr(5);
    arr[0] = 3;
    arr[1] = 3;
    arr[2] = 3;
    arr[3] = 3;
    arr[4] = 3;
    for(size_t i = 0; i < arr.GetSize(); ++i){
        assert(arr[i] == 3);
    }

    // copy constructor and operator==
    DynamicArray<int> arr2 = arr;
    assert(arr == arr2);
    std::cout << "TEST1 : COMPLETE\n";
}

void test_dynamic_array_operations()
{
    DynamicArray<int> arr(5);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    DynamicArray<int> arr2(6);
    arr2[0] = 1;
    arr2[1] = 2;
    arr2[2] = 3;
    arr2[3] = 4;
    arr2[4] = 5;
    arr2[5] = 6;

    arr.Append(6);

    assert(arr == arr2);
    std::cout << "TEST2 : COMPLETE\n";
}

void test_array_sequence_basics()
{
    ArraySequence<int> seq(3);
    seq[0] = 3;
    seq[1] = 3;
    seq[2] = 3;
    for (size_t i = 0; i < seq.GetSize(); ++i) assert(seq[i] == 3);

    std::cout << "TEST3 : COMPLETE\n";
}

void test_array_sequence_operations()
{
    ArraySequence<int> arr(5);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    ArraySequence<int> arr2(6);
    arr2[0] = 1;
    arr2[1] = 2;
    arr2[2] = 3;
    arr2[3] = 4;
    arr2[4] = 5;
    arr2[5] = 6;

    arr2.PopBack();

    assert(arr == arr2);
    std::cout << "TEST4 : COMPLETE\n";
}


void test_list_basics()
{
    // const-val constructor
    List<int> list;
    list.Prepend(3);
    list.Prepend(3);
    list.Prepend(3);
    list.Prepend(3);

    for(size_t i = 0; i < list.GetSize(); ++i){
        assert(list[i] == 3);
    }

    // copy constructor and operator==
    List<int> list2 = list;
    assert(list == list2);
    std::cout << "TEST5 : COMPLETE\n";
}

void test_list_operations()
{
    List<int> list;
    list.Prepend(1);
    list.Prepend(2);
    list.Prepend(3);
    list.Prepend(4);
    list.Prepend(5);

    List<int> list2;
    list2.Prepend(1);
    list2.Prepend(2);
    list2.Prepend(3);
    list2.Prepend(4);
    list2.Prepend(5);
    list2.Prepend(6);

    list.Prepend(6);

    assert(list == list2);
    std::cout << "TEST6 : COMPLETE\n";
}

void test_list_sequence_basics()
{
    // const-val constructor
    ListSequence<int> list;
    list.Prepend(3);
    list.Prepend(3);
    list.Prepend(3);
    list.Prepend(3);

    for(size_t i = 0; i < list.GetSize(); ++i){
        assert(list[i] == 3);
    }

    // copy constructor and operator==
    ListSequence<int> list2 = list;
    assert(list == list2);
    std::cout << "TEST7 : COMPLETE\n";
}

void test_list_sequence_operations()
{
    ListSequence<int> list;
    list.Prepend(1);
    list.Prepend(2);
    list.Prepend(3);
    list.Prepend(4);
    list.Prepend(5);

    ListSequence<int> list2;
    list2.Prepend(1);
    list2.Prepend(2);
    list2.Prepend(3);
    list2.Prepend(4);
    list2.Prepend(5);
    list2.Prepend(6);

    list.Prepend(6);

    assert(list == list2);
    std::cout << "TEST8 : COMPLETE\n";
}


int main(){
    test_dynamic_array_basics();
    test_dynamic_array_operations();
    test_array_sequence_basics();
    test_array_sequence_operations();
    test_list_basics();
    test_list_operations();
    test_list_sequence_basics();
    test_list_sequence_operations();
}
