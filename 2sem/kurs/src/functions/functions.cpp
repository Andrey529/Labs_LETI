#include <fstream>
#include <iostream>

void inputAllData();
bool openFiles(std::fstream &f_countStamps,std::fstream &f_infLetter,std::fstream &f_oldAndNewRates,
               std::fstream f_log, std::fstream f_result){
    const unsigned nameFile = 255;  // max lenght of files
    char nameFileCountStamps[nameFile];      // file with count of stamps
    char nameFileInfLetter[nameFile];      // file with information of all letters
    char nameFileOldAndNewRates[nameFile];     // file with old and new rates of letters
    char nameFileLog[nameFile];               // log file
    char nameFileResult[nameFile];           // result file

    f_countStamps.open(/*nameCountOfStamps*/
    "C:\\Users\\andre\\CLionProjects\\leti_progs\\2sem\\kurs\\text-files\\numberAndDenominationsOfStamps",std::ios::in);
    if(f_countStamps.bad()){
        std::cout << "It is impossible to open a file with the count and denomination of stamps." << std::endl;
        return false;
    }
    std::cout << "The number and denominations of stamps will be entered from the file: "<< nameFileCountStamps << std::endl;

    f_infLetter.open(/*nameFileInfLetter*/
    "C:\\Users\\andre\\CLionProjects\\leti_progs\\2sem\\kurs\\text-files\\informationAboutLetters.txt",std::ios::in);
    if(f_infLetter.bad()){
        std::cout << "It is impossible to open a file with the information about letters." << std::endl;
        return false;
    }
    std::cout << "The information about letters will be entered from the file: "<< nameFileInfLetter << std::endl;

    f_oldAndNewRates.open(/*nameFileOldAndNewRates*/
    "C:\\Users\\andre\\CLionProjects\\leti_progs\\2sem\\kurs\\text-files\\oldAndNewRatesForLetters.txt",std::ios::in);
    if(f_oldAndNewRates.bad()){
        std::cout << "It is impossible to open a file with the ." << std::endl;
    }
    return true;
}
