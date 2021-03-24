/*
  Выполнил студент группы 0302, Блюдин А.И.

  Формулировка задания: 19. Заданная строка состоит из слов,разделенных одним
  или несколькими пробелами. Определить: а) количество слов в строке.

  Для ввода имени файла необходимо полностью указывать его расположение, например:
    C:\Users\andre\CLionProjects\2sem\lab1_part2_2sem_proga\data1.txt
    C:\Users\andre\CLionProjects\2sem\lab1_part2_2sem_proga\result.txt
*/

#include <iostream>
#include <fstream>

enum class Situations{
    END_OF_FILE,
    NEW_LINE,
    MARK_IS_HERE,
    BAD,
    GOOD
};

const unsigned MaxLen = 10; //максимальное колво символов в строке
const unsigned NameFile = 100; // максимальное количество для имени файла
std::fstream f_in;
std::fstream f_out;

struct String{
    char Str[MaxLen+1]; // массив, в котором лежат символы строки. +1 для хранения маркера
    char Mark;          // маркер
    int Len;            // количество символов для 2 части программы (варианты 3 и 4)
};

Situations inputStr_1(String* ukaz);                  // вводит данные из файла с вариантом хранения: ограничитель и маркер
Situations inputStr_2(String* ukaz, int kolvo);       // вводит данные из файла с вариантом хранения: колво символов в строке и маркер
Situations inputStr_3(String* ukaz);                  // вводит данные из файла с вариантом хранения: ограничитель с подсчетом колво символов
Situations inputStr_4(String* ukaz);                  // вводит данные из файла с вариантом хранения: колво символов
int process_1and2(String* ukaz);                      // ищет колво слов в строке для 1 части проги (варианты 1 и 2)
int process_3and4(String* ukaz);                      // ищет колво слов в строке для 2 части проги (варианты 3 и 4)
void outResults_1and2(String* ukaz, int number, int slov);  // выводит результаты дл 1 части проги (варианты 1 и 2)
void outResults_3and4(String* ukaz, int number, int slov); // выводит результаты для 2 части проги (варианты 3 и 4)

