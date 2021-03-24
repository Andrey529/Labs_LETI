#include <fstream>
#include "All_Strings.h"
#include <iostream>
#include "Situations.h"

void perevod_new_line(std::fstream* f_in){
    char s = '!';
    while(s != '\n'){
        s = f_in->get();
    }
}

Situations input_bloc(std::fstream* f_in,All_Strings* txt, const int coordinates[2], Situations* status){

    // перевод блока по вертикали
    f_in->seekg(0,std::ios::beg);
    for(int i=0; i<(5*coordinates[0]); i++){
        perevod_new_line(f_in);
    }

    // считывание строки
    for(int row=0; row<5; row++){ // проход по строкам

        if(*(status+row) == Situations::GOOG){   // если в прошлом блоке данна€ строка не кончилась

            f_in->seekg(5*coordinates[1],std::ios::cur);  // перевод курсора в строке до позиции дл€ считывани€ очередного
                                                            // блока справа
            int column=0; // индекс столбца (символа в строке)
            char s;
            while(column<5){
                s = f_in->get();

                if(f_in->eof()) {             // если очередной символ в строке -- конец файла, то ставим
                    txt->setMark_in_string(row,column);    // в данную строку состо€ние конца файла
                    for(int i = row; i<5; i++) {            // блоки теперь могут строитьс€ только справа
                        *(status + i) = Situations::END_OF_FILE_IN_STRING;
                    }
                    return Situations::END_OF_FILE;
                }                                                // так как ниже строк нету

                else if(s == '\n') {                    // если очередной символ -- переход к новой строке
                    txt->setMark_in_string(row,column);  // дальше блоки справа не будут считывать данную строку
                    *(status+row) = Situations::NEW_LINE;
                    break;
                }
                else{
                    txt->setStr(row,column,s);        // считываем очередной элемент в строке
                }
                if(column == 4){                      // если в строке были считаны все 5 символов =>
                    txt->setMark_in_string(row,column+1); // => строка не кончилась и не конец файла
                    *(status+row) = Situations::GOOG;
                }
                column++;  // переход к новому столбцу (символу в строке)
            }

        }
        perevod_new_line(f_in);   // переход на новую строку после прочтени€ очередной строки

    }
    return Situations::BAD;
}


Situations perevod_bloc(const Situations *status, int* coordinates){


    return Situations::END_OF_FILE;
}

void vivod_bloc(std::fstream& f_out, All_Strings* txt, int coordinates[2]){

    std::cout << "¬ывод блока с координатами: (" << coordinates[0] << ", " << coordinates[1] << ")" << std::endl;
    for(int row=0;row<5;row++){
        for(int column=0; column<6;column++){
            std::cout << txt->getStr(row,column) << ' ';
        }
        std::cout << '\n';
    }

    f_out << "¬ывод блока с координатами: (" << coordinates[0] << ", " << coordinates[1] << ")" << std::endl;
    for(int row=0;row<5;row++){
        for(int column=0; column<6;column++){
            f_out << txt->getStr(row,column) << ' ';
        }
        f_out << '\n';
    }
}

int search_count_sentences(All_Strings* txt){
    int sentence = 0;
    for(int row = 0; row < 5; row++){
        int column = 0;
        while((txt->getStr(row,column)) != txt->getMark()){
            if((txt->getStr(row,column)) == '.'){
                sentence++;
            }
            else if((txt->getStr(row,column)) == '!'){
                sentence++;
            }
            else if((txt->getStr(row,column)) == '?'){
                sentence++;
            }
            column++;
        }
    }
    return sentence;
}

void output_result(std::fstream& f_out, int sentence){
    std::cout << "¬ введенном тексте всего " << sentence;
    if( (sentence%10 == 0) || ( ((sentence%10)>=5) && ((sentence%10)<=9) ) ) std::cout << " предложений." << std::endl << std::endl;
    else if( ( ((sentence%10)>=2) && ((sentence%10)<=4) ) && ((sentence%100)!=12) &&
             ((sentence%100)!=13) && ((sentence%100)!=14) ) std::cout << " предложени€." << std::endl << std::endl;
    else if( ((sentence%10)==1) && ((sentence%100)!=11) ) std::cout << " предложение." << std::endl << std::endl;
    else if( ((sentence%100)>=11) && ((sentence%100)<=14) ) std::cout << " предложений." << std::endl << std::endl;

    f_out << "¬ введенном тексте всего " << sentence;
    if( (sentence%10 == 0) || ( ((sentence%10)>=5) && ((sentence%10)<=9) ) ) f_out << " предложений." << std::endl << std::endl;
    else if( ( ((sentence%10)>=2) && ((sentence%10)<=4) ) && ((sentence%100)!=12) &&
             ((sentence%100)!=13) && ((sentence%100)!=14) ) f_out << " предложени€." << std::endl << std::endl;
    else if( ((sentence%10)==1) && ((sentence%100)!=11) ) f_out << " предложение." << std::endl << std::endl;
    else if( ((sentence%100)>=11) && ((sentence%100)<=14) ) f_out << " предложений." << std::endl << std::endl;

}