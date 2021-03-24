/*
  �������� ������� ������ 0302, ������ �.�.

  ������������ �������: 19. �������� ������ ������� �� ����,����������� �����
  ��� ����������� ���������. ����������: �) ���������� ���� � ������.

  ��� ����� ����� ����� ���������� ��������� ��������� ��� ������������, ��������:
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

const unsigned MaxLen = 10; //������������ ����� �������� � ������
const unsigned NameFile = 100; // ������������ ���������� ��� ����� �����
std::fstream f_in;
std::fstream f_out;

struct String{
    char Str[MaxLen+1]; // ������, � ������� ����� ������� ������. +1 ��� �������� �������
    char Mark;          // ������
    int Len;            // ���������� �������� ��� 2 ����� ��������� (�������� 3 � 4)
};

Situations inputStr_1(String* ukaz);                  // ������ ������ �� ����� � ��������� ��������: ������������ � ������
Situations inputStr_2(String* ukaz, int kolvo);       // ������ ������ �� ����� � ��������� ��������: ����� �������� � ������ � ������
Situations inputStr_3(String* ukaz);                  // ������ ������ �� ����� � ��������� ��������: ������������ � ��������� ����� ��������
Situations inputStr_4(String* ukaz);                  // ������ ������ �� ����� � ��������� ��������: ����� ��������
int process_1and2(String* ukaz);                      // ���� ����� ���� � ������ ��� 1 ����� ����� (�������� 1 � 2)
int process_3and4(String* ukaz);                      // ���� ����� ���� � ������ ��� 2 ����� ����� (�������� 3 � 4)
void outResults_1and2(String* ukaz, int number, int slov);  // ������� ���������� �� 1 ����� ����� (�������� 1 � 2)
void outResults_3and4(String* ukaz, int number, int slov); // ������� ���������� ��� 2 ����� ����� (�������� 3 � 4)

int main() {
    setlocale(0,"rus");

    std::cout << "������� ������ ���������:\n" <<
              "1 - ������������� ������������������ �������� � ������������� ��� ����� � ��������\n" <<
              "2 - ������������� ������������������ �������� � ��������� �� ����� ��� ����� � ��������\n" <<
              "3 - ������������� ������������������ �������� � ������������� ��� ����� � ��������� ���������� �������� � ������\n" <<
              "4 - ������������� ������������������ �������� � ��������� �� ����� ��� �����" << std::endl;
    std::cout << "������:";
    char var_progi = '!'; // ������� ��������� (1 ��� 2 ��� 3 ��� 4)
    int i = 0;
    /*
     1 - ������ � �������������
     2 - ������ � ����������� ��������
     3 - � ������������� � ��������� ���������� ��������
     4 - ���������� ��������
     */
    while((var_progi != '1') && (var_progi != '2') && (var_progi != '3') && (var_progi != '4') && (i<3)){     //������ ��� ���������
        std::cin >> var_progi;
        ++i;
    }
    if(i == 3){     // ���� ������������� 3 ������� ����� �������� ���������
        std::cout << "����������� ������ ������� ���������.";
        return -1;
    }

    char name_in[NameFile]; // ��� ����� ��� �������� ������
    std::cout << "������� ��� ����� � �������� �������:";
    std::cin >> name_in;      // C:\Users\andre\CLionProjects\2sem\lab1_part2_2sem_proga\data1.txt
                              // C:\Users\andre\CLionProjects\2sem\lab1_part2_2sem_proga\data2.txt
                              // C:\Users\andre\CLionProjects\2sem\lab1_part2_2sem_proga\data3.txt
                              // C:\Users\andre\CLionProjects\2sem\lab1_part2_2sem_proga\data4.txt

    f_in.open(name_in,std::ios::in);
    if(f_in.bad()){
        std::cout << "��������� ���� �� ������." << std::endl;
    }
    else{
        std::cout << "���������� ����� �������� � ����." << std::endl;
        std::cout << "������� ��� ����� ��� ������ �����������:";
        char name_out[NameFile]; // ��� ����� ���� ��������� ���������� ���������� ���������
        std::cin >> name_out;               // C:\Users\andre\CLionProjects\2sem\lab1_part2_2sem_proga\result.txt
        f_out.open(name_out,std::ios::out);
        if(f_out.bad()){
            std::cout << "��� ����������� ������������ ���� � �����������." << std::endl;
            f_in.close();
            return -2;
        }
        if(var_progi == '1'){  // ������ � �������������
            String str;  // ������� ��������� � ��������� �� ���
            struct String* ukaz;
            ukaz = &str;

            Situations flag; // ���� ������ �� ����� � ��������� ��������� (���� ��������)
            int number = 1;  // ���������� ����� �������������� ������
            do{
                str.Mark = f_in.get(); // ������ ������
                if(!f_in.eof()){ // ���� ���� �� ������
                    flag = inputStr_1(ukaz);
                    int slov;
                    slov = process_1and2(ukaz);
                    outResults_1and2(ukaz,number, slov);
                }
                else{
                    std::cout << "���� ��� ����� ������ ����." << std::endl;
                    f_out << "���� ��� ����� ������ ����." << std::endl;
                    break;
                }
                number++;
            }
            while(flag != Situations::END_OF_FILE);
        }
        else if(var_progi == '2'){  // ������ � ����������� ��������
            String str;
            struct String* ukaz;
            ukaz = &str;

            Situations flag = Situations::GOOD;
            int number = 1; // ����� �������� ������
            while(flag != Situations::END_OF_FILE){
                str.Mark = f_in.get(); //������
                if(!f_in.eof()){ // ���� ���� �� ������
                    int kolvo;
                    f_in >> kolvo; //���������� �������� � �������� ������

                    if(kolvo > static_cast<int>(MaxLen)){ // ���� ��������� ����� �������� ��������� ����������� ���������
                        kolvo = MaxLen;
                    }
                    else if(kolvo <= 0){ // ���� �������� ����� ���������������
                        char s = '!';
                        while( (s != '\n') && (!f_in.eof()) ){ // ���� ���� ����� ����� ���� ������� � ����� ������
                            s = f_in.get();                    // ���� ������� � ����� ������ ������ ������ �� ��������� ��������� � ����� ������
                        }                                      // ����� ����� �����
                        std::cout << "� ������ ��� ������� " << number <<
                                  " ����������� ������� ���������� �������� � ������." << std::endl << std::endl;
                        f_out << "� ������ ��� ������� " << number <<
                              " ����������� ������� ���������� �������� � ������." << std::endl << std::endl;
                        if(s == '\n'){
                            flag = Situations::NEW_LINE;
                            number++;
                            continue;
                        }
                        else{break;}
                    }

                    char s;
                    s = f_in.get(); //������� ������ ����� ������ �������� � 1 ��������� � ������
                    // ��� ��� ������ ������ �������� � ����:  ������������������� ������
                    // ������: #10 1 ������ !
                    // "1 ������ !" - ��� ������

                    if((!f_in.eof()) && (s != '\n')){
                        flag = inputStr_2(ukaz, kolvo);
                        if(flag == Situations::BAD){
                            break;
                        }
                        int slov;  //����� ���� � ������
                        slov = process_1and2(ukaz);
                        outResults_1and2(ukaz, number, slov);
                    }
                    else if(f_in.eof()){
                        std::cout << "� ������ ��� ������� " << number << " ��� ��������.";
                        f_out << "� ������ ��� ������� " << number << " ��� ��������.";
                        flag = Situations::END_OF_FILE;
                    }
                    else if(s == '\n'){
                        flag = Situations::GOOD;
                        std::cout << "� ������ ��� ������� " << number << " ��� ��������." << std::endl << std::endl;
                        f_out << "� ������ ��� ������� " << number << " ��� ��������." << std::endl << std::endl;
                        number++;
                        continue;
                    }
                }
                else{
                    std::cout << "���� ��� ����� ������ ����." << std::endl;
                    f_out << "���� ��� ����� ������ ����." << std::endl;
                    break;
                }
                number++;
            }


        }
        else if(var_progi == '3'){ // � ������������� � ��������� ����� ��������
            String str;  // ������� ��������� � ��������� �� ���
            struct String* ukaz;
            ukaz = &str;

            Situations flag; // ���� ������ �� ����� � ��������� ��������� (���� ��������)
            int number = 1;  // ���������� ����� �������������� ������
            do{
                str.Mark = f_in.get(); // ������ 1 ������ (������������)
                str.Len = 0;
                if(!f_in.eof()){ // ���� ���� �� ������
                    flag = inputStr_3(ukaz);
                    if((ukaz->Len)>0){
                        int slov;
                        slov = process_3and4(ukaz);
                        outResults_3and4(ukaz,number, slov);
                    }
                    else{
                        std::cout << "� ������ ��� ������� " << number << " 0 ��������." << std::endl << std::endl;
                        f_out << "� ������ ��� ������� " << number << " 0 ��������." << std::endl << std::endl;
                    }
                }
                else{
                    std::cout << "���� ��� ����� ������ ����." << std::endl;
                    f_out << "���� ��� ����� ������ ����." << std::endl;
                    break;
                }
                number++;
            }
            while(flag != Situations::END_OF_FILE);
        }
        else {  // � ����������� ��������
            String str;
            struct String *ukaz;
            ukaz = &str;

            Situations flag = Situations::GOOD;
            int number = 1; // ����� �������� ������
            while (flag != Situations::END_OF_FILE) {
                f_in >> str.Len; //�����
                if (!f_in.eof()) { // ���� ���� �� ������
                    if ((str.Len) > static_cast<int>(MaxLen)){
                        str.Len = MaxLen;
                    }
                    else if((str.Len) <= 0){
                        char s = '!';
                        while ((s != '\n') && (!f_in.eof())) { // ���� ���� ����� ����� ���� ������� � ����� ������
                            s = f_in.get();                    // ���� ������� � ����� ������ ������ ������ �� ��������� ��������� � ����� ������
                        }                                      // ����� ����� �����
                        std::cout << "� ������ ��� ������� " << number <<
                                  " ����������� ������� ���������� �������� � ������." << std::endl << std::endl;
                        f_out << "� ������ ��� ������� " << number <<
                              " ����������� ������� ���������� �������� � ������." << std::endl << std::endl;
                        if (s == '\n') {
                            flag = Situations::NEW_LINE;
                            number++;
                            continue;
                        } else if (f_in.eof()) break;
                    }
                    char s;
                    s = f_in.get(); //������� ������ ����� ������ �������� � 1 ��������� � ������
                    // ��� ��� ������ ������ �������� � ����:  ������������� ������
                    // ������: 10 1 ������ !
                    // "1 ������ !" - ��� ������

                    if ((!f_in.eof()) && (s != '\n')) {
                        flag = inputStr_4(ukaz);
                        if (flag == Situations::BAD) {
                            break;
                        }
                        if((str.Len)>0){
                            int slov;  //����� ���� � ������
                            slov = process_3and4(ukaz);
                            outResults_3and4(ukaz, number, slov);
                        }
                        else{
                            std::cout << "� ������ ��� ������� " << number << " 0 ��������." << std::endl << std::endl;
                            f_out << "� ������ ��� ������� " << number << " 0 ��������." << std::endl << std::endl;
                        }
                    }
                    else if (f_in.eof()) {
                        std::cout << "� ������ ��� ������� " << number << " ��� ��������.";
                        f_out << "� ������ ��� ������� " << number << " ��� ��������.";
                        flag = Situations::END_OF_FILE;
                    }
                    else if (s == '\n') {
                        flag = Situations::GOOD;
                        std::cout << "� ������ ��� ������� " << number << " ��� ��������." << std::endl
                                  << std::endl;
                        f_out << "� ������ ��� ������� " << number << " ��� ��������." << std::endl << std::endl;
                        number++;
                        continue;
                    }

                }
                else {
                    std::cout << "���� ��� ����� ������ ����." << std::endl;
                    f_out << "���� ��� ����� ������ ����." << std::endl;
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
    std::cout << "����������� ����� " << number << " ������: ";
    f_out << "����������� ����� " << number << " ������: ";
    for(int i=0; ;i++){
        std::cout << ukaz->Str[i];
        f_out << ukaz->Str[i];
        if(ukaz->Str[i] == ukaz->Mark){
            break;
        }
    }
    f_out << std::endl;
    std::cout << std::endl;

    f_out << "� ������ ��� ������� " << number << " ����� " << slov;
    if( (slov%10 == 0) || ( ((slov%10)>=5) && ((slov%10)<=9) ) ) f_out << " ����." << std::endl << std::endl;
    else if( ( ((slov%10)>=2) && ((slov%10)<=4) ) && ((slov%100)!=12) &&
             ((slov%100)!=13) && ((slov%100)!=14) ) f_out << " �����." << std::endl << std::endl;
    else if( ((slov%10)==1) && ((slov%100)!=11) ) f_out << " �����." << std::endl << std::endl;
    else if( ((slov%100)>=11) && ((slov%100)<=14) ) f_out << " ����." << std::endl << std::endl;

    std::cout << "� ������ ��� ������� " << number << " ����� " << slov;
    if( (slov%10 == 0) || ( ((slov%10)>=5) && ((slov%10)<=9) ) ) std::cout << " ����." << std::endl << std::endl;
    else if( ( ((slov%10)>=2) && ((slov%10)<=4) ) && ((slov%100)!=12) &&
             ((slov%100)!=13) && ((slov%100)!=14) ) std::cout << " �����." << std::endl << std::endl;
    else if( ((slov%10)==1) && ((slov%100)!=11) ) std::cout << " �����." << std::endl << std::endl;
    else if( ((slov%100)>=11) && ((slov%100)<=14) ) std::cout << " ����." << std::endl << std::endl;
    // � ����������� �� ����� ���� ��������� ��������� ����� "�����".
}

void outResults_3and4(String* ukaz, int number, int slov){
    std::cout << "����������� ����� " << number << " ������: ";
    f_out << "����������� ����� " << number << " ������: ";
    for(int i=0;i<(ukaz->Len);i++){
        std::cout << ukaz->Str[i];
        f_out << ukaz->Str[i];
    }
    f_out << std::endl << "� ������ ������ " << ukaz->Len;
    std::cout << std::endl << "� ������ ������ " << ukaz->Len;

    if( ((ukaz->Len)%10 == 0) || ( (((ukaz->Len)%10)>=5) && (((ukaz->Len)%10)<=9) ) ) f_out << " ��������";
    else if( ( (((ukaz->Len)%10)>=2) && (((ukaz->Len)%10)<=4) ) && (((ukaz->Len)%100)!=12) &&
             (((ukaz->Len)%100)!=13) && (((ukaz->Len)%100)!=14) ) f_out << " �������";
    else if( (((ukaz->Len)%10)==1) && (((ukaz->Len)%100)!=11) ) f_out << " ������";
    else if( (((ukaz->Len)%100)>=11) && (((ukaz->Len)%100)<=14) ) f_out << " ��������";

    if( ((ukaz->Len)%10 == 0) || ( (((ukaz->Len)%10)>=5) && (((ukaz->Len)%10)<=9) ) ) std::cout << " ��������";
    else if( ( (((ukaz->Len)%10)>=2) && (((ukaz->Len)%10)<=4) ) && (((ukaz->Len)%100)!=12) &&
             (((ukaz->Len)%100)!=13) && (((ukaz->Len)%100)!=14) ) std::cout << " �������";
    else if( (((ukaz->Len)%10)==1) && (((ukaz->Len)%100)!=11) ) std::cout << " ������";
    else if( (((ukaz->Len)%100)>=11) && (((ukaz->Len)%100)<=14) ) std::cout << " ��������";

    f_out << " � " << slov;
    std::cout << " � " << slov;
    if( (slov%10 == 0) || ( ((slov%10)>=5) && ((slov%10)<=9) ) ) f_out << " ����." << std::endl << std::endl;
    else if( ( ((slov%10)>=2) && ((slov%10)<=4) ) && ((slov%100)!=12) &&
             ((slov%100)!=13) && ((slov%100)!=14) ) f_out << " �����." << std::endl << std::endl;
    else if( ((slov%10)==1) && ((slov%100)!=11) ) f_out << " �����." << std::endl << std::endl;
    else if( ((slov%100)>=11) && ((slov%100)<=14) ) f_out << " ����." << std::endl << std::endl;

    if( (slov%10 == 0) || ( ((slov%10)>=5) && ((slov%10)<=9) ) ) std::cout << " ����." << std::endl << std::endl;
    else if( ( ((slov%10)>=2) && ((slov%10)<=4) ) && ((slov%100)!=12) &&
             ((slov%100)!=13) && ((slov%100)!=14) ) std::cout << " �����." << std::endl << std::endl;
    else if( ((slov%10)==1) && ((slov%100)!=11) ) std::cout << " �����." << std::endl << std::endl;
    else if( ((slov%100)>=11) && ((slov%100)<=14) ) std::cout << " ����." << std::endl << std::endl;
    // � ����������� �� ����� ���� ��������� ��������� ���� "�����" � "������".
}