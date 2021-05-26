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

        auto *stickeredStamps = new stickekeredStamps;
        auto *result = sortLetters(f_log, true,countOfStamp,infLetters,infLetters,stickeredStamps,stickeredStamps);

        result->outputListOfLettersInConsoleAndInFile(f_result,f_log);

        delete result;
        delete stickeredStamps;
        // находим марку с максимальным номиналом
//        std::wcout << countOfStamp->getStampOfMaxDenomination(infLetters->getMaxNeedUnits());

        // максимальное колво необходимое для наклейки
//        std::wcout << infLetters->getMaxNeedUnits();

        // проверка сортировка писем по колво марок на них
//        infLetters->sortLettersByCountStamps();
//        infLetters->outputListOfLettersInConsoleAndInFile(f_result,f_log);


        // проверка наличия марок в наборе
//        if(countOfStamp->haveStamps()){
//            std::wcout << "have";
//        }
//        else{
//            std::wcout << "do not have";
//        }

        // проверка метода что на письма нужно еще наклеить марки
//        if(!(infLetters->lettersDoNotNeedStamps())){
//            std::wcout << "need" << std::endl;
//        }

        // проверка конструктора копирования списка писем
//        auto *inf2 = new listOfLetters(infLetters);
//        inf2->outputListOfLettersInConsoleAndInFile(f_result,f_log);
//        delete inf2;


        // проверка конструктора копирования списка номиналов марок
//        auto *count2 = new countOfStamps(countOfStamp);
//        count2->outputCountOfStampsInFileAndInConsole(f_result,f_log);
//        delete count2;

//        std::wcout << infLetters->getCountOfLetters() << std::endl;
//        infLetters->getLetterByNumber(4)->outputDataOfElementOfListLettersInConsole(f_log);

//        infLetters->outputInConsole(f_log);
//        infLetters->swapLettersByNumbers(4,2);
//        infLetters->outputInConsole(f_log);


        // проверка конструктора списка наклеиных марок на письма
//        auto *listOfStickeredStamps = new stickekeredStamps;
//        for(int i=0; i<5; i++){
//            listOfStickeredStamps->setElement(i+1,i+2,i+3);
//        }
//        listOfStickeredStamps->outputList(f_log,f_result);
//        auto *list2 = new stickekeredStamps(listOfStickeredStamps);
//        list2->outputList(f_log,f_result);
//        delete listOfStickeredStamps;
//        delete list2;

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