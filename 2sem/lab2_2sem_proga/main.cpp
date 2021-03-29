
#include <iostream>
#include <fstream>
#include "All_Strings.h"
#include "Functions.h"
#include "Situations.h"

int main(){

    std::fstream f_in, f_out;
    setlocale(0,"rus");

    const unsigned nameFile = 255;
    char name_input[nameFile];
    char name_output[nameFile];
    std::cout << "Введите расположения файла с данными:\n";
    //std::cin >> name_input;                     // C:\Users\andre\CLionProjects\leti_progs\2sem\lab2_2sem_proga\data.txt

    f_in.open(/*name_input*/ "/home/andrey/Projects/Labs_LETI/2sem/lab2_2sem_proga/data.txt",std::ios::in);
    if(f_in.bad()){
        std::cout << "Невозможно открыть файл для ввода данных.";
    }
    else{
        std::cout << "Результаты будут выведены в файл." << std::endl;
        std::cout << "Введите расположения файла, куда необходимо вывести результаты:\n";
        //std::cin >> name_output;                // C:\Users\andre\CLionProjects\leti_progs\2sem\lab2_2sem_proga\result.txt
        f_out.open(/*name_output*/ "/home/andrey/Projects/Labs_LETI/2sem/lab2_2sem_proga/result.txt",std::ios::out);

        if(f_out.bad()){
            std::cout << "Невозможно вывести результаты в файл." << std::endl;
            f_in.close();
            return -1;
        }
        else{
            All_Strings txt;
            int count_sentences = 0;
            Situations flag = Situations::GOOG;

            char s = '@';
            std::cout << "Введите маркер:";
            //std::cin >> s;
            txt.setMark(s);
            int coordinates[2] = {0,0};
            Situations status[5] = {Situations::GOOG, Situations::GOOG,Situations::GOOG,Situations::GOOG,Situations::GOOG};


            do{
                input_bloc(&f_in,&txt,coordinates,status);
                count_sentences += search_count_sentences(&txt);
                vivod_bloc(f_out,&txt,coordinates);
                flag = perevod_bloc(status, coordinates,txt);
            }
            while (flag != Situations::END_OF_FILE);
            output_result(f_out, count_sentences);
        }
    }

    return 0;
}
