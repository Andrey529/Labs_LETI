#ifndef KURS_FUNCTIONS_H
#define KURS_FUNCTIONS_H
#include <fstream>
#include <iostream>


//void inputAllData(std::fstream &f_countStamps,std::fstream &f_infLetter,
//                  std::fstream &f_oldAndNewRates, std::fstream &f_log, std::fstream &f_result);
//void outputAllData(std::fstream &f_log, std::fstream &f_result);
bool openFiles(std::wfstream &f_countStamps,std::wfstream &f_infLetter,
               std::wfstream &f_oldAndNewRates, std::wfstream &f_log, std::wfstream &f_result);

#endif //KURS_FUNCTIONS_H
