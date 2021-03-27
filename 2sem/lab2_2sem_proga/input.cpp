#include "All_Strings.h"
#include "Situations.h"
#include <fstream>
#include <iostream>

void perevod_new_line(std::fstream* f_in){
    char s = '!';
    while((s != '\n') && (!f_in->eof())){
        s = f_in->get();
    }
}

Situations input_bloc(std::fstream* f_in,All_Strings* txt, const int coordinates[2], Situations* status){

    // перевод блока по вертикали
    f_in->seekg(0,std::ios::beg);
    for(int i=0; i<(5*coordinates[0]); i++){
        perevod_new_line(f_in);
    }

    txt->setNumber(0);
    // считывание строки
    for(int row=0; row<5; row++){ // проход по строкам

        if(*(status+row) == Situations::GOOG){   // если в прошлом блоке данная строка не кончилась

            f_in->seekg(5*coordinates[1],std::ios::cur);  // перевод курсора в строке до позиции для считывания очередного
            // блока справа

            //изза /n и /r неправильно переводится курсор для перемещения строк в блоке
            if(row == 1) f_in->seekg(-3);
            else if(row == 2) f_in->seekg(-2);
            else if(row == 3) f_in->seekg(-1);


            int column=0; // индекс столбца (символа в строке)
            char s;
            while(column<5){
                s = f_in->get();
                //*f_in >> s;
                if(f_in->eof()) {             // если очередной символ в строке -- конец файла, то ставим
                    txt->setMark_in_string(row,column);    // в данную строку состояние конца файла
                    for(int i = row; i<5; i++) {            // блоки теперь могут строиться только справа
                        *(status + i) = Situations::END_OF_FILE_IN_STRING;
                    }
                    txt->setNumber(row+1);
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
                    *(status + row) = Situations::GOOG;
                    if(row != 4){
                        perevod_new_line(f_in);   // переход на новую строку после прочтения очередной строки
                    }
                }
                column++;  // переход к новому столбцу (символу в строке)
            }
        }
        txt->setNumber(row+1);
    }
    return Situations::BAD;
}


Situations perevod_bloc(const Situations *status, int* coordinates, All_Strings txt){
    for(int i=0;i<5;i++){
        if(*(status+i) == Situations::GOOG){
            std::cout << "GOOD ";
        }
        else if(*(status+i) == Situations::END_OF_FILE_IN_STRING){
            std::cout << "END ";
        }
        else if(*(status+i) == Situations::NEW_LINE){
            std::cout << "NEW_LINE ";
        }
    }
    std::cout << "\n" << coordinates[0] << ' ' << coordinates[1] << '\n';

    int count = 0;
    for(int i=0; i < txt.getNumber();i++){
        if( (*(status+i)) == Situations::NEW_LINE){
            count++;
        }
    }
    if(count == (txt.getNumber())){
        coordinates[0]++;
        coordinates[1] = 0;
        return Situations::GOOG;
    }
    if((count == (txt.getNumber()-1)) && ( ( *(status+txt.getNumber()-1) ) == Situations::END_OF_FILE_IN_STRING) ){
        return Situations::END_OF_FILE;
    }

    coordinates[1]++;
    return Situations::GOOG;
}
