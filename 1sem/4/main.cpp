#include <iostream>
#include <fstream>
using namespace std;
int main() {
    setlocale(0,"rus");
    int vers;
    cout << "������� ������ ���������(1 ��� 2):";
    cin >> vers;
    if(vers == 1){
        const unsigned N=10;//������������ ���������� ��������� � �������
        int a;//�������� ���������� ��������� � �������
        unsigned i,j;//��������� �����������
        int t;//��������������� ����������
        int W[N],x;
        fstream f;
        f.open("C:\\Users\\andre\\CLionProjects\\4\\input1.txt",ios::in);
        if(f.bad() == 1){
            cout << "������ ��� �������� ����� ��� ����� !!!" << endl;
        }
        else{
            f >> a;
            if(a<0){a=0; cout << "������������ ������ �������������� � 0.";}
            else if(a>N) a=N;
            i = 0;
            while(1){
                if(a == 0) break;
                f >> x;
                W[i] = x;
                i++;
                if(f.eof()) break;//�������� � ����� ���������
                if((i>=N) || (i>=a)) break;//�� ������� ����� � �������
            }
            a = i;
            f.close();
            if(a != 0){
                f.open("C:\\Users\\andre\\CLionProjects\\4\\result1.txt",ios::out);
                if(f.bad() == 1) cout << "������ �������� ����� ��� ������ !!!" << endl;
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
        int a; // �������� ����� ��������� � �������
        unsigned i,j;// ��������� ����������
        int *p;// ��������� ������ ����� *(p+i)
        int x;
        int t;
        fstream f;
        f.open("C:\\Users\\andre\\CLionProjects\\4\\input2.txt",ios::in);
        if(f.bad() == 1){
            cout << "������ ��� �������� ����� ��� ����� !!!" << endl;
        }
        else{
            a = 0; // ������� ��������� ���������� ��������� � �����
            while(1){
                f >> x;
                a++;
                if(f.eof()) break; // �������� � ����� ���������
            }
            f.close();

            p = new int[a]; //����� ������������ ����������� ���������� ��������
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
                    cout << "������ ��� �������� ����� ��� ������ !!!" << endl;
                }
                else{
                    for(i=0;i<a;i++){

                        f << *(p+i) << " ";
                        cout << *(p+i) << " ";
                    }//����������� ����� ��������� �������� � ������
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
