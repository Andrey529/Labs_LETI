#include <iostream>
#include <fstream>
#include "header.h"
#include "Functions.h"

int main() {

    std::fstream f_in, f_out;
    setlocale(0,"rus");
    const unsigned nameFile = 255;  // максимальная длина имени файла
    char name_input[nameFile];      // для входного файла с данными
    char name_output[nameFile];     // для вывода результатов
    std::cout << "Введите расположения файла с данными:\n";
    //std::cin >> name_input;                     // /home/andrey/Projects/Labs_LETI/2sem/lab2_2sem_proga/data.txt
                                                  // C:\Users\andre\CLionProjects\leti_progs\2sem\lab3\text-files\data.txt
    f_in.open(/*name_input*/"C:\\Users\\andre\\CLionProjects\\leti_progs\\2sem\\lab3\\text-files\\data.txt",std::ios::in);
    if(f_in.bad()){
        std::cout << "Невозможно открыть файл для ввода данных.";
    }
    else{
        std::cout << "Результаты будут выведены в файл." << std::endl;
        std::cout << "Введите расположения файла, куда необходимо вывести результаты:\n";
        //std::cin >> name_output;                // /home/andrey/Projects/Labs_LETI/2sem/lab2_2sem_proga/result.txt
                                                  // C:\Users\andre\CLionProjects\leti_progs\2sem\lab3\text-files\result.txt
        f_out.open(/*name_output*/"C:\\Users\\andre\\CLionProjects\\leti_progs\\2sem\\lab3\\text-files\\result.txt", std::ios::out);

        if (f_out.bad()) {
            std::cout << "Невозможно вывести результаты в файл." << std::endl;
            f_in.close();
        }
        else {

            elementList *head;
            head = nullptr;
            inputList(f_in, &head);


            f_in.close();
            f_out.close();
        }
    }
    return 0;
}