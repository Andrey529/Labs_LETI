#include <iostream>
#include "functions.h"
int main() {

    std::fstream f_in1, f_in2, f_out;
    representation();
    if(checkFilesIsOpen(f_in1, f_in2, f_out)){
        ListOfStrings list1(f_in1);
        ListOfStrings list2(f_in2);
        if(list1.listNotEmpty() && list2.listNotEmpty()){ // if all 2 text entered
            list1.outputListInConsole();
            list1.outputListInFile(f_out);
            std::cout << "---------------------------------" << std::endl;
            f_out << "---------------------------------" << std::endl;
            list2.outputListInConsole();
            list2.outputListInFile(f_out);
        }
        else if(list1.listNotEmpty()){ // if first text entered, but second did not
            list1.outputListInConsole();
            list1.outputListInFile(f_out);
        }
        else if(list2.listNotEmpty()){ // if second text entered, but first did not
            list2.outputListInConsole();
            list2.outputListInFile(f_out);
        }
        else{ // if noone text entered
            std::cout << "Not" << std::endl;
        }

        f_in1.close();
        f_in2.close();
        f_out.close();
    }
    return 0;
}