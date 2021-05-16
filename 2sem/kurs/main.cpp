#include "./headers/functions/functions.h"
#include "./headers/countStamps/listOfCountStamps.h"
#include "./headers/informationAboutLetters/listOfLetters.h"
int main() {
    setlocale(LC_ALL,"ru_RU.UTF-8");
    std::wfstream f_countStamps, f_oldAndNewRates, f_log, f_infLetter, f_result;
    openFiles(f_countStamps, f_infLetter, f_oldAndNewRates,f_log,f_result);

    countOfStamps countOfStamp(f_countStamps,f_log);
    countOfStamp.outputCountOfStampsInFileAndInConsole(f_result,f_log);

    listOfLetters letters(f_infLetter,f_log);
    letters.outputListOfLettersInConsoleAndInFile(f_result,f_log);


    return 0;
}