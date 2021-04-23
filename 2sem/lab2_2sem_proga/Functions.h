#include "All_Strings.h"
#include <fstream>
#include "Situations.h"
#ifndef LAB2_2SEM_PROGA_FUNCTIONS_H
#define LAB2_2SEM_PROGA_FUNCTIONS_H

Situations input_bloc(std::fstream* f_in, All_Strings* txt, const int coordinates[2], Situations* status); // ввод блока
Situations perevod_bloc(const Situations* status, int* coordinates, All_Strings txt);                  // перевод блока по файлу
void vivod_bloc(std::fstream& f_out, All_Strings* txt, int coordinates[2]);                            // вывод очередного блока
int search_count_sentences(All_Strings* txt);                                                   // поиск количества предложений
void output_result(std::fstream& f_out, int sentence);                                       // вывод результата работы программы
void privetstvie(std::fstream& f_out);                                                       // вывод приветствия
#endif //LAB2_2SEM_PROGA_FUNCTIONS_H