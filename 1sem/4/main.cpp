#include <iostream>
#include <fstream>
using namespace std;
int main() {
    setlocale(0,"rus");
    int vers;
    cout << "Введите версию программы(1 или 2):";
    cin >> vers;
    if(vers == 1){
        const unsigned N=10;//максимальное количество элементов в массиве
        int a;//реальное количество элементов в массиве
        unsigned i,j;//индексные переменнные
        int t;//вспомогательная переменная
        int W[N],x;
        fstream f;
        f.open("C:\\Users\\andre\\CLionProjects\\4\\input1.txt",ios::in);
        if(f.bad() == 1){
            cout << "Ошибка при открытии файла для входа !!!" << endl;
        }
        else{
            f >> a;
            if(a<0){a=0; cout << "Некорректный размер скорректирован в 0.";}
            else if(a>N) a=N;
            i = 0;
            while(1){
                if(a == 0) break;
                f >> x;
                W[i] = x;
                i++;
                if(f.eof()) break;//значения в файле исчерпаны
                if((i>=N) || (i>=a)) break;//не хватает места в массиве
            }
            a = i;
            f.close();
            if(a != 0){
                f.open("C:\\Users\\andre\\CLionProjects\\4\\result1.txt",ios::out);
                if(f.bad() == 1) cout << "Ошибка открытия файла для вывода !!!" << endl;
                else{
                    for(i=0;i<a;i++){
                        f << W[i] << " ";
                        cout << W[i] << " ";
                    }
                    f << "\n";
                    cout << "\n";
                    for(i=(a-1);i>0;i--){
                        for (j = (a-1); j > 0; j--) {
                            if( (W[j] > 0) && ((W[j] % 2) == 0) && (!((W[j-1] > 0) && ((W[j-1] % 2) == 0)))  ){
                                t = W[j];
                                W[j] = W[j - 1];
                                W[j - 1] = t;
                            }
                        }
                    }
                    for(i=(a-1);i>0;i--){
                        for(j=(a-1);j>0;j--){
                            if ((W[j] < 0) && ((W[j] % 2) != 0) && (!((W[j-1] < 0) && ((W[j-1] % 2) != 0))) ) {
                                t = W[j];
                                W[j] = W[j-1];
                                W[j-1] = t;
                            }
                        }
                    }
                    for(i=0;i<a;i++){
                        f << W[i] << " ";
                        cout << W[i] << " ";
                    }
                    f.close();
                }
            }
        }
    }
    else if(vers == 2){
        int a; // реальное число элементов в массиве
        unsigned i,j;// индексная переменная
        int *p;// обращение только через *(p+i)
        int x;
        int t;
        fstream f;
        f.open("C:\\Users\\andre\\CLionProjects\\4\\input2.txt",ios::in);
        if(f.bad() == 1){
            cout << "Ошибка при открытии файла для ввода !!!" << endl;
        }
        else{
            a = 0; // сначало сосчитаем количество элементов в файле
            while(1){
                f >> x;
                a++;
                if(f.eof()) break; // значения в файле исчерпаны
            }
            f.close();

            p = new int[a]; //будем обрабатывать фактическое количество значений
            if(p != NULL){
                f.open("C:\\Users\\andre\\CLionProjects\\4\\input2.txt",ios::in);
                a = 0;
                while(1){
                    f >> x;
                    *(p+a) = x;
                    a++;
                    if(f.eof()) break;
                }
                f.close();

                f.open("C:\\Users\\andre\\CLionProjects\\4\\result2.txt",ios::out);
                if(f.bad() == 1){
                    cout << "Ошибка при открытии файла для вывода !!!" << endl;
                }
                else{
                    for(i=0;i<a;i++){

                        f << *(p+i) << " ";
                        cout << *(p+i) << " ";
                    }//контрольный вывод введенных значений в массив
                    f << "\n";
                    cout << "\n";
                    for(i=(a-1);i>0;i--){
                        for (j = (a-1); j > 0; j--) {
                            if( (*(p+j) > 0) && ((*(p+j) % 2) == 0) && (!((*(p+j-1) > 0) && ((*(p+j-1) % 2) == 0)))  ){
                                t = *(p+j);
                                *(p+j) = *(p+j-1);
                                *(p+j-1) = t;
                            }
                        }
                    }
                    for(i=(a-1);i>0;i--){
                        for(j=(a-1);j>0;j--){
                            if ((*(p+j) < 0) && ((*(p+j) % 2) != 0) && (!((*(p+j-1) < 0) && ((*(p+j-1) % 2) != 0))) ) {
                                t = *(p+j);
                                *(p+j) = *(p+j-1);
                                *(p+j-1) = t;
                            }
                        }
                    }
                    for(i=0;i<a;i++){
                        f << *(p+i) << " ";
                        cout << *(p+i) << " ";
                    }
                    f.close();
                }
                delete [] p;
            }
        }
    }
    return 0;
}