int main() {
    setlocale(0,"rus");

    std::cout << "Введите версию программы:\n" <<
              "1 - Представление последовательности символов с ограничителем для файла и маркером\n" <<
              "2 - Представление последовательности символов с указанием их числа для файла и маркером\n" <<
              "3 - Представление последовательности символов с ограничителем для файла и подсчетом количества символов в строке\n" <<
              "4 - Представление последовательности символов с указанием их числа для файла" << std::endl;
    std::cout << "Версия:";
    char var_progi = '!'; // вариант программы (1 или 2 или 3 или 4)
    int i = 0;
    /*
     1 - маркер с ограничителем
     2 - маркер с количеством символов
     3 - с ограничителем и подсчетом количества символов
     4 - количество символов
     */
    while((var_progi != '1') && (var_progi != '2') && (var_progi != '3') && (var_progi != '4') && (i<3)){     //вводим вар программы
        std::cin >> var_progi;
        ++i;
    }
    if(i == 3){     // если израсходаваны 3 попытки ввода варианта программы
        std::cout << "Неправильно введен вариант программы.";
        return -1;
    }

    char name_in[NameFile]; // имя файла где хранятся данные
    std::cout << "Введите имя файла с исходным текстом:";
    std::cin >> name_in;      // C:\Users\andre\CLionProjects\2sem\lab1_part2_2sem_proga\data1.txt
                              // C:\Users\andre\CLionProjects\2sem\lab1_part2_2sem_proga\data2.txt
                              // C:\Users\andre\CLionProjects\2sem\lab1_part2_2sem_proga\data3.txt
                              // C:\Users\andre\CLionProjects\2sem\lab1_part2_2sem_proga\data4.txt

    f_in.open(name_in,std::ios::in);
    if(f_in.bad()){
        std::cout << "Указанный файл не найден." << std::endl;
    }
    else{
        std::cout << "Результаты будут выведены в файл." << std::endl;
        std::cout << "Введите имя файла для вывода результатов:";
        char name_out[NameFile]; // имя файла куда заносятся результаты выполнения программы
        std::cin >> name_out;               // C:\Users\andre\CLionProjects\2sem\lab1_part2_2sem_proga\result.txt
        f_out.open(name_out,std::ios::out);
        if(f_out.bad()){
            std::cout << "Нет возможности сформировать файл с результатом." << std::endl;
            f_in.close();
            return -2;
        }
        if(var_progi == '1'){  // маркер с ограничителем
            String str;  // создаем структуру и указатель на нее
            struct String* ukaz;
            ukaz = &str;

            Situations flag; // флаг выхода из цикла и окончания программы (файл кончился)
            int number = 1;  // порядковый номер обрабатываемой строки
            do{
                str.Mark = f_in.get(); // вводим маркер
                if(!f_in.eof()){ // если файл не пустой
                    flag = inputStr_1(ukaz);
                    int slov;
                    slov = process_1and2(ukaz);
                    outResults_1and2(ukaz,number, slov);
                }
                else{
                    std::cout << "Файл для ввода строки пуст." << std::endl;
                    f_out << "Файл для ввода строки пуст." << std::endl;
                    break;
                }
                number++;
            }
            while(flag != Situations::END_OF_FILE);
        }
        else if(var_progi == '2'){  // маркер с количеством символов
            String str;
            struct String* ukaz;
            ukaz = &str;

            Situations flag = Situations::GOOD;
            int number = 1; // номер вводимой строки
            while(flag != Situations::END_OF_FILE){
                str.Mark = f_in.get(); //маркер
                if(!f_in.eof()){ // если файл не пустой
                    int kolvo;
                    f_in >> kolvo; //количество символов в вводимой строке

                    if(kolvo > static_cast<int>(MaxLen)){ // если введенное колво символов превышает максимально возможный
                        kolvo = MaxLen;
                    }
                    else if(kolvo <= 0){ // если вводимое колво неположительное
                        char s = '!';
                        while( (s != '\n') && (!f_in.eof()) ){ // ищем либо конец файла либо переход к новой строке
                            s = f_in.get();                    // если переход к новой строке найден первым то программа переходит к новой строке
                        }                                      // иначе конец проги
                        std::cout << "В строке под номером " << number <<
                                  " неправильно введено количество символов в строке." << std::endl << std::endl;
                        f_out << "В строке под номером " << number <<
                              " неправильно введено количество символов в строке." << std::endl << std::endl;
                        if(s == '\n'){
                            flag = Situations::NEW_LINE;
                            number++;
                            continue;
                        }
                        else{break;}
                    }

                    char s;
                    s = f_in.get(); //убираем пробел между числом символов и 1 элементом в строке
                    // так как строка данных хранятся в виде:  МаркерЧислоСимволов строка
                    // пример: #10 1 строка !
                    // "1 строка !" - это строка

                    if((!f_in.eof()) && (s != '\n')){
                        flag = inputStr_2(ukaz, kolvo);
                        if(flag == Situations::BAD){
                            break;
                        }
                        int slov;  //колво слов в строке
                        slov = process_1and2(ukaz);
                        outResults_1and2(ukaz, number, slov);
                    }
                    else if(f_in.eof()){
                        std::cout << "В строке под номером " << number << " нет символов.";
                        f_out << "В строке под номером " << number << " нет символов.";
                        flag = Situations::END_OF_FILE;
                    }
                    else if(s == '\n'){
                        flag = Situations::GOOD;
                        std::cout << "В строке под номером " << number << " нет символов." << std::endl << std::endl;
                        f_out << "В строке под номером " << number << " нет символов." << std::endl << std::endl;
                        number++;
                        continue;
                    }
                }
                else{
                    std::cout << "Файл для ввода строки пуст." << std::endl;
                    f_out << "Файл для ввода строки пуст." << std::endl;
                    break;
                }
                number++;
            }


        }
        else if(var_progi == '3'){ // с ограничителем и подсчетом колво символов
            String str;  // создаем структуру и указатель на нее
            struct String* ukaz;
            ukaz = &str;

            Situations flag; // флаг выхода из цикла и окончания программы (файл кончился)
            int number = 1;  // порядковый номер обрабатываемой строки
            do{
                str.Mark = f_in.get(); // вводим 1 символ (ограничитель)
                str.Len = 0;
                if(!f_in.eof()){ // если файл не пустой
                    flag = inputStr_3(ukaz);
                    if((ukaz->Len)>0){
                        int slov;
                        slov = process_3and4(ukaz);
                        outResults_3and4(ukaz,number, slov);
                    }
                    else{
                        std::cout << "В строке под номером " << number << " 0 символов." << std::endl << std::endl;
                        f_out << "В строке под номером " << number << " 0 символов." << std::endl << std::endl;
                    }
                }
                else{
                    std::cout << "Файл для ввода строки пуст." << std::endl;
                    f_out << "Файл для ввода строки пуст." << std::endl;
                    break;
                }
                number++;
            }
            while(flag != Situations::END_OF_FILE);
        }
        else {  // с количеством символов
            String str;
            struct String *ukaz;
            ukaz = &str;

            Situations flag = Situations::GOOD;
            int number = 1; // номер вводимой строки
            while (flag != Situations::END_OF_FILE) {
                f_in >> str.Len; //длина
                if (!f_in.eof()) { // если файл не пустой
                    if ((str.Len) > static_cast<int>(MaxLen)){
                        str.Len = MaxLen;
                    }
                    else if((str.Len) <= 0){
                        char s = '!';
                        while ((s != '\n') && (!f_in.eof())) { // ищем либо конец файла либо переход к новой строке
                            s = f_in.get();                    // если переход к новой строке найден первым то программа переходит к новой строке
                        }                                      // иначе конец проги
                        std::cout << "В строке под номером " << number <<
                                  " неправильно введено количество символов в строке." << std::endl << std::endl;
                        f_out << "В строке под номером " << number <<
                              " неправильно введено количество символов в строке." << std::endl << std::endl;
                        if (s == '\n') {
                            flag = Situations::NEW_LINE;
                            number++;
                            continue;
                        } else if (f_in.eof()) break;
                    }
                    char s;
                    s = f_in.get(); //убираем пробел между числом символов и 1 элементом в строке
                    // так как строка данных хранятся в виде:  ЧислоСимволов строка
                    // пример: 10 1 строка !
                    // "1 строка !" - это строка

                    if ((!f_in.eof()) && (s != '\n')) {
                        flag = inputStr_4(ukaz);
                        if (flag == Situations::BAD) {
                            break;
                        }
                        if((str.Len)>0){
                            int slov;  //колво слов в строке
                            slov = process_3and4(ukaz);
                            outResults_3and4(ukaz, number, slov);
                        }
                        else{
                            std::cout << "В строке под номером " << number << " 0 символов." << std::endl << std::endl;
                            f_out << "В строке под номером " << number << " 0 символов." << std::endl << std::endl;
                        }
                    }
                    else if (f_in.eof()) {
                        std::cout << "В строке под номером " << number << " нет символов.";
                        f_out << "В строке под номером " << number << " нет символов.";
                        flag = Situations::END_OF_FILE;
                    }
                    else if (s == '\n') {
                        flag = Situations::GOOD;
                        std::cout << "В строке под номером " << number << " нет символов." << std::endl
                                  << std::endl;
                        f_out << "В строке под номером " << number << " нет символов." << std::endl << std::endl;
                        number++;
                        continue;
                    }

                }
                else {
                    std::cout << "Файл для ввода строки пуст." << std::endl;
                    f_out << "Файл для ввода строки пуст." << std::endl;
                    break;
                }
                number++;
            }
        }
    }
    return 0;
}

