#include <iostream>
#include "All_Strings.h"
#include <fstream>

void vivod_bloc(std::fstream& f_out, All_Strings* txt, int coordinates[2]){

    std::cout << "Вывод блока с координатами: (" << coordinates[0] << ", " << coordinates[1] << ")" << std::endl;
    for(int row=0;row<5;row++){
        int column = 0;
        while(txt->getStr(row,column) != txt->getMark()){
            std::cout << txt->getStr(row,column) << ' ';
            column++;
        }
        std::cout << std::endl;
    }

    f_out << "Вывод блока с координатами: (" << coordinates[0] << ", " << coordinates[1] << ")" << std::endl;
    for(int row=0;row<5;row++){
        int column = 0;
        while(txt->getStr(row,column) != txt->getMark()){
            f_out << txt->getStr(row,column) << ' ';
            column++;
        }
        txt->setMark_in_string(row,0);
        f_out << std::endl;
    }
}



void output_result(std::fstream& f_out, int sentence){
    std::cout << "В данном тексте всего " << sentence;
    if( (sentence%10 == 0) || ( ((sentence%10)>=5) && ((sentence%10)<=9) ) ) std::cout << " предложений.";
    else if( ( ((sentence%10)>=2) && ((sentence%10)<=4) ) && ((sentence%100)!=12) &&
             ((sentence%100)!=13) && ((sentence%100)!=14) ) std::cout << " предложения.";
    else if( ((sentence%10)==1) && ((sentence%100)!=11) ) std::cout << " предложение.";
    else if( ((sentence%100)>=11) && ((sentence%100)<=14) ) std::cout << " предложений.";

    f_out << "В данном тексте всего " << sentence;
    if( (sentence%10 == 0) || ( ((sentence%10)>=5) && ((sentence%10)<=9) ) ) f_out << " предложений.";
    else if( ( ((sentence%10)>=2) && ((sentence%10)<=4) ) && ((sentence%100)!=12) &&
             ((sentence%100)!=13) && ((sentence%100)!=14) ) f_out << " предложения.";
    else if( ((sentence%10)==1) && ((sentence%100)!=11) ) f_out << " предложение.";
    else if( ((sentence%100)>=11) && ((sentence%100)<=14) ) f_out << " предложений.";
}
