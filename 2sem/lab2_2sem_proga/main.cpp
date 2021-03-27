// 2) разобраться с вводом символов в следующих блоках
// 3) разобраться с переводом строк при считывании блока, в котором меньше 5 строк
// 4) разобраться с конечным блоком. В строчке с концом файла все символы присутствуют (5 штук).
// 5) сделать представления программы (кто написал, формулировка задания)
// 6) комментарии проставить
// 7) отредачить все на читабельность и некретичные ошибки


#include <iostream>
#include <fstream>
#include "All_Strings.h"
#include "Functions.h"
#include "Situations.h"

int main(){

    std::fstream f_in, f_out;
    setlocale(0,"rus");

    const unsigned nameFile = 255; // максимальный размер для имени файла
    char name_input[nameFile]; // имя файла где хранятся данные (текст)
    char name_output[nameFile]; // имя файла куда выводится результат

    std::cout << "Введите имя файла с исходным текстом:\n";
    //std::cin >> name_input;                     // C:\Users\andre\CLionProjects\leti_progs\2sem\lab2_2sem_proga\data.txt

    f_in.open(/*name_input*/ "C:\\Users\\andre\\CLionProjects\\leti_progs\\2sem\\lab2_2sem_proga\\data.txt",std::ios::in);
    if(f_in.bad()){
        std::cout << "Произошла ошибка при открытии файла для ввода текста.";
    }
    else{
        std::cout << "Результаты будут выведены в файл." << std::endl;
        std::cout << "Введите имя файла для вывода результатов:\n";
        //std::cin >> name_output;                // C:\Users\andre\CLionProjects\leti_progs\2sem\lab2_2sem_proga\result.txt
        f_out.open(/*name_output*/ "C:\\Users\\andre\\CLionProjects\\leti_progs\\2sem\\lab2_2sem_proga\\result.txt",std::ios::out);
        if(f_out.bad()){
            std::cout << "Нет возможности сформировать файл с результатом." << std::endl;
            f_in.close();
            return -1;
        }
        else{
            All_Strings txt;
            int count_sentences = 0;
            Situations flag = Situations::GOOG;

            // ввод маркера
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