/*
 * 1) переводим блок по вертикали
 * 2) смотрим на состояние текущей строки в предыдущем блоке
 *          а) если GOOD, то считываем строку
 *
 *          б) переходим к новой строке
 * */




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
    for(int i=0; i<5*coordinates[0]; i++){
        char s = '!';
        while(s != '\n'){
            s = f_in->get();
        }
    }

    int row = 0;
    txt->setNumber(0);
    while( (row<5) ){


        if( (*(status+row)) == Situations::GOOG ){

            f_in->seekg(5*coordinates[1],std::ios::cur);

            int column = 0;
            while( (column<5) ){
                char s;
                s = f_in->get();

                if(f_in->eof()){
                    txt->setMark_in_string(row,column);
                    *(status+row) = Situations::END_OF_FILE_IN_STRING;
                    for(int i = row;i<5;i++){
                        *(status+i) = Situations::END_OF_FILE_IN_STRING;
                    }
                    txt->setNumber(row+1);
                    return Situations::END_OF_FILE;
                }

                if(s == '\n'){
                    *(status+row) = Situations::NEW_LINE;
                    txt->setMark_in_string(row,column);
                }
                else{
                    txt->setStr(row,column,s);
                }
                column++;

                if(column == 5){
                    txt->setMark_in_string(row,column);
                    s = f_in->get();
                    if(f_in->eof()){
                        *(status+row) = Situations::END_OF_FILE_IN_STRING;
                    }
                    if(s == '\n'){
                        *(status+row) = Situations::NEW_LINE;
                        f_in->seekg(-2,std::ios::cur);
                    }
                    else{
                        *(status+row) = Situations::GOOG;
                    }
                    while( (s != '\n') && (!f_in->eof()) ){
                        s = f_in->get();
                    }
                }


//                if(f_in->eof()){
//
//                }

            }

        }
        row++;
        txt->setNumber(row);

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
