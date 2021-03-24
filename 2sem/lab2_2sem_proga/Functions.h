#include "All_Strings.h"
#include <fstream>
#include "Situations.h"
#ifndef LAB2_2SEM_PROGA_FUNCTIONS_H
#define LAB2_2SEM_PROGA_FUNCTIONS_H

Situations input_bloc(std::fstream* f_in, All_Strings* txt, const int coordinates[2], Situations* status);
void perevod_new_line(std::fstream* f_in);

Situations perevod_bloc(const Situations* status, int* coordinates);

void vivod_bloc(std::fstream& f_out, All_Strings* txt, int coordinates[2]);
int search_count_sentences(All_Strings* txt);
void output_result(std::fstream& f_out, int sentence);
#endif //LAB2_2SEM_PROGA_FUNCTIONS_H