#include <iostream>
#include <fstream>
#include "List.h"
#include "situations.h"

const unsigned nameFile = 255;  // ������������ ����� ����� �����

int main() {

    std::fstream f_in, f_out, f_replace;
    setlocale(0,"rus");
    char name_input[nameFile];      // ��� �������� ����� � �������
    char name_output[nameFile];     // ��� ������ �����������
    char name_replace[nameFile];    // ��� ������ �������� ������
    std::cout << "������� ������������ ����� � �������:\n";
    //std::cin >> name_input;                     // /home/andrey/Projects/Labs_LETI/2sem/lab2_2sem_proga/data.txt
                                                  // C:\Users\andre\CLionProjects\leti_progs\2sem\lab3\text-files\data.txt
    f_in.open(/*name_input*/"C:\\Users\\andre\\CLionProjects\\leti_progs\\2sem\\lab3\\text-files\\data.txt",std::ios::in);
    if(f_in.bad()){
        std::cout << "���������� ������� ���� ��� ����� ������.";
    }
    else{
        std::cout << "���������� ����� �������� � ����." << std::endl;
        std::cout << "������� ������������ �����, ���� ���������� ������� ����������:\n";
        //std::cin >> name_output;                // /home/andrey/Projects/Labs_LETI/2sem/lab2_2sem_proga/result.txt
                                                  // C:\Users\andre\CLionProjects\leti_progs\2sem\lab3\text-files\result.txt
        f_out.open(/*name_output*/"C:\\Users\\andre\\CLionProjects\\leti_progs\\2sem\\lab3\\text-files\\result.txt", std::ios::out);

        if (f_out.bad()) {
            std::cout << "���������� ������� ���������� � ����." << std::endl;
            f_in.close();
        }
        else{
            f_replace.open(/*name_replace*/"C:\\Users\\andre\\CLionProjects\\leti_progs\\2sem\\lab3\\text-files\\replaceElement.txt",std::ios::in);

            if(f_replace.bad()) {
                std::cout << "���������� ������ ������ ����������� �������� ������." << std::endl;
                f_in.close();
                f_out.close();
            }
            else{
                List list(&f_in);
                if(list.getHead() == nullptr){
                    // when memory did not allocate
                    std::cout << "���� � ������� ������" << std::endl;
                    f_out << "���� � ������� ������" << std::endl;
                    return -1;
                }

                else{
                    situations situation;
                    do{
                        situation = list.addNewElement(&f_in);
                        if( (!list.listNotEnd(situation)) || (list.memoryDidnotAllocate(situation)) ) {
                            break;
                        }
                    }
                    while(true);
                    list.outputList(f_out);
                    list.replaceElement(&f_replace);
                    list.outputList(f_out);
                }
                f_in.close();
                f_out.close();
                f_replace.close();
            }
        }
    }
    return 0;
}