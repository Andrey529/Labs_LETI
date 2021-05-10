//#include "./headers/functions/functions.h"
//#include "./headers/listOfPartsString/partOfString.h"
#include <iostream>
#include <fstream>
//#include <wchar.h>
int main() {
//    std::wfstream f_countStamps, f_infLetter, f_oldAndNewRates, f_log, f_result;
//    openFiles(f_countStamps, f_infLetter, f_oldAndNewRates,f_log,f_result);

//    inputAllData(f_countStamps,f_infLetter,f_oldAndNewRates,f_log,f_result);

    std::wfstream f_infLetter;
    f_infLetter.open("/home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/informationAboutLetters.txt",std::ios::in);
    wchar_t s;

    int i=0;
    while(true){
        s = f_infLetter.get();
        std::wcout << int(s) << ' ';
        if(s == '\n'){
            i++;
        }
        if(i==2){
            break;
        }
    }
    s = f_infLetter.get();
    std::wcout << s;
//    partOfString partOfString;
//    partOfString.setInf(f_infLetter,f_log);

    return 0;
}