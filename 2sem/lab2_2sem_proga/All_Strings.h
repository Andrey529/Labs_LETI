#ifndef LAB2_2SEM_PROGA_ALL_STRINGS_H
#define LAB2_2SEM_PROGA_ALL_STRINGS_H

const unsigned len_str = 5;    // максимальная длина строки в блоке
const unsigned number_str = 5; //максимальное количество строк в блоке

class All_Strings{
    char string[number_str][len_str+1];
    int Number; // фактическое количество строк в блоке
    char Mark;  // маркер
public:
    void setStr(unsigned row,unsigned column, char s){ // вводим символ индекса column в строку row
        string[row][column] = s;
    }
    char getStr(unsigned row, unsigned column){        // получаем элемент под индексом column в строке row
        return string[row][column];
    }
    void setMark_in_string(unsigned row, unsigned column){  // установка маркера в конец строки под номером row
        string[row][column] = Mark;
    }
    void setMark(char s){                              // устанавливаем маркер
        Mark = s;
    }
    char getMark(){                                    // получить значение маркера
        return Mark;
    }
    int getNumber(){                                   // получить количество строк в блоке
        return Number;
    }
    void setNumber(unsigned row){
        Number = row;
    }
};

#endif //LAB2_2SEM_PROGA_ALL_STRINGS_H
