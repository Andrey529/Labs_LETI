/*
 * Выполнил: студент группы 0302 Блюдин А.И.
 * Формулировка задания: подсчитать количество предложений в тексте
 * если любое из них может быть окончено 3 знаками препинания (".", "!", "?").
 * */

#include <iostream>
#include <fstream>
#include "All_Strings.h"
#include "Functions.h"
#include "Situations.h"

int main(){

    std::fstream f_in, f_out;
    setlocale(0,"rus");

    const unsigned nameFile = 255;  // максимальная длина имени файла
    char name_input[nameFile];      // для входного файла с данными
    char name_output[nameFile];     // для вывода результатов
    std::cout << "Введите расположения файла с данными:\n";
    std::cin >> name_input;                     // /home/andrey/Projects/Labs_LETI/2sem/lab2_2sem_proga/data.txt

    f_in.open(name_input,std::ios::in);
    if(f_in.bad()){
        std::cout << "Невозможно открыть файл для ввода данных.";
    }
    else{
        std::cout << "Результаты будут выведены в файл." << std::endl;
        std::cout << "Введите расположения файла, куда необходимо вывести результаты:\n";
        std::cin >> name_output;                // /home/andrey/Projects/Labs_LETI/2sem/lab2_2sem_proga/result.txt
        f_out.open(name_output,std::ios::out);

        if(f_out.bad()){
            std::cout << "Невозможно вывести результаты в файл." << std::endl;
            f_in.close();
            return -1;
        }
        else{
            char s;
            s = f_in.peek();
            if(s != -1){
                All_Strings txt;
                int count_sentences = 0;
                Situations flag = Situations::GOOG;

                std::cout << "Введите маркер:";
                std::cin >> s;
                txt.setMark(s);
                std::cout << std::endl;
                int coordinates[2] = {0,0};
                Situations status[5] = {Situations::GOOG, Situations::GOOG,Situations::GOOG,Situations::GOOG,Situations::GOOG};

                privetstvie(f_out);
                for(int i=0; i<5; i++){
                    txt.setMark_in_string(i,0);
                }
                std::cout << "===============Контрольный вывод текста===============" << std::endl << std::endl;
                f_out << "===============Контрольный вывод текста===============" << std::endl << std::endl;

                do{
                    input_bloc(&f_in,&txt,coordinates,status);
                    count_sentences += search_count_sentences(&txt);
                    vivod_bloc(f_out,&txt,coordinates);
                    flag = perevod_bloc(status, coordinates,txt);
                }
                while (flag != Situations::END_OF_FILE);
                output_result(f_out, count_sentences);
            }
            else{
                std::cout << "Файл с данными пустой." << std::endl;
                f_out << "Файл с данными пустой." << std::endl;
            }
            f_in.close();
            f_out.close();
        }
    }
    return 0;
}