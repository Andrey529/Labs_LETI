#include "../../headers/functions/functions.h"

void sortLetters(std::wfstream &f_log, countOfStamps *countOfStamp, listOfLetters *listLetters){
    elementOfListLetters *letter;
    listLetters->setIndexes();
    while(true){
        letter = letterWithLessNeedStamps(countOfStamp,listLetters);
        if(letter == nullptr){
            f_log << "All letters were sorted." << std::endl << std::endl;
            break;
        }
        int stamp;
        while(true){
            if(!letter->getNeedToSort()){
                break;
            }
            stamp = countOfStamp->getStampOfMaxDenomination(letter->getNeedUnits());

            letter->setCountOfStamps(letter->getCountOfStamps()+1);
            letter->setNeedUnits(letter->getNeedUnits()-stamp);

            elemListCountOfStamps *elem = countOfStamp->getHead();
            while(elem != nullptr){
                if(elem->getDenomination() == stamp){
                    elem->reduceCountStamps(1);
                    break;
                }
                elem = elem->getNextElement();
            }
            f_log << "A stamp with denomination = " << stamp << " was stickered on the letter by number = "
                  << letter->getIndex()+1 << ". Now on this letter stickered " << letter->getCountOfStamps()
                  << " stamps and need to stick stamps on " << letter->getNeedUnits() << " units." << std::endl;
            if(letter->getNeedUnits() <= 0){
                letter->setNeedToSort(false);
            }
        }
    }
}

elementOfListLetters *letterWithLessNeedStamps(countOfStamps *countOfStamp, listOfLetters *listLetters){
    elementOfListLetters *letter = listLetters->getHead();
    while(letter != nullptr){
        if(!letter->getNeedToSort()){
            letter = letter->getNextLetter();
            continue;
        }
        letter->setNeedStamps(0);
        letter->setNeedToSort(true);
        int needUnits = letter->getNeedUnits();
        while(needUnits > 0){
            int maxStamp = countOfStamp->getStampOfMaxDenomination(needUnits);
            if(maxStamp == -1){
                letter->setNeedToSort(false);
                break;
            }

            needUnits = needUnits - maxStamp;
            letter->setNeedStamps(letter->getNeedStamps()+1);
        }

        letter = letter->getNextLetter();
    }
    int min = 10000;
    elementOfListLetters *needLetter;
    letter = listLetters->getHead();
    while(letter != nullptr){
        if( (letter->getNeedStamps() < min) && (letter->getNeedToSort())){
            min = letter->getNeedStamps();
            needLetter = letter;
        }
        letter = letter->getNextLetter();
    }
    if(min != 10000){
        return needLetter;
    }
    else{
        return nullptr;
    }
}

void printResults(std::wfstream &f_log, std::wfstream &f_out, listOfLetters *listLetters){
    elementOfListLetters *elem = listLetters->getHead();
    f_log << "-----------Results-----------" << std::endl;
    f_out << "-----------Results-----------" << std::endl;
    std::wcout << "-----------Results-----------" << std::endl;
    listLetters->setIndexes();
    while(elem != nullptr){
        f_log << "On the Letter by number " << elem->getIndex()+1 << " stickered "
        << elem->getCountOfStamps() << " stamps. ";
        f_out << "On the Letter by number " << elem->getIndex()+1 << " stickered "
              << elem->getCountOfStamps() << " stamps. ";
        std::wcout << "On the Letter by number " << elem->getIndex()+1 << " stickered "
                   << elem->getCountOfStamps() << " stamps. ";
        if(elem->getNeedUnits() > 0){
            f_log << "This letter is ready to be sent because there are not enough stamps for it." << std::endl;
            f_out << "This letter is ready to be sent because there are not enough stamps for it." << std::endl;
            std::wcout << "This letter is ready to be sent because there are not enough stamps for it." << std::endl;
        }
        else{
            f_log << "This letter is ready to be sent." << std::endl;
            f_out << "This letter is ready to be sent." << std::endl;
            std::wcout << "This letter is ready to be sent." << std::endl;
        }
        elem = elem->getNextLetter();
    }
}


