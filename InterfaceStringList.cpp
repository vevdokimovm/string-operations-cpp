//
// Created by Vasiliy Evdokimov on 05.06.2020.
//

#include <iostream>

#include "InterfaceStringList.hpp"
#include "StringList.hpp"

void InterfaceStringList(){
    StringL s = "";
    StringL option = "";

    std::cin >> s;
    std::cout << s;
    while(true){
        std::cout << "Menu : \n"
                     "1. Concatenate\n"
                     "2. Add symbol\n"
                     "3. Erase symbol\n"
                     "4. Get symbol\n"
                     "5. Get size\n"
                     "6. Quit\n";

        std::cin >> option;

        if (option == "1"){
            StringL s2 = "";
            std::cout << "Enter string : ";
            std::cin >> s2;
            s = s + s2;
        }
        else if (option == "2"){
            char c = '\0';
            size_t pos = 0;
            std::cout << "Enter new symbol : ";
            std::cin >> c;
            std::cout << "Enter his position : ";
            std::cin >> pos;
            s.InsertAt(pos, c);
        }
        else if (option == "3"){
            size_t pos = 0;
            std::cout << "Enter position you want to delete : ";
            std::cin >> pos;
            s.EraseAt(pos);
        }
        else if (option == "4"){
            size_t pos = 0;
            std::cout << "Enter position you want to check : ";
            std::cin >> pos;
            std::cout << s[pos];
        }
        else if (option == "5"){
            std::cout << s.GetSize();
        }
        else if (option == "6"){
            break;
        }
        else {
            std::cout << "\n****"
                         " Incorrect input. "
                         "Please read instructions carefully and try again! **** \n\n";
            continue;
        }

        std::cout << s;
    }
}

