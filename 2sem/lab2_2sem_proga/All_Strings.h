#ifndef LAB2_2SEM_PROGA_ALL_STRINGS_H
#define LAB2_2SEM_PROGA_ALL_STRINGS_H

const unsigned len_str = 5;    // максимальная длина строки в блоке
const unsigned number_str = 5; // максимальное количество строк в блоке

class string{
    char str[len_str+1];
public:
    void setSymbol(unsigned column, char s){
        str[column] = s;
    }
    char getSymbol(unsigned column){
        return str[column];
    }
    void setMark_in_this_str(unsigned column, char Mark){
        str[column] = Mark;
    }
};

class All_Strings{
    string str[number_str];
    int Number; // количество строк в блоке
    char Mark;  // маркер
public:
    void setStr(unsigned row,unsigned column, char s){ // установить символ под номером column в строку под номером row
        str[row].setSymbol(column,s);
    }
    char getStr(unsigned row, unsigned column){        // получить символ под номером column в строке row
        return str[row].getSymbol(column);
    }
    void setMark_in_string(unsigned row, unsigned column){  // установить маркер в строку под номером row
        str[row].setMark_in_this_str(column,Mark);
    }
    void setMark(char s){                              // установить маркер
        Mark = s;
    }
    char getMark(){                                    // узнать какой маркер установлен
        return Mark;
    }
    int getNumber(){                                   // узнать количество строк в блоке
        return Number;
    }
    void setNumber(unsigned row){                      // задать количество строк в блоке
        Number = row;
    }
};

#endif //LAB2_2SEM_PROGA_ALL_STRINGS_H