void calculationValues(listOfLetters *infLetters, listOfOldAndNewRatesForLetters *rates, std::wfstream &f_log){
    bool flag = true;
    elementOfListLetters *letter = infLetters->getHead();
    while(letter != nullptr){
        elementOfOldAndNewRates *elemRates = rates->getHead();
        while((elemRates != nullptr) && flag) {
            if ((letter->getTypeOfLetter() == elemRates->getTypeOfLetter()) &&
                (letter->getTypeOfAddress() == elemRates->getTypeOfAddress())) {
                rateValues *val = elemRates->getHeadValues();
                while(val != nullptr){
                    if( (letter->getWeight() >= val->getLowerBound()) &&
                        (letter->getWeight() <= val->getUpperBound()) ){
                        letter->setOldPrice(val->getOldPrice());
                        letter->setNewPrice(val->getNewPrice());
                        letter->setNeedUnits(letter->getNewPrice()-letter->getOldPrice());
                        flag = false;
                        break;
                    }
                    val = val->getNext();
                }
            }
            elemRates = elemRates->getNextElement();
        }
        flag = true;
        letter = letter->getNextLetter();
    }
    letter = infLetters->getHead();
    int i=1;
    while (letter != nullptr){
        f_log << "-----Letter by number " << i << " -----" << std::endl;
        if(letter->getNeedUnits() == -1){
            letter->setNeedToSort(false);
            f_log << "Do not need to be sort." << std::endl;
        }
        else{
            f_log << "Old price = " << letter->getOldPrice() << std::endl;
            f_log << "New price = " << letter->getNewPrice() << std::endl;
            f_log << "Need units = " << letter->getNeedUnits() << std::endl;
        }
        i++;
        letter = letter->getNextLetter();
    }
    f_log << std::endl;
}



bool allDataWasInputed(countOfStamps *countOfStamps,listOfLetters *infLetters, listOfOldAndNewRatesForLetters *rates){
    if(countOfStamps->listIsEmpty()){
        return false;
    }
    else if(!(infLetters->listNotEmpty())){
        return false;
    }
    else if(!(rates->listNotEmpty())){
        return false;
    }
    return true;
}


void outputAllData(std::wfstream &f_log, std::wfstream &f_result, countOfStamps *countOfStamps,
                   listOfLetters *infLetters, listOfOldAndNewRatesForLetters *rates){
    countOfStamps->outputCountOfStampsInFileAndInConsole(f_result,f_log);
    infLetters->outputListOfLettersInConsoleAndInFile(f_result,f_log);
    rates->outputListOfRatesInConsoleAndInFile(f_result,f_log);
}

bool openFiles(std::wfstream &f_countStamps,std::wfstream &f_infLetter,std::wfstream &f_oldAndNewRates,
               std::wfstream &f_log, std::wfstream &f_result){
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
        std::wcout << "It is impossible to open a file with the count and denomination of stamps." << std::endl;
        return false;
    }
    f_countStamps.imbue(std::locale("ru_RU.UTF-8"));
//    std::wcout << "The number and denominations of stamps will be entered from the file: "<< nameFileCountStamps << std::endl;

//    C:\Users\andre\CLionProjects\leti_progs\2sem\kurs\text-files\informationAboutLetters.txt
//    /home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/informationAboutLetters.txt
    f_infLetter.open(/*nameFileInfLetter*/
    "/home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/informationAboutLetters.txt",std::ios::in);
    if(f_infLetter.bad()){
        std::wcout << "It is impossible to open a file with the information about letters." << std::endl;
        return false;
    }
    f_infLetter.imbue(std::locale("ru_RU.UTF-8"));
//    std::wcout << "The information about letters will be entered from the file: "<< nameFileInfLetter << std::endl;

//    C:\Users\andre\CLionProjects\leti_progs\2sem\kurs\text-files\oldAndNewRatesForLetters.txt
//    /home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/oldAndNewRatesForLetters.txt
    f_oldAndNewRates.open(/*nameFileOldAndNewRates*/
    "/home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/oldAndNewRatesForLetters.txt",std::ios::in);
    if(f_oldAndNewRates.bad()){
        std::wcout << "It is impossible to open a file with the old and new rates for letters." << std::endl;
        return false;
    }
    f_oldAndNewRates.imbue(std::locale("ru_RU.UTF-8"));
//    std::wcout << "The old and new rates of letters will be entered from the file: "<< nameFileOldAndNewRates << std::endl;

//    C:\Users\andre\CLionProjects\leti_progs\2sem\kurs\text-files\log.txt
//    /home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/log.txt
    f_log.open(/*nameFileLog*/
            "/home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/log.txt",std::ios::out);
    if(f_log.bad()){
        std::wcout << "Unable to open file for log output." << std::endl;
        return false;
    }
    f_log.imbue(std::locale("ru_RU.UTF-8"));
//    std::wcout << "The logs will be output in the file: "<< nameFileInfLetter << std::endl;

//    C:\Users\andre\CLionProjects\leti_progs\2sem\kurs\text-files\result.txt
//    /home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/result.txt
    f_result.open(/*nameFileResult*/
            "/home/andrey/Projects/Labs_LETI/2sem/kurs/text-files/result.txt",std::ios::out);
    if(f_result.bad()){
        std::wcout << "Unable to open file for result output." << std::endl;
        return false;
    }
    f_result.imbue(std::locale("ru_RU.UTF-8"));
//    std::wcout << "The results will be output in the file: "<< nameFileInfLetter << std::endl;

    return true;
}
