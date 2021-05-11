#include "./headers/functions/functions.h"
#include "./headers/listOfPartsString/partOfString.h"
//#include "./headers/countStamps/listOfCountStamps.h"
int main() {
    setlocale(LC_ALL,"ru_RU.UTF-8");
    std::wfstream f_countStamps, f_oldAndNewRates, f_log, f_infLetter, f_result;
    openFiles(f_countStamps, f_infLetter, f_oldAndNewRates,f_log,f_result);

    partOfString partOfString;
    situations flag = situations::notLastElement;
    while(flag != situations::endOfFile){
        flag = partOfString.setInf(f_infLetter,f_log);
        partOfString.getInfInConsole();
        std::wcout << std::endl;
    }
    return 0;
}