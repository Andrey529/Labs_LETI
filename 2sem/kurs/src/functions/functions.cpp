#include "../../headers/functions/functions.h"

void inputAllData(std::fstream &f_countStamps,std::fstream &f_infLetter,
                  std::fstream &f_oldAndNewRates, std::fstream &f_log, std::fstream &f_result){
    countOfStamps countOfStamps(f_countStamps,f_log);
    countOfStamps.outputCountOfStampsInFileAndInConsole(f_result,f_log);

}

//void outputAllData(std::fstream &f_log, std::fstream &f_result){
//}

bool openFiles(std::fstream &f_countStamps,std::fstream &f_infLetter,std::fstream &f_oldAndNewRates,
               std::fstream &f_log, std::fstream &f_result){
    const unsigned nameFile = 255;  // max lenght of files
    char nameFileCountStamps[nameFile];      // file with count of stamps
    char nameFileInfLetter[nameFile];      // file with information of all letters
    char nameFileOldAndNewRates[nameFile];     // file with old and new rates of letters
    char nameFileLog[nameFile];               // log file
    char nameFileResult[nameFile];           // result file

//    C:\Users\andre\CLionProjects\leti_progs\2sem\kurs\text-files\numberAndDenominationsOfStamps.txt
//    /home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/numberAndDenominationsOfStamps.txt
    f_countStamps.open(/*nameCountOfStamps*/
    "/home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/numberAndDenominationsOfStamps.txt",std::ios::in);
    if(f_countStamps.bad()){
        std::cout << "It is impossible to open a file with the count and denomination of stamps." << std::endl;
        return false;
    }
//    std::cout << "The number and denominations of stamps will be entered from the file: "<< nameFileCountStamps << std::endl;

//    C:\Users\andre\CLionProjects\leti_progs\2sem\kurs\text-files\informationAboutLetters.txt
//    /home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/informationAboutLetters.txt
    f_infLetter.open(/*nameFileInfLetter*/
    "/home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/informationAboutLetters.txt",std::ios::in);
    if(f_infLetter.bad()){
        std::cout << "It is impossible to open a file with the information about letters." << std::endl;
        return false;
    }
//    std::cout << "The information about letters will be entered from the file: "<< nameFileInfLetter << std::endl;

//    C:\Users\andre\CLionProjects\leti_progs\2sem\kurs\text-files\oldAndNewRatesForLetters.txt
//    /home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/oldAndNewRatesForLetters.txt
    f_oldAndNewRates.open(/*nameFileOldAndNewRates*/
    "/home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/oldAndNewRatesForLetters.txt",std::ios::in);
    if(f_oldAndNewRates.bad()){
        std::cout << "It is impossible to open a file with the old and new rates for letters." << std::endl;
        return false;
    }
//    std::cout << "The old and new rates of letters will be entered from the file: "<< nameFileOldAndNewRates << std::endl;

//    C:\Users\andre\CLionProjects\leti_progs\2sem\kurs\text-files\log.txt
//    /home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/log.txt
    f_log.open(/*nameFileLog*/
            "/home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/log.txt",std::ios::out);
    if(f_log.bad()){
        std::cout << "Unable to open file for log output." << std::endl;
        return false;
    }
//    std::cout << "The logs will be output in the file: "<< nameFileInfLetter << std::endl;

//    C:\Users\andre\CLionProjects\leti_progs\2sem\kurs\text-files\result.txt
//    /home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/result.txt
    f_result.open(/*nameFileResult*/
            "/home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/result.txt",std::ios::out);
    if(f_result.bad()){
        std::cout << "Unable to open file for result output." << std::endl;
        return false;
    }
//    std::cout << "The results will be output in the file: "<< nameFileInfLetter << std::endl;

    return true;
}