Situations inputStr_1(String* ukaz){
    for(int i=0; ;i++){

        ukaz->Str[i] = f_in.get();

        if(f_in.eof()){
            ukaz->Str[i] = ukaz->Mark;
            return Situations::END_OF_FILE;
        }

        else if(ukaz->Str[i] == '\n'){
            ukaz->Str[i] = ukaz->Mark;
            return Situations::NEW_LINE;
        }


        else if(ukaz->Str[i] == ukaz->Mark){
            char s = '!';
            while( (s != '\n') && ( !(f_in.eof()) ) ){
                s = f_in.get();
            }
            if(s == '\n'){
                return Situations::MARK_IS_HERE;
            }
            else{
                return Situations::END_OF_FILE;
            }
        }

        else if(i == MaxLen){
            ukaz->Str[i] = ukaz->Mark;

            char s = '!';
            while( (s != '\n') && ( !(f_in.eof()) ) ){
                s = f_in.get();
            }
            if(s == '\n'){
                return Situations::NEW_LINE;
            }
            else{
                return Situations::END_OF_FILE;
            }
        }
    }
}


Situations inputStr_2(String* ukaz, int kolvo){
    int i = 0;
    while(i<kolvo){
        ukaz->Str[i] = f_in.get();

        if(f_in.eof()){
            ukaz->Str[i] = ukaz->Mark;
            return Situations::END_OF_FILE;
        }

        else if(ukaz->Str[i] == '\n'){
            ukaz->Str[i] = ukaz->Mark;
            return Situations::NEW_LINE;
        }

        else if(i==(kolvo-1)){
            ukaz->Str[kolvo] = ukaz->Mark;
            char s = '!';
            while( (!f_in.eof()) && (s != '\n') ){
                s = f_in.get();
            }
            if(s == '\n'){
                return Situations::NEW_LINE;
            }
            else{
                return Situations::END_OF_FILE;
            }
        }
        i++;
    }
    return Situations::BAD;
}

