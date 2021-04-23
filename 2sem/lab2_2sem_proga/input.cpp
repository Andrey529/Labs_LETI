#include "All_Strings.h"
#include "Situations.h"
#include <fstream>
#include <iostream>

Situations input_bloc(std::fstream* f_in,All_Strings* txt, const int coordinates[2], Situations* status){

    f_in->seekg(0,std::ios::beg); // перевод каретки в начало файла

    // перевод блока по вертикали
    for(int i=0; i<(5*coordinates[0]); i++){
        char s = '!';
        while(s != '\n'){
            s = f_in->get();
        }
    }

    int row = 0;
    txt->setNumber(0); // устанавливаем количество строк в блоке = 0

    // обновления состояния блока, когда он переходит на новую строчку
    int count = 0;
    for(int i=0;i<5;i++){
        if((*(status+i)) == Situations::NEW_LINE){
            count++;
        }
    }
    if(count == 5){
        for(int i=0;i<5;i++){
            *(status+i) = Situations::GOOG;
        }
    }


    while( (row<5) ){  // проход по строкам

        if( (*(status+row)) == Situations::GOOG ){ // если в прошлом блоке данная строка была полная
                                                    // и не заканчивалась 1 символом в данной блоке

            f_in->seekg(5*coordinates[1],std::ios::cur); // переводим каретку в файле по горизонтали

            char s;
            int column = 0;
            while( (column<5) ){ // проход по элементам строки

                s = f_in->peek(); // проверяем следующий элемент

                if(s == -1){    // если на следующем символе конец файла
                    txt->setMark_in_string(row,column);
                    for(int i = row;i<5;i++){ // ставим состояние текущей и последующих строк, что конец файла
                        *(status+i) = Situations::END_OF_FILE_IN_STRING;
                    }
                    txt->setNumber(row+1);
                    return Situations::END_OF_FILE;
                }

                if(s == '\n'){   //  если следующий символ переход к новой строке
                    s = f_in->get();
                    *(status+row) = Situations::NEW_LINE; // ставим статус в этой строке, что в данном блоке конец строки
                    txt->setMark_in_string(row,column); // ставим маркер
                    break;
                }
                else{
                    s = f_in->get(); // считываем символ и записываем в блок
                    txt->setStr(row,column,s);
                }
                column++;

                if(column == 5){ // если в блоке текущая строка полностью заполнилась символами
                    txt->setMark_in_string(row,column);
                    s = f_in->peek(); // проверяем след символ после 5 в строке
                    if(s == -1){ // если конец файла, ставим состояние строки, что конец строки в данном блоке
                        *(status+row) = Situations::END_OF_FILE_IN_STRING;
                    }
                    else if(s == '\n'){ // если переход к новой строке, то строка переходит на новую в данном блоке
                        *(status+row) = Situations::NEW_LINE;
                        //f_in->seekg(-1,std::ios::cur);
                    }
                    else{
                        *(status+row) = Situations::GOOG;
                    }


                    s = '!';   // переводим строку на след строку
                    while( (s != '\n') && (f_in->peek() != -1) ){
                        s = f_in->get();
                    }
                }
            }
        }
        else if((*(status+row)) == Situations::NEW_LINE){ // если строка в предыдущем блоке перешла на новую
            char s = '!';        // переходим на следующую строку
            while(s != '\n'){
                s = f_in->get();
            }
        }
        row++;
        txt->setNumber(row);
    }
    return Situations::GOOG;
}


Situations perevod_bloc(const Situations *status, int* coordinates, All_Strings txt){

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
