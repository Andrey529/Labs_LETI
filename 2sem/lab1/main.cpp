/*
  Выполнил студент группы 0302, Блюдин А.И.

  Формулировка задания: 19. Заданная строка состоит из слов,разделенных одним
  или несколькими пробелами. Определить: а) количество слов в строке.

  Для ввода имени файла необходимо полностью указывать его расположение, например:
    C:\Users\andre\CLionProjects\2sem\lab1\data1.txt
    C:\Users\andre\CLionProjects\2sem\lab1\result.txt
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
};

Situations inputStr_1(String* ukaz);                  // вводит данные из файла с вариантом хранения: ограничитель
Situations inputStr_2(String* ukaz, int kolvo);       // вводит данные из файла с вариантом хранения: колво символов в строке
int process(String* ukaz);                            // ищет колво слов в строке
void outResults(String* ukaz, int number, int slov);  // выводит резултаты

int main() {
    setlocale(0,"rus");

    std::cout << "Введите версию программы:\n" <<
                 "1 - Представление последовательности символов с ограничителем для файла\n" <<
                 "2 - Представление последовательности символов с указанием их числа для файла" << std::endl;
    std::cout << "Версия:";
    char var_progi = '!'; // вариант программы (1 или 2)
    int i = 0;
    while((var_progi != '1') && (var_progi != '2') && (i<3)){     //вводим вар программы
        std::cin >> var_progi;
        ++i;
    }
    if(i == 3){     // если израсходаваны 3 попытки ввода варианта программы
        std::cout << "Неправильно введен вариант программы.";
        return -1;
    }

    char name_in[NameFile]; // имя файла где хранятся данные
    std::cout << "Введите имя файла с исходным текстом:";
    std::cin >> name_in;      // C:\Users\andre\CLionProjects\2sem\lab1\data1.txt
                              // C:\Users\andre\CLionProjects\2sem\lab1\data2.txt

    f_in.open(name_in,std::ios::in);
    if(f_in.bad()){
        std::cout << "Указанный файл не найден." << std::endl;
    }
    else{
        std::cout << "Результаты будут выведены в файл." << std::endl;
        std::cout << "Введите имя файла для вывода результатов:";
        char name_out[NameFile]; // имя файла куда заносятся результаты выполнения программы
        std::cin >> name_out;   // C:\Users\andre\CLionProjects\2sem\lab1\result.txt
        f_out.open(name_out,std::ios::out);
        if(f_out.bad()){
            std::cout << "Нет возможности сформировать файл с результатом." << std::endl;
            f_in.close();
            return -2;
        }
        if(var_progi == '1'){
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
                    slov = process(ukaz);
                    outResults(ukaz,number, slov);
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
        else{
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
                        else if(f_in.eof()) break;
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
                        slov = process(ukaz);
                        outResults(ukaz, number, slov);
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

int process(String* ukaz){
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

void outResults(String* ukaz, int number, int slov){
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

