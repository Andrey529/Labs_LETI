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

    // ������� ����� �� ���������
    f_in->seekg(0,std::ios::beg);
    for(int i=0; i<(5*coordinates[0]); i++){
        perevod_new_line(f_in);
    }

    txt->setNumber(0);
    // ���������� ������
    for(int row=0; row<5; row++){ // ������ �� �������

        if(*(status+row) == Situations::GOOG){   // ���� � ������� ����� ������ ������ �� ���������

            f_in->seekg(5*coordinates[1],std::ios::cur);  // ������� ������� � ������ �� ������� ��� ���������� ����������
            // ����� ������

            //���� /n � /r ����������� ����������� ������ ��� ����������� ����� � �����
            if(row == 1) f_in->seekg(-3);
            else if(row == 2) f_in->seekg(-2);
            else if(row == 3) f_in->seekg(-1);


            int column=0; // ������ ������� (������� � ������)
            char s;
            while(column<5){
                s = f_in->get();
                //*f_in >> s;
                if(f_in->eof()) {             // ���� ��������� ������ � ������ -- ����� �����, �� ������
                    txt->setMark_in_string(row,column);    // � ������ ������ ��������� ����� �����
                    for(int i = row; i<5; i++) {            // ����� ������ ����� ��������� ������ ������
                        *(status + i) = Situations::END_OF_FILE_IN_STRING;
                    }
                    txt->setNumber(row+1);
                    return Situations::END_OF_FILE;
                }                                                // ��� ��� ���� ����� ����

                else if(s == '\n') {                    // ���� ��������� ������ -- ������� � ����� ������
                    txt->setMark_in_string(row,column);  // ������ ����� ������ �� ����� ��������� ������ ������
                    *(status+row) = Situations::NEW_LINE;
                    break;
                }
                else{
                    txt->setStr(row,column,s);        // ��������� ��������� ������� � ������
                }
                if(column == 4){                      // ���� � ������ ���� ������� ��� 5 �������� =>
                    txt->setMark_in_string(row,column+1); // => ������ �� ��������� � �� ����� �����
                    *(status + row) = Situations::GOOG;
                    if(row != 4){
                        perevod_new_line(f_in);   // ������� �� ����� ������ ����� ��������� ��������� ������
                    }
                }
                column++;  // ������� � ������ ������� (������� � ������)
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
