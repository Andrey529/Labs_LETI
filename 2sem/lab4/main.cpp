#include <iostream>
#include "functions.h"
int main() {
    std::fstream f_in1, f_in2, f_out;
    representation();
    if(checkFilesIsOpen(f_in1, f_in2, f_out)){
        ListOfStrings list1(f_in1);  // text in 1 file
        ListOfStrings list2(f_in2);  // text in 2 file
        if(list1.listNotEmpty() && list2.listNotEmpty()){ // if all 2 text entered
            list1.outputListInConsoleAndInFile(f_out);
            std::cout << "---------------------------------" << std::endl;
            f_out << "---------------------------------" << std::endl;
            list2.outputListInConsoleAndInFile(f_out);

            ListOfStrings list3 = ListOfStrings::differenceList1AndList2(list1,list2);
            if(list3.listNotEmpty()){
                std::cout << "---------------------------------" << std::endl;
                f_out << "---------------------------------" << std::endl;
                std::cout << "A new list is formed from the difference between the first and second lists." << std::endl;
                f_out << "A new list is formed from the difference between the first and second lists." << std::endl;

                list3.outputListInConsoleAndInFile(f_out);
            }
            else{
                std::cout << "Аfter running the program, an empty list was formed" << std::endl;
                f_out << "Аfter running the program, an empty list was formed" << std::endl;
            }

        }
        else if(list1.listNotEmpty()){ // if first text entered, but second did not
            list1.outputListInConsoleAndInFile(f_out);
            std::cout << "---------------------------------" << std::endl;
            f_out << "---------------------------------" << std::endl;
            std::cout << "A new list is formed from the first list." << std::endl;
            f_out << "A new list is formed from the first list." << std::endl;
            ListOfStrings list3(list1);
            list3.outputListInConsoleAndInFile(f_out);
        }
        else if(list2.listNotEmpty()){ // if second text entered, but first did not
            list2.outputListInConsoleAndInFile(f_out);
            std::cout << "---------------------------------" << std::endl;
            f_out << "---------------------------------" << std::endl;
            std::cout << "A new list is formed from the second list." << std::endl;
            f_out << "A new list is formed from the second list." << std::endl;
            ListOfStrings list3(list2);
            list3.outputListInConsoleAndInFile(f_out);
        }
        else{ // if noone text entered
            std::cout << "It is impossible to form a new list." << std::endl;
            f_out  << "It is impossible to form a new list." << std::endl;
        }
        f_in1.close();
        f_in2.close();
        f_out.close();
    }
    return 0;
}