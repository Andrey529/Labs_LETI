#include "./headers/functions/functions.h"
int main() {
    setlocale(LC_ALL,"ru_RU.UTF-8");
    std::wfstream f_countStamps, f_oldAndNewRates, f_log, f_infLetter, f_result;

    openFiles(f_countStamps, f_infLetter, f_oldAndNewRates,f_log,f_result);

    auto *countOfStamp = new (std::nothrow) countOfStamps(f_countStamps,f_log);
    auto *infLetters = new (std::nothrow) listOfLetters(f_infLetter,f_log);
    auto *ratesOfLetters = new (std::nothrow) listOfOldAndNewRatesForLetters(f_oldAndNewRates,f_log);

    if( (!countOfStamp) || (!infLetters) || (!ratesOfLetters) ){
        std::wcout << "Does not enough memory for data." << std::endl;
        f_log << "Does not enough memory for data." << std::endl;
        f_result << "Does not enough memory for data." << std::endl;
        delete countOfStamp;
        delete infLetters;
        delete ratesOfLetters;
        return -1;
    }
    outputAllData(f_log,f_result,countOfStamp,infLetters,ratesOfLetters);

    f_log << "Check if all data has been entered." << std::endl;
    if(allDataWasInputed(countOfStamp,infLetters,ratesOfLetters)){
        f_log << "All data has been entered." << std::endl;
        calculationValues(infLetters,ratesOfLetters,f_log);

        delete countOfStamp;
        delete infLetters;
        delete ratesOfLetters;
    }
    else{
        std::wcout << "Not all data has been entered." << std::endl;
        f_log << "Not all data has been entered." << std::endl;
        f_result << "Not all data has been entered." << std::endl;
        delete countOfStamp;
        delete infLetters;
        delete ratesOfLetters;
    }
    f_log.close();
    f_result.close();
    f_oldAndNewRates.close();
    f_infLetter.close();
    f_countStamps.close();
    return 0;
}