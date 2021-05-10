#ifndef KURS_FUNCTIONS_H
#define KURS_FUNCTIONS_H
#include <fstream>
#include <iostream>
#include "../countStamps/listOfCountStamps.h"


void inputAllData(std::fstream &f_countStamps,std::fstream &f_infLetter,
                  std::fstream &f_oldAndNewRates, std::fstream &f_log, std::fstream &f_result);
//void outputAllData(std::fstream &f_log, std::fstream &f_result);
bool openFiles(std::fstream &f_countStamps,std::fstream &f_infLetter,
               std::fstream &f_oldAndNewRates, std::fstream &f_log, std::fstream &f_result);

#endif //KURS_FUNCTIONS_H
