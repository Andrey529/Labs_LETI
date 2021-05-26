#ifndef KURS_FUNCTIONS_H
#define KURS_FUNCTIONS_H
#include <fstream>
#include <iostream>
#include "../countStamps/listOfCountStamps.h"
#include "../informationAboutLetters/listOfLetters.h"
#include "../oldAndNewRatesForLetters/listOfOldAndNewRates.h"
#include "../stickeredStamps/stickeredStamps.h"

void outputAllData(std::wfstream &f_log, std::wfstream &f_result, countOfStamps *countOfStamps,
                   listOfLetters *infLetters, listOfOldAndNewRatesForLetters *rates);
bool openFiles(std::wfstream &f_countStamps,std::wfstream &f_infLetter,
               std::wfstream &f_oldAndNewRates, std::wfstream &f_log, std::wfstream &f_result);
bool allDataWasInputed(countOfStamps *countOfStamps,listOfLetters *infLetters, listOfOldAndNewRatesForLetters *rates);
void calculationValues(listOfLetters *infLetters, listOfOldAndNewRatesForLetters *rates, std::wfstream &f_log);

bool newStateOfStickeredStampsIsBetter(listOfLetters *listOfLettersOld, listOfLetters *listOfLettersNew);

listOfLetters *sortLetters(std::wfstream &f_log, bool firstState, countOfStamps *countOfStamp, listOfLetters *listLetters,
                           listOfLetters *bestListLetters, stickekeredStamps *stickerStamps, stickekeredStamps *bestStickerStamps);
#endif //KURS_FUNCTIONS_H