Situations inputStr_3(String* ukaz){
    for(int i=0; ;i++){

        ukaz->Str[i] = f_in.get();

        if(f_in.eof()){
            return Situations::END_OF_FILE;
        }

        else if(ukaz->Str[i] == '\n'){
            return Situations::NEW_LINE;
        }


        else if(ukaz->Str[i] == ukaz->Mark){
            char s = '!';
            while( (s != '\n') && ( !(f_in.eof()) ) ){
                s = f_in.get();
            }
            if(s == '\n'){
                return Situations::MARK_IS_HERE;
            }
            else{
                return Situations::END_OF_FILE;
            }
        }

        else if(i == MaxLen){
            char s = '!';
            while( (s != '\n') && ( !(f_in.eof()) ) ){
                s = f_in.get();
            }
            if(s == '\n'){
                return Situations::NEW_LINE;
            }
            else{
                return Situations::END_OF_FILE;
            }
        }
        ukaz->Len++;
    }
}

Situations inputStr_4(String* ukaz){
    int i = 0;
    while(i<(ukaz->Len)){
        ukaz->Str[i] = f_in.get();

        if(f_in.eof()){
            ukaz->Len = i;
            return Situations::END_OF_FILE;
        }

        else if(ukaz->Str[i] == '\n'){
            ukaz->Len = i;
            return Situations::NEW_LINE;
        }

        else if(i==((ukaz->Len)-1)){
            char s = '!';
            while( (!f_in.eof()) && (s != '\n') ){
                s = f_in.get();
            }
            if(s == '\n'){
                return Situations::NEW_LINE;
            }
            else{
                return Situations::END_OF_FILE;
            }
        }
        i++;
    }
    return Situations::BAD;
}

int process_1and2(String* ukaz){
    int slov = 0;
    int i = 1;
    char elem1 = ukaz->Str[0];
    if(elem1 == ukaz->Mark){
        return 0;
    }
    if(elem1 != ' '){
        slov++;
    }
    while(ukaz->Str[i] != ukaz->Mark){
        if( (ukaz->Str[i] != ' ') && (elem1 == ' ') ){  // __**
            slov++;
            elem1 = ukaz->Str[i];
            i++;
            continue;
        }
        else if( (ukaz->Str[i] != ' ') && (elem1 != ' ') ){ // ****
            elem1 = ukaz->Str[i];
            i++;
            continue;
        }
        else if( (ukaz->Str[i] == ' ') && (elem1 != ' ') ){ // **__
            elem1 = ukaz->Str[i];
            i++;
            continue;
        }
        else{  // ____
            elem1 = ukaz->Str[i];
            i++;
            continue;
        }
    }
    return slov;
}

int process_3and4(String* ukaz){
    int slov = 0;
    int i = 1;
    char elem1 = ukaz->Str[0];
    if(elem1 != ' '){
        slov++;
    }
    while(i != ukaz->Len){
        if( (ukaz->Str[i] != ' ') && (elem1 == ' ') ){  // __**
            slov++;
            elem1 = ukaz->Str[i];
            i++;
            continue;
        }
        else if( (ukaz->Str[i] != ' ') && (elem1 != ' ') ){ // ****
            elem1 = ukaz->Str[i];
            i++;
            continue;
        }
        else if( (ukaz->Str[i] == ' ') && (elem1 != ' ') ){ // **__
            elem1 = ukaz->Str[i];
            i++;
            continue;
        }
        else{  // ____
            elem1 = ukaz->Str[i];
            i++;
            continue;
        }
    }
    return slov;
}

