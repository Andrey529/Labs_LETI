#include <iostream>
#include "LIstOfStrings.h"

void representation(){
    std::cout << "\nThe program was made by Andrey Blyudin, student of group 0302.\n"
              << "formulation of the task: form a list by including in it one"
              << " time items that are included in list 1, but are not included in list 2." << std::endl;
}

bool checkFilesIsOpen(std::fstream &f_in1, std::fstream &f_in2, std::fstream &f_out){
    const unsigned nameFile = 255;  // max lenght of files
    char name_input_firstText[nameFile];      // file with first text
    char name_input_secondText[nameFile];      // file with second text
    char name_output[nameFile];     // file to output result of program
    std::cout << "Enter the name of the data file with first text (full file location):\n";
    //std::cin >> name_input_firstText;                     // /home/andrey/Projects/Labs_LETI/2sem/lab4/text-files/text1.txt
                                                            // C:\Users\andre\CLionProjects\leti_progs\2sem\lab4\text-files\text1.txt
    f_in1.open(/*name_input_firstText*/"C:\\Users\\andre\\CLionProjects\\leti_progs\\2sem\\lab4\\text-files\\text1.txt",std::ios::in);
    if(f_in1.bad()){
        std::cout << "Unable to open data file with first text.";
        return false;
    }
    std::cout << "The first text will be input in file " << name_input_firstText << "." << std::endl;
    std::cout << "Enter the name of the data file with second text (full file location):\n";
    //std::cin >> name_input_secondText;        // /home/andrey/Projects/Labs_LETI/2sem/lab4/text-files/text2.txt
                                                // C:\Users\andre\CLionProjects\leti_progs\2sem\lab4\text-files\text2.txt
    f_in2.open(/*name_input_secondText*/"C:\\Users\\andre\\CLionProjects\\leti_progs\\2sem\\lab4\\text-files\\text2.txt", std::ios::out);
    if (f_in2.bad()) {
        std::cout << "Unable to open data file with second text.";
        f_in1.close();
        return false;
    }
    std::cout << "The second text will be input in file " << name_input_secondText << "." << std::endl;
    std::cout<< "Enter the name of the file where the result of the program will be displayed (full file location)."<< std::endl;
    //std::cin >> name_output;     // C:\Users\andre\CLionProjects\leti_progs\2sem\lab4\text-files\output.txt
                                   // /home/andrey/Projects/Labs_LETI/2sem/lab4/text-files/output.txt
    f_out.open(/*name_output*/"C:\\Users\\andre\\CLionProjects\\leti_progs\\2sem\\lab4\\text-files\\output.txt", std::ios::in);
    if (f_out.bad()) {
        std::cout << "Unable to open file where the result of the program will be displayed." << std::endl;
        f_in1.close();
        f_in2.close();
        return false;
    }
    std::cout << "The result of the program will be displayed in " << name_output << "." << std::endl <<  std::endl;
    std::cout << "===================================================================" << std::endl << std::endl;
    return true;

}

//bool inputList(std::fstream &f_in, ListOfStrings *list){
//
//    return true;
//}