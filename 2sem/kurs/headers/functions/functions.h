#ifndef KURS_FUNCTIONS_H
#define KURS_FUNCTIONS_H
#include <fstream>
#include <iostream>
#include "../countStamps/listOfCountStamps.h"
#include "../informationAboutLetters/listOfLetters.h"
#include "../oldAndNewRatesForLetters/listOfOldAndNewRates.h"

void outputAllData(std::wfstream &f_log, std::wfstream &f_result, countOfStamps *countOfStamps,
                   listOfLetters *infLetters, listOfOldAndNewRatesForLetters *rates);
bool openFiles(std::wfstream &f_countStamps,std::wfstream &f_infLetter,
               std::wfstream &f_oldAndNewRates, std::wfstream &f_log, std::wfstream &f_result);
bool allDataWasInputed(countOfStamps *countOfStamps,listOfLetters *infLetters, listOfOldAndNewRatesForLetters *rates);
void calculationValues(listOfLetters *infLetters, listOfOldAndNewRatesForLetters *rates, std::wfstream &f_log);
#endif //KURS_FUNCTIONS_H
