#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

fstream f;

int razmer(int* N,int* row1){
    int i,j,t,m,sum,sum1,sum2,k_glav,k1,k2,row1_1,row1_2;
    char s, k;
    f >> *N;
    if(*N == -1){
        if(f.eof()){
            return -1;
        }
    }
    if(*N <= 0){
        return -2;
    }
    int r[*N];
    for(i=0;i<*N;i++){
        r[i] = 0;
    }
    s = '!';
    f >> resetiosflags(ios::skipws);
    while(s != '\n'){
        do{
            f >> s;
            if(f.eof()) break;
        }
        while(s == ' ');
        if(f.eof()) break;
    }
    if(f.eof()){
        return -4;
    }

    s = '!';
    i = 0;
    k = ' ';
    while(1){
        if(f.eof()) break;
        i++;
        while(s != '\n'){
            if(f.eof()) break;
            f >> s;
            if(s == '\n') k = ' ';
            if((k != ' ') && (s != ' ')) continue;
            if(f.eof()) break;
            if((s != ' ') && (s != '\n')){
                r[i-1]++;
                k = s;
            }
            else{
                k = ' ';
            }
        }
        s = '!';
    }

    i = 0;
    sum = 0;
    for(i=0;i<*N;i++){
        k_glav = r[i];
        k1 = k_glav;
        sum1 = 0;
        for(m=r[i];m>0;m--){
            sum2 = 1;
            k2 = k1;
            for(j=i+1;j<(i+k2);j++){
                t = r[j];
                if(t >= k2){
                    sum2++;
                }
                else{break;}
            }
            if(sum2 == k2){
                row1_2 = i;
            }
            if((sum2 == k1) && (sum2 > sum1)){
                sum1 = sum2;
                row1_1 = row1_2;
            }
            k1--;
        }
        if((sum1 > sum)){
            sum = sum1;
            *row1 = row1_1;
        }
    }
    *N = sum;
    return 0;
}

int inpArray(int N/*rows and columns*/,int row1, int** p/*array*/){
    int i,j,M;
    char s;
    M = N;
    *p = new int[(N)*(M)];

    s = '!';
    f >> resetiosflags(ios::skipws);
    while(s != '\n'){                        /*переход с первой строчке где расположен размер матрицы*/
        do{                                  /*на вторую для уже осуществления ввода элементов матрицы из файла*/
            f >> s;
        }
        while(s == ' ');
    }
    s = '!';
    for(i=0;i<row1;i++){
        while(s != '\n'){
            do{
                f >> s;
            }
            while(s == ' ');
        }
    }

    f >> setiosflags(ios::skipws);
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(f.eof()) break;
            f >> *(*p+M*i+j);
        }

        // перевод на новую строку, в случае, когда размер матрицы меньше колво элементов в строке
        s = '!';
        f >> resetiosflags(ios::skipws);
        while(s != '\n'){
            if(f.eof()) break;
            f >> s;
        }
        f >> setiosflags(ios::skipws);
    }
    return 1;
}

void outArray(int N /*rows and columns*/, int* p /*array*/){
    int i,j,M;
    M = N;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(j==0){
                cout<<*(p+M*i+j);
                f<<*(p+M*i+j);
            }
            else{
                cout<<" "<<*(p+M*i+j);
                f<<' '<<*(p+M*i+j);
            }
        }
        cout<<"\n";
        f<<'\n';
    }
}

int proverka(int N/*rows and columns*/, int* p/*array*/){
    int i,j,M,Res1,Res2,Itog;
    int k[2][N];
    M = N;
    Res1 = 0; Res2 = 0; Itog = 1;

    for(i=0;i<2;i++){ // инициализации вспомогательного массива для хранения суммы строк и столбцов
        for(j=0;j<N;j++){
            k[i][j]=0;
        }
    }

    for(i=0;i<N;i++){ //сумма на побочной диагонали
        for(j=(M-1);j>=0;j--){
            if(i == (N-(j+1))){
                Res2 = Res2 + *(p+M*i+j);
            }
        }
    }

    for(i=0;i<N;i++){// сумма на главной диагонали и суммы каждой строки
        for(j=0;j<M;j++){
            if(i==j){
                Res1 = Res1 + *(p+M*i+j);
            }
            k[0][i] = k[0][i] + *(p+M*i+j);
        }
    }

    if(Res1 != Res2){ //когда сумма на главной диагонали не равно сумме на побочной
        return -1;
    }

    for(j=0;j<M;j++) { // суммы в каждом столбце
        for (i = 0; i < N; i++) {
            k[1][j] = k[1][j] + *(p+M*i+j);
        }
    }

    for(i=0;i<2;i++){
        for(j=0;j<N;j++){
            if(k[i][j] != Res1){
                Itog = 0;
                break;
            }
        }
        if(Itog) break;
    }
    return Itog;
}

int main(){
    setlocale(0,"Rus");
    int N, vivod,size,row1;
    int *p;
    N = -1;

    f.open("C:\\Users\\andre\\CLionProjects\\5\\text.txt", ios::in);
    if(f.bad() != 0){
        cout<<"error"<<endl;
        return -1;
    }
    size = razmer(&N,&row1); // нахождение правильного размера матрицы

    if(size == -1){
        cout << "Файл пуст";
        return -4;
    }
    else if(size == -4){
        cout << "Нет элементов матрицы в файле";
        return -7;
    }
    f.close();

    f.open("C:\\Users\\andre\\CLionProjects\\5\\text.txt", ios::in);
    if(f.bad() != 0){
        cout<<"error"<<endl;
        return -2;
    }
    inpArray(N, row1, &p); // ввод из внешнего файла элементов матрицы для дальнейшей обработки
    f.close();

    f.open("C:\\Users\\andre\\CLionProjects\\5\\result.txt", ios::out);
    if(f.bad() != 0){
        cout<<"error"<<endl;
        return -3;
    }

    if(size == -2){
        cout << "Некорректный размер матрицы";
        f << "Некорректный размер матрицы";
        return -5;
    }

    outArray(N, p); // вывод элементов матрицы во внешний файл

    vivod = proverka(N, p); // проверка матрицы - является ли она магическим квадратом

    if(vivod == 1){
        cout << "--Данная матрица является магическим квадратом--";
        f << "--Данная матрица является магическим квадратом--";
    }
    else{
        cout << "--Данная матрица не является магическим квадратом--";
        f << "--Данная матрица не является магическим квадратом--";
    }
    f.close();

    if(p) delete[] p;

    return 0;
}





