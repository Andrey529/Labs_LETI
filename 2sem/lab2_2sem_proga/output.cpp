#include <iostream>
#include "All_Strings.h"
#include <fstream>

void vivod_bloc(std::fstream& f_out, All_Strings* txt, int coordinates[2]){

    std::cout << "����� ����� � ������������: (" << coordinates[0] << ", " << coordinates[1] << ")" << std::endl;
    for(int row=0;row<(txt->getNumber());row++){
        int column = 0;
        do{
            std::cout << txt->getStr(row,column) << ' ';
            column++;
        }
        while(txt->getStr(row,column) != txt->getMark());
        std::cout << '\n';
    }

    f_out << "����� ����� � ������������: (" << coordinates[0] << ", " << coordinates[1] << ")" << std::endl;
    for(int row=0;row<(txt->getNumber());row++){
        int column = 0;
        do{
            f_out << txt->getStr(row,column) << ' ';
            column++;
        }
        while(txt->getStr(row,column) != txt->getMark());
        f_out << '\n';
    }
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
