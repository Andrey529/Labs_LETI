#ifndef KURS_FUNCTIONS_H
#define KURS_FUNCTIONS_H

void inputAllData();
bool openFiles(std::fstream &f_countStamps,std::fstream &f_infLetter,
               std::fstream &f_oldAndNewRates, std::fstream f_log, std::fstream f_result);

#endif //KURS_FUNCTIONS_H
