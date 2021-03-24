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

    // ������� ����� �� ���������
    f_in->seekg(0,std::ios::beg);
    for(int i=0; i<(5*coordinates[0]); i++){
        perevod_new_line(f_in);
    }

    // ���������� ������
    for(int row=0; row<5; row++){ // ������ �� �������

        if(*(status+row) == Situations::GOOG){   // ���� � ������� ����� ������ ������ �� ���������

            f_in->seekg(5*coordinates[1],std::ios::cur);  // ������� ������� � ������ �� ������� ��� ���������� ����������
                                                            // ����� ������
            int column=0; // ������ ������� (������� � ������)
            char s;
            while(column<5){
                s = f_in->get();

                if(f_in->eof()) {             // ���� ��������� ������ � ������ -- ����� �����, �� ������
                    txt->setMark_in_string(row,column);    // � ������ ������ ��������� ����� �����
                    for(int i = row; i<5; i++) {            // ����� ������ ����� ��������� ������ ������
                        *(status + i) = Situations::END_OF_FILE_IN_STRING;
                    }
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
                    *(status+row) = Situations::GOOG;
                }
                column++;  // ������� � ������ ������� (������� � ������)
            }

        }
        perevod_new_line(f_in);   // ������� �� ����� ������ ����� ��������� ��������� ������

    }
    return Situations::BAD;
}


Situations perevod_bloc(const Situations *status, int* coordinates){


    return Situations::END_OF_FILE;
}

void vivod_bloc(std::fstream& f_out, All_Strings* txt, int coordinates[2]){

    std::cout << "����� ����� � ������������: (" << coordinates[0] << ", " << coordinates[1] << ")" << std::endl;
    for(int row=0;row<5;row++){
        for(int column=0; column<6;column++){
            std::cout << txt->getStr(row,column) << ' ';
        }
        std::cout << '\n';
    }

    f_out << "����� ����� � ������������: (" << coordinates[0] << ", " << coordinates[1] << ")" << std::endl;
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
    std::cout << "� ��������� ������ ����� " << sentence;
    if( (sentence%10 == 0) || ( ((sentence%10)>=5) && ((sentence%10)<=9) ) ) std::cout << " �����������." << std::endl << std::endl;
    else if( ( ((sentence%10)>=2) && ((sentence%10)<=4) ) && ((sentence%100)!=12) &&
             ((sentence%100)!=13) && ((sentence%100)!=14) ) std::cout << " �����������." << std::endl << std::endl;
    else if( ((sentence%10)==1) && ((sentence%100)!=11) ) std::cout << " �����������." << std::endl << std::endl;
    else if( ((sentence%100)>=11) && ((sentence%100)<=14) ) std::cout << " �����������." << std::endl << std::endl;

    f_out << "� ��������� ������ ����� " << sentence;
    if( (sentence%10 == 0) || ( ((sentence%10)>=5) && ((sentence%10)<=9) ) ) f_out << " �����������." << std::endl << std::endl;
    else if( ( ((sentence%10)>=2) && ((sentence%10)<=4) ) && ((sentence%100)!=12) &&
             ((sentence%100)!=13) && ((sentence%100)!=14) ) f_out << " �����������." << std::endl << std::endl;
    else if( ((sentence%10)==1) && ((sentence%100)!=11) ) f_out << " �����������." << std::endl << std::endl;
    else if( ((sentence%100)>=11) && ((sentence%100)<=14) ) f_out << " �����������." << std::endl << std::endl;

}