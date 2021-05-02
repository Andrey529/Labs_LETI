#include <iostream>
#include "functions.h"
int main() {

    std::fstream f_in1, f_in2, f_out;
    representation();
    if(checkFilesIsOpen(f_in1, f_in2, f_out)){
        ListOfStrings list1, list2;
        list1.inputList(f_in1);
//        if(text1Entered && text2Entered){ // if all 2 text entered
//
//        }
//        else if(text1Entered){ // if first text entered, but second did not
//
//        }
//        else if(text2Entered){ // if second text entered, but first did not
//
//        }
//        else{ // if noone text entered

        }
//        while(true){
//            listOfPartsString test;
//            situations flag = test.setInf(&f_in1);
//            test.getInfInConsole();
//            if(flag == situations::lastElement){
//                std::cout << 'X' << std::endl;
//            }
//            else if(flag == situations::endOfFile){
//                std::cout << "END_OF_FILE";
//                break;
//            }
//        }

        f_in1.close();
        f_in2.close();
        f_out.close();

    return 0;
}