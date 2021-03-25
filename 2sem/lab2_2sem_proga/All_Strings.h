#ifndef LAB2_2SEM_PROGA_ALL_STRINGS_H
#define LAB2_2SEM_PROGA_ALL_STRINGS_H

const unsigned len_str = 5;    // ������������ ����� ������ � �����
const unsigned number_str = 5; //������������ ���������� ����� � �����

class All_Strings{
    char string[number_str][len_str+1];
    int Number; // ����������� ���������� ����� � �����
    char Mark;  // ������
public:
    void setStr(unsigned row,unsigned column, char s){ // ������ ������ ������� column � ������ row
        string[row][column] = s;
    }
    char getStr(unsigned row, unsigned column){        // �������� ������� ��� �������� column � ������ row
        return string[row][column];
    }
    void setMark_in_string(unsigned row, unsigned column){  // ��������� ������� � ����� ������ ��� ������� row
        string[row][column] = Mark;
    }
    void setMark(char s){                              // ������������� ������
        Mark = s;
    }
    char getMark(){                                    // �������� �������� �������
        return Mark;
    }
    int getNumber(){                                   // �������� ���������� ����� � �����
        return Number;
    }
    void setNumber(unsigned row){
        Number = row;
    }
};

#endif //LAB2_2SEM_PROGA_ALL_STRINGS_H
