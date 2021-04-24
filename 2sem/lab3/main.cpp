#include <iostream>
#include <fstream>
#include "List.h"
#include "situations.h"

const unsigned nameFile = 255;  // max lenght of files

int main() {

    std::fstream f_in, f_out, f_replace;
    setlocale(0,"rus");
    std::cout << "The program was made by Andrey Blyudin, student of group 0302.\n"
              << "formulation of the task: make a list with the function of replacing a list item under some number." << std::endl;
    char name_input[nameFile];      // file with text
    char name_output[nameFile];     // file to output result of program
    char name_replace[nameFile];    // file with replacement result
    std::cout << "Enter the name of the data file (full file location):\n";
    std::cin >> name_input;                     // /home/andrey/Projects/Labs_LETI/2sem/lab3/text-files/data.txt
                                                // C:\Users\andre\CLionProjects\leti_progs\2sem\lab3\text-files\data.txt

    f_in.open(name_input,std::ios::in);
    if(f_in.bad()){
        std::cout << "Unable to open data file.";
    }
    else{
        std::cout << "The data will be input in file " << name_input << "." << std::endl;
        std::cout << "Enter the name of the file where the result will be output (full file location)." << std::endl;
        std::cin >> name_output;                // /home/andrey/Projects/Labs_LETI/2sem/lab3/text-files/result.txt
                                                  // C:\Users\andre\CLionProjects\leti_progs\2sem\lab3\text-files\result.txt

        f_out.open(name_output, std::ios::out);
        if (f_out.bad()) {
            std::cout << "Unable to open result file." << std::endl;
            f_in.close();
        }
        else{                   // /home/andrey/Projects/Labs_LETI/2sem/lab3/text-files/replaceElement.txt
            std::cout << "The results will be output in file " << name_output << "." << std::endl;
            std::cout << "Enter the name of the file where the replacement element (full file location)." << std::endl;
            std::cin >> name_replace;     // C:\Users\andre\CLionProjects\leti_progs\2sem\lab3\text-files\replaceElement.txt
            f_replace.open(name_replace,std::ios::in);

            if(f_replace.bad()) {
                std::cout << "Unable to open file with replacement element." << std::endl;
                f_in.close();
                f_out.close();
            }
            else{
                std::cout << "The replecement element will be input in file " << name_replace << "." << std::endl;
                List list;
                situations flag = list.addFirstElement(&f_in);
                if(flag == situations::emptyFile){
                    std::cout << "File with text is empty." << std::endl;
                    f_out << "File with text is empty." << std::endl;
                    return -1;
                }
                else if(flag == situations::notEnoughMemory){
                    // when memory did not allocate
                    std::cout << "Not enough memory for first element." << std::endl;
                    f_out << "Not enough memory for first element." << std::endl;
                    return -2;
                }
                else if(flag == situations::inList1Element){
                    std::cout << "------List before modification------" << std::endl;
                    f_out << "------List before modification------" << std::endl;
                    list.outputList(f_out);
                    list.replaceElement(&f_replace);
                    std::cout << "------List after modification------" << std::endl;
                    f_out << "------List after modification------" << std::endl;
                    list.outputList(f_out);
                    return 1;
                }
                else{ // when in list >= 1 elements
                    situations situation;
                    do{
                        situation = list.addNewElement(&f_in);
                        if( (!list.listNotEnd(situation)) || (list.memoryDidnotAllocate(situation)) ) {
                            break;
                        }
                    }
                    while(true);
                    std::cout << "------List before modification------" << std::endl;
                    f_out << "------List before modification------" << std::endl;
                    list.outputList(f_out);
                    list.replaceElement(&f_replace);
                    std::cout << "------List after modification------" << std::endl;
                    f_out << "------List after modification------" << std::endl;
                    list.outputList(f_out);
                }
                f_in.close();
                f_out.close();
                f_replace.close();
            }
        }
    }
    return 0;
}