void outResults_1and2(String* ukaz, int number, int slov){
    std::cout << "Контрольный вывод " << number << " строки: ";
    f_out << "Контрольный вывод " << number << " строки: ";
    for(int i=0; ;i++){
        std::cout << ukaz->Str[i];
        f_out << ukaz->Str[i];
        if(ukaz->Str[i] == ukaz->Mark){
            break;
        }
    }
    f_out << std::endl;
    std::cout << std::endl;

    f_out << "В строке под номером " << number << " всего " << slov;
    if( (slov%10 == 0) || ( ((slov%10)>=5) && ((slov%10)<=9) ) ) f_out << " слов." << std::endl << std::endl;
    else if( ( ((slov%10)>=2) && ((slov%10)<=4) ) && ((slov%100)!=12) &&
             ((slov%100)!=13) && ((slov%100)!=14) ) f_out << " слова." << std::endl << std::endl;
    else if( ((slov%10)==1) && ((slov%100)!=11) ) f_out << " слово." << std::endl << std::endl;
    else if( ((slov%100)>=11) && ((slov%100)<=14) ) f_out << " слов." << std::endl << std::endl;

    std::cout << "В строке под номером " << number << " всего " << slov;
    if( (slov%10 == 0) || ( ((slov%10)>=5) && ((slov%10)<=9) ) ) std::cout << " слов." << std::endl << std::endl;
    else if( ( ((slov%10)>=2) && ((slov%10)<=4) ) && ((slov%100)!=12) &&
             ((slov%100)!=13) && ((slov%100)!=14) ) std::cout << " слова." << std::endl << std::endl;
    else if( ((slov%10)==1) && ((slov%100)!=11) ) std::cout << " слово." << std::endl << std::endl;
    else if( ((slov%100)>=11) && ((slov%100)<=14) ) std::cout << " слов." << std::endl << std::endl;
    // в зависимости от колво слов сортируем окончания слова "слово".
}

void outResults_3and4(String* ukaz, int number, int slov){
    std::cout << "Контрольный вывод " << number << " строки: ";
    f_out << "Контрольный вывод " << number << " строки: ";
    for(int i=0;i<(ukaz->Len);i++){
        std::cout << ukaz->Str[i];
        f_out << ukaz->Str[i];
    }
    f_out << std::endl << "В данной строке " << ukaz->Len;
    std::cout << std::endl << "В данной строке " << ukaz->Len;

    if( ((ukaz->Len)%10 == 0) || ( (((ukaz->Len)%10)>=5) && (((ukaz->Len)%10)<=9) ) ) f_out << " символов";
    else if( ( (((ukaz->Len)%10)>=2) && (((ukaz->Len)%10)<=4) ) && (((ukaz->Len)%100)!=12) &&
             (((ukaz->Len)%100)!=13) && (((ukaz->Len)%100)!=14) ) f_out << " символа";
    else if( (((ukaz->Len)%10)==1) && (((ukaz->Len)%100)!=11) ) f_out << " символ";
    else if( (((ukaz->Len)%100)>=11) && (((ukaz->Len)%100)<=14) ) f_out << " символов";

    if( ((ukaz->Len)%10 == 0) || ( (((ukaz->Len)%10)>=5) && (((ukaz->Len)%10)<=9) ) ) std::cout << " символов";
    else if( ( (((ukaz->Len)%10)>=2) && (((ukaz->Len)%10)<=4) ) && (((ukaz->Len)%100)!=12) &&
             (((ukaz->Len)%100)!=13) && (((ukaz->Len)%100)!=14) ) std::cout << " символа";
    else if( (((ukaz->Len)%10)==1) && (((ukaz->Len)%100)!=11) ) std::cout << " символ";
    else if( (((ukaz->Len)%100)>=11) && (((ukaz->Len)%100)<=14) ) std::cout << " символов";

    f_out << " и " << slov;
    std::cout << " и " << slov;
    if( (slov%10 == 0) || ( ((slov%10)>=5) && ((slov%10)<=9) ) ) f_out << " слов." << std::endl << std::endl;
    else if( ( ((slov%10)>=2) && ((slov%10)<=4) ) && ((slov%100)!=12) &&
             ((slov%100)!=13) && ((slov%100)!=14) ) f_out << " слова." << std::endl << std::endl;
    else if( ((slov%10)==1) && ((slov%100)!=11) ) f_out << " слово." << std::endl << std::endl;
    else if( ((slov%100)>=11) && ((slov%100)<=14) ) f_out << " слов." << std::endl << std::endl;

    if( (slov%10 == 0) || ( ((slov%10)>=5) && ((slov%10)<=9) ) ) std::cout << " слов." << std::endl << std::endl;
    else if( ( ((slov%10)>=2) && ((slov%10)<=4) ) && ((slov%100)!=12) &&
             ((slov%100)!=13) && ((slov%100)!=14) ) std::cout << " слова." << std::endl << std::endl;
    else if( ((slov%10)==1) && ((slov%100)!=11) ) std::cout << " слово." << std::endl << std::endl;
    else if( ((slov%100)>=11) && ((slov%100)<=14) ) std::cout << " слов." << std::endl << std::endl;
    // в зависимости от колво слов сортируем окончания слов "слово" и "символ".
}