//
// Created by Vasiliy Evdokimov on 21.05.2020.
//

#include <iostream>

#include "Interface.hpp"
#include "InterfaceStringVector.hpp"
#include "InterfaceStringList.hpp"
#include "StringVector.hpp"

void InterfaceString(){
    std::cout << "Hello, Dear User! Currently you're using my implementation "
                 "of C++ string!\nI hope you'll enjoy! Let's start then!\n\n";

    std::cout << "Firstly, choose which version you want to use :\n"
                 "1. String as array\n"
                 "2. String as list\n";

    StringV option = "";
    std::cin >> option;

    while (!(option == "1" || option == "2")) {
        std::cout << "\n****"
                     " Incorrect input. "
                     "Please read instructions carefully and try again! **** \n\n";
        std::cin >> option;
    }

    if (option == "1") InterfaceStringVector();
    else if (option == "2") InterfaceStringList();

}