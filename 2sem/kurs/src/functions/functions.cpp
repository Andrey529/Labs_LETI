#include "../../headers/functions/functions.h"

listOfLetters *sortLetters(std::wfstream &f_log, bool firstState, countOfStamps *countOfStamp, listOfLetters *listLetters,
    listOfLetters *bestListLetters, stickekeredStamps *stickerStamps, stickekeredStamps *bestStickerStamps){
    if(listLetters->lettersDoNotNeedStamps()){
        if( (newStateOfStickeredStampsIsBetter(bestListLetters, listLetters)) || firstState){
            f_log << "new best condition has been found" << std::endl;
            delete bestListLetters;
            bestListLetters = listLetters;
            delete bestStickerStamps;
            bestStickerStamps = stickerStamps;
            firstState = false;
        }
        return bestListLetters;
    }
    if(!(countOfStamp->haveStamps())){
        f_log << "all stamps are out." << std::endl;
        return bestListLetters;
    }
    listLetters->sortLettersByCountStamps();
    listLetters->setIndexes();
    elementOfListLetters *elem = listLetters->getHead();
    int stamp;
    while (elem != nullptr){
        if(!(elem->getNeedToSort())){
            elem = elem->getNextLetter();
            continue;
        }
        stamp = countOfStamp->getStampOfMaxDenomination(listLetters->getMaxNeedUnits());

        //
        auto *newStickerStamps = new stickekeredStamps(stickerStamps);
        newStickerStamps->setElement(stamp,elem->getNeedUnits(),elem->getCountOfStamps());

        //
        auto *newListLetters = new listOfLetters(listLetters);
        elementOfListLetters *newElem = newListLetters->getHead();
        while(newElem != nullptr){
            if(elem->getIndex() == newElem->getIndex()){
                break;
            }
            newElem = newElem->getNextLetter();
        }
        newElem->setCountOfStamps(newElem->getCountOfStamps()+1);
        newElem->setNeedUnits(newElem->getNeedUnits() - stamp);
        if(newElem->getNeedUnits() <= 0){
            newElem->setNeedToSort(false);
        }

        //
        auto *newListOfCountStamps = new countOfStamps(countOfStamp);
        elemListCountOfStamps *elemListCountOfStamps = newListOfCountStamps->getHead();
        while(elemListCountOfStamps != nullptr){
            if(elemListCountOfStamps->getDenomination() == stamp){
                elemListCountOfStamps->setCountStamps(elemListCountOfStamps->getCountStamps()-1);
                break;
            }
            elemListCountOfStamps = elemListCountOfStamps->getNextElement();
        }

        if( (!(newStateOfStickeredStampsIsBetter(bestListLetters, newListLetters))) && (!firstState) ){
            f_log << "there is no point in going further" << std::endl;
            delete newListOfCountStamps;
            delete newListLetters;
            delete newStickerStamps;
            elem = elem->getNextLetter();
            continue;
        }

        sortLetters(f_log,firstState,newListOfCountStamps,newListLetters,bestListLetters,newStickerStamps,bestStickerStamps);
        if(!(newListLetters->lettersDoNotNeedStamps())){
            delete newStickerStamps;
            delete newListLetters;
            delete newListOfCountStamps;
        }
        elem = elem->getNextLetter();
    }
    return nullptr;
}

bool newStateOfStickeredStampsIsBetter(listOfLetters *listOfLettersOld, listOfLetters *listOfLettersNew) {
    elementOfListLetters *elem1 = listOfLettersOld->getHead();
    elementOfListLetters *elem2 = listOfLettersNew->getHead();
    int countLetters = listOfLettersOld->getCountOfLetters();

    int array1[countLetters];
    int array2[countLetters];

    for(int i=0; ;i++){
        array1[i] = elem1->getCountOfStamps();
        elem1 = elem1->getNextLetter();
        if(elem1 == nullptr){
            break;
        }
    }

    for(int i=0; ; i++){
        array2[i] = elem2->getCountOfStamps();
        elem2 = elem2->getNextLetter();
        if(elem2 == nullptr){
            break;
        }
    }
    int tmp;
    for(int i=0; i < countLetters-1; i++){    // sorting first array
        for(int j=0; j < countLetters-1; j++){
            if(array1[j] < array1[j+1]){
                tmp = array1[j];
                array1[j] = array1[j+1];
                array1[j+1] = tmp;
            }
        }
    }
    // sorting second array
    for(int i=0; i < countLetters-1; i++){
        for(int j=0; j < countLetters-1; j++){
            if(array2[j] < array2[j+1]){
                tmp = array2[j];
                array2[j] = array2[j+1];
                array2[j+1] = tmp;
            }
        }
    }

    for(int i = 0; i < countLetters; i++){
        if(array1[i] < array2[i]){
            return false;
        }
        else if(array2[i] < array1[i]){
            return true;
        }
        else{
            continue;
        }
    }
    return true;
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


//void stikerMarks(std::wfstream &f_log, countOfStamps *countOfStamp, elementOfListLetters *letter, stickekeredStamps *base){
//    if(letter->getNextLetter() == nullptr){
//        std::wcout << "End of sort." << std::endl;
//        f_log << "End of sort." << std::endl;
//        return;
//    }
//    while (letter->getNeedToSort()){
//        elemListCountOfStamps *count = countOfStamp->getHead();
//        int maxNominalOfStamp = -1;
//        while(count != nullptr){
//            if( (count->getDenomination() >= maxNominalOfStamp) && (count->getDenomination() <= letter->getNeedUnits())
//                && (count->getCountStamps() > 0) ){
//                maxNominalOfStamp = count->getDenomination();
//            }
//            count = count->getNextElement();
//        }
//        letter->setCountOfStamps(letter->getCountOfStamps()+1);
//        letter->setNeedUnits(letter->getNeedUnits()-maxNominalOfStamp);
//
//        count = countOfStamp->getHead();
//        while(true){
//            if(count->getDenomination() == maxNominalOfStamp){
//                count->setCountStamps(count->getCountStamps()-1);
//                break;
//            }
//            count = count->getNextElement();
//        }
//
//        if(letter->getNeedUnits() <= 0){
//            letter->setNeedToSort(false);
//        }
//
//        auto *elemStickeredStamp = new elementOfStikeredStamps;
//        if(base->getHead() == nullptr){
//            base->setHead(elemStickeredStamp);
//            base->setPrevious(elemStickeredStamp);
//            elemStickeredStamp->setDenomination(maxNominalOfStamp);
//        }
//        else{
//            base->getPrevious()->setNextStamp(elemStickeredStamp);
//            base->setPrevious(elemStickeredStamp);
//            elemStickeredStamp->setDenomination(maxNominalOfStamp);
//        }
//        stikerMarks(f_log,countOfStamp,letter, base);
//    }
//
//}
//
//void printPermutations(int index,countOfStamps countOfStamp, listOfLetters *infLetter, std::wfstream &f_log, stickekeredStamps *best) {
//    int length = infLetter->getCountOfLetters();
//    if (index == length) {
////        infLetter->outputInConsole(f_log);
//        infLetter->outputIndexesInConsole();
//        elementOfListLetters *elem = infLetter->getHead();
//        auto *base = new stickekeredStamps;
////        stikerMarks(f_log,countOfStamp,)        ну и хуетааааааааааааа
//
//        return;
//    }
//    for (int i=index; i < length; i++) {
//        infLetter->swapLettersByNumbers(i,index);
//        printPermutations(index + 1,countOfStamp, infLetter,f_log, best);
//        infLetter->swapLettersByNumbers(i,index);
//    }
//}