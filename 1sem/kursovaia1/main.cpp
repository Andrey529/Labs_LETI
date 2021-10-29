/*    ��������: ������ ������, ������� ������ 0302
      ���� ������ ����������: 22.12.2020, ���������: 25.12.2020
      ������ ���������: 76
      ---------------------������������ �������----------------------------
      ���� N ����� �� ���������. ����� ����� ��� �����, ���������� ��������� ��-
      ����, ���������� ������������ ����� �������� �����. ������: ��� ������� �.
      ===========================================================================       */

#include <iostream>
#include <fstream>
#include <cmath>


using namespace std;

void inpArray(fstream& f, int* N, float** A, float** B);
void privetstvie(ostream& f);
void outArray(fstream& f, int N, float* A, float* B);
void poisk_tochek(ostream& f, int* a, int* b, int* c, int* d,int N, float* A, float* B, int* Itog, int* count_max);
bool proverka_figure(float Ax, float Ay, float Bx, float By, float Cx, float Cy, float Dx, float Dy, double AB, double BC, float Tx, float Ty);
void vivod(ostream& f, int a, int b, int c, int d, int count, float* A, float* B);

int main() {
    setlocale(0,"rus");
    fstream f;
    int n,i,a,b,c,d;
    a = 0; b = 0; c = 0; d = 0;
    float* x;
    float* y;
    int N = 100, Itog = 0, count_max = 0;

    f.open("C:\\Users\\andre\\CLionProjects\\kursovaia1\\points.txt",ios::in);
    if(f.bad()){
        cout << "������ ��� �������� ����� �� ���� ��������� �����";
        return -1;
    }
    else{
        f >> n;
        if(f.eof()){
            cout << "���� ��� ����� ��������� ����� ����" << endl;
            return -2;
        }
        if((n<4) || (n>100)){
            i = 0;
            do{
                cin >> n;
                i++;
            }
            while((n<4) && (i<3) && (n>100));
            if(i == 3){
                cout << "�� 3 ������� �� ���� ������� ����������� ���������� �����" << endl;
                return -3;
            }
        }
        if(n < N) N = n;
        x = new float[N];
        if(x == NULL){
            cout << "������������ ����� ��� �������� ������� ��� �������� ��������� X\n";
            f.close();
            return -4;
        }
        else{
            y = new float[N];
            if(y == NULL){
                cout << "������������ ����� ��� �������� ������� ��� �������� ��������� X\n";
                f.close();
                return -5;
            }
            else{
                inpArray(f, &N, &x, &y);
                f.close();
            }
        }

    }

    f.open("C:\\Users\\andre\\CLionProjects\\kursovaia1\\result.txt",ios::out);
    if(f.bad()){
        cout << "������ ��� �������� ����� �� ����� ����������";
        return -6;
    }
    else{
        privetstvie(f);
        outArray(f,N,x,y);
        poisk_tochek(f,&a, &b, &c, &d, N, x, y, &Itog, &count_max);
        if(Itog){
            vivod(f,a,b,c,d,count_max,x,y);
            f.close();
        }
        else{
            f << "���������� ��������� ����� �� ��������� ������";
            cout << "���������� ��������� ����� �� ��������� ������";
            f.close();
        }
    }
    f.open("C:\\Users\\andre\\CLionProjects\\kursovaia1\\result_kratko.txt",ios::out);
    if(f.bad()){
        cout << "������ ��� �������� ����� �� ����� ����������";
        return -7;
    }
    else{
        if(Itog){
            privetstvie(f);
            outArray(f,N,x,y);
            vivod(f,a,b,c,d,count_max,x,y);
        }
        else{
            f << "���������� ��������� ����� �� ��������� ������";
            cout << "���������� ��������� ����� �� ��������� ������";
        }
    }
    f.close();
    if(x) delete[] x;
    if(y) delete[] y;
    return 0;
}

void inpArray(fstream& f, int* N, float** A, float** B){
    int i,j;
    char s;
    for(i=0;i<*N;i++){
        if(f.eof()){
            *N = i;
            break;
        }
        f >> *(*A+i);
        s = f.get();
        if((s == '\n') || (f.eof())){
            i--;
            continue;
        }
        f >> *(*B+i);
        for(j=0;j<i;j++){
            if((*(*A+j) == *(*A+i)) && (*(*B+j) == *(*B+i))){
                i--;
                break;
            }
        }
        while((s != '\n') && (!f.eof())){
            s = f.get();
        }
    }
}

void outArray(fstream& f, int N, float* A, float* B){
    int i;
    for(i=0;i<N;i++){
        cout << "���������� " << i+1 << " �����: X = " << A[i] << " Y = " << B[i] << '\n';
        f << "���������� " << i+1 << " �����: X = " << A[i] << " Y = " << B[i] << '\n';
    }
    cout <<"========================================" << endl;
    f << "========================================" << endl;
}
void    vivod(ostream& f, int a, int b, int c, int d, int count, float* A, float* B){
    cout << "=================����===================\n"
         << "������ ��������� �� ������ ������ �����:\n"
         << "A = (" << A[a] << ',' << B[a] << ')' << '\n'
         << "B = (" << A[b] << ',' << B[b] << ')' << '\n'
         << "C = (" << A[c] << ',' << B[c] << ')' << '\n'
         << "D = (" << A[d] << ',' << B[d] << ')' << '\n'
         << "���������� ����� ������� ������ = " << count << endl;
    f    << "=================����===================\n"
         << "������ ��������� �� ������ ������ �����:\n"
         << "A = (" << A[a] << ',' << B[a] << ')' << '\n'
         << "B = (" << A[b] << ',' << B[b] << ')' << '\n'
         << "C = (" << A[c] << ',' << B[c] << ')' << '\n'
         << "D = (" << A[d] << ',' << B[d] << ')' << '\n'
         << "���������� ����� ������� ������ = " << count << endl;
}

void privetstvie(ostream& f){
    cout << "��������: ������ ������, ������� ������ 0302\n"
         << "���� ������ ����������: 22.12.2020, ���������: 25.12.2020\n"
         << "������ ���������: 76\n"
         << "---------------------������������ �������----------------------------\n"
         << "���� N ����� �� ���������. ����� ����� ��� �����, ���������� ��������� ��-\n"
         << "����, ���������� ������������ ����� �������� �����. ������: ��� ������� �.\n"
         << "===========================================================================\n";

    f    << "��������: ������ ������, ������� ������ 0302\n"
         << "���� ������ ����������: 22.12.2020, ���������: 25.12.2020\n"
         << "������ ���������: 76\n"
         << "---------------------������������ �������----------------------------\n"
         << "���� N ����� �� ���������. ����� ����� ��� �����, ���������� ��������� ��-\n"
         << "����, ���������� ������������ ����� �������� �����. ������: ��� ������� �.\n"
         << "===========================================================================\n";
}

void poisk_tochek(ostream& f, int* a, int* b, int* c, int* d,int N, float* A, float* B, int* Itog, int* count_max){
    int i,j,t,p,count,m,lmax,l,n,o,flag,kol;
    double AB,BC,CD;
    flag = 0; kol = 0;
    float vector_AB[2] = {0,0}, vector_BC[2] = {0,0}, vector_CD[2] = {0,0};
    int vspm_tek[4]={-1,-1,-1,-1}; int vspm_pr[N][4];
    for(i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if(j != i){
                vector_AB[0] = *(A+j) - *(A+i); // ���������� ������� AB �� X
                vector_AB[1] = *(B+j) - *(B+i); // ���������� ������� AB �� Y
                AB = sqrt(vector_AB[0]*vector_AB[0] + vector_AB[1]*vector_AB[1]); // ����� ������� AB
                for(t = 0; t < N; t++){
                    if( (t != j) && (t != i) ){
                        vector_BC[0] = *(A+t) - *(A+j);
                        vector_BC[1] = *(B+t) - *(B+j);
                        if((vector_AB[0]*vector_BC[0] + vector_AB[1]*vector_BC[1]) == 0){ // ���� ������ AB ��������������� ������� BC
                            BC = sqrt(vector_BC[0]*vector_BC[0] + vector_BC[1]*vector_BC[1]); // ����� ������� BC
                            for(p=0;p<N;p++){
                                if( (p!=i) && (p!=j) && (p!=t) ){
                                    vector_CD[0] = *(A+p) - *(A+t);
                                    vector_CD[1] = *(B+p) - *(B+t);
                                    if((vector_BC[0]*vector_CD[0] + vector_BC[1]*vector_CD[1]) == 0){ // ���� ������ BC ��������������� ������� CD
                                        CD = sqrt(vector_CD[0]*vector_CD[0] + vector_CD[1]*vector_CD[1]); // ����� ������� CD
                                        if(AB == CD){
                                            flag = 0;
                                            if(kol>0){
                                                vspm_tek[0] = i; vspm_tek[1]=j; vspm_tek[2]=t;vspm_tek[3]=p;
                                                for(l=0;l<3;l++){
                                                    for(n=0;n<3-l;n++){
                                                        if(vspm_tek[n]>vspm_tek[n+1]){
                                                            o = vspm_tek[n];
                                                            vspm_tek[n] = vspm_tek[n+1];
                                                            vspm_tek[n+1]=o;
                                                        }
                                                    }
                                                }
                                                for(l=0;l<kol;l++){
                                                    for(m=0;m<4;m++) {
                                                        if(vspm_tek[m] == vspm_pr[l][m]){
                                                            flag++;
                                                        }
                                                    }
                                                    if(flag >= 4) break;
                                                }
                                            }
                                            if(flag == 4){
                                                continue;
                                            }
                                            else{
                                                *Itog = 1;
                                                f << "������ ������ \n"
                                                  << "A = (" << A[i] << ';' << B[i] << ") \n"
                                                  << "B = (" << A[j] << ';' << B[j] << ") \n"
                                                  << "C = (" << A[t] << ';' << B[t] << ") \n"
                                                  << "D = (" << A[p] << ';' << B[p] << ") \n"
                                                  << "�������� ����� ����� ����������� ������ ������\n";
                                                cout << "������ ������ \n"
                                                     << "A = (" << A[i] << ';' << B[i] << ") \n"
                                                     << "B = (" << A[j] << ';' << B[j] << ") \n"
                                                     << "C = (" << A[t] << ';' << B[t] << ") \n"
                                                     << "D = (" << A[p] << ';' << B[p] << ") \n"
                                                     << "�������� ����� ����� ����������� ������ ������\n";
                                                count = 0;
                                                for(m=0;m<N;m++){
                                                    if( (m!=i) && (m!=j) && (m!=t) && (m!=p) ){
                                                        f << "����� (" << A[m] << ';' << B[m] << "): ";
                                                        cout << "����� (" << A[m] << ';' << B[m] << "): ";
                                                        if(proverka_figure(*(A+i), *(B+i), *(A+j), *(B+j), *(A+t), *(B+t),*(A+p), *(B+p), AB, BC, *(A+m), *(B+m))){
                                                            count++;
                                                            f << "����������� ������\n";
                                                            cout << "����������� ������\n";
                                                        }
                                                        else{
                                                            f << "�� ����������� ������\n";
                                                            cout << "�� ����������� ������\n";
                                                        }
                                                    }
                                                }
                                                f << "������ ������ ������ ����� " << count << " �����\n";
                                                cout << "������ ������ ������ ����� " << count << " �����\n";
                                                if(count >= lmax){
                                                    lmax = count;
                                                    *a = i; *b = j; *c = t; *d = p;
                                                    vspm_pr[kol][0]=i;vspm_pr[kol][1]=j;vspm_pr[kol][2]=t;vspm_pr[kol][3]=p;
                                                }
                                                for(l=0;l<3;l++){
                                                    for(n=0;n<3-l;n++){
                                                        if(vspm_pr[kol][n]>vspm_pr[kol][n+1]){
                                                            o = vspm_pr[kol][n];
                                                            vspm_pr[kol][n] = vspm_pr[kol][n+1];
                                                            vspm_pr[kol][n+1]=o;
                                                        }
                                                    }
                                                }
                                            }
                                            kol++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    *count_max = lmax;
}

bool proverka_figure(float Ax, float Ay, float Bx, float By, float Cx, float Cy, float Dx, float Dy, double AB, double BC, float Tx, float Ty){
    int i;
    double ugli[4] = {0,0,0,0}; // ���� ����� ���������������� ���������, ���� �� ����� ����� 2�, �� ����������� ����� ����� � �������������� ABCD
    double vector1[2] = {0,0}; //1 ������, ������ �������� ��� ����������� �����, � ����� ��� ������ ������� {x,y}
    double vector2[2] = {0,0}; //2 ������, ������ �������� ��� ����������� �����, � ����� ��� ������ �������  {x,y}
    double dlina1 = 0, dlina2 = 0;// ��������������� ����� ���� ��������, ����� �������� ������ ����
    double scal_proizv = 0;
    double sum,t,radius;
    int resultat = 1;
    double seredina1[2] = {0,0}; // ���������� x,y ����� ������� �� 1 �������, �� ������� ��������� ������ ��������������
    double seredina2[2] = {0,0}; // ���������� x,y ����� ������� �� 2 �������, �� ������� ��������� ������ ��������������
    // ������ �� ���� ������  (y1-y2)*x + (x2-x1)*y + (x1*y2 - x2*y1) = 0  ==== Ax + By + C = 0


    // �������� ����� �� ����� ������ �������������� ABCD
    sum = 0;
    for(i=0;i<4;i++){
        if(i == 0){
            vector1[0] = Ax - Tx;
            vector1[1] = Ay - Ty;
            vector2[0] = Bx - Tx;
            vector2[1] = By - Ty;
        }
        else if(i == 1){
            vector1[0] = Bx - Tx;
            vector1[1] = By - Ty;
            vector2[0] = Cx - Tx;
            vector2[1] = Cy - Ty;
        }
        else if(i == 2){
            vector1[0] = Cx - Tx;
            vector1[1] = Cy - Ty;
            vector2[0] = Dx - Tx;
            vector2[1] = Dy - Ty;
        }
        else{
            vector1[0] = Dx - Tx;
            vector1[1] = Dy - Ty;
            vector2[0] = Ax - Tx;
            vector2[1] = Ay - Ty;
        }
        dlina1 = sqrt(vector1[0]*vector1[0] + vector1[1]*vector1[1]);
        dlina2 = sqrt(vector2[0]*vector2[0] + vector2[1]*vector2[1]);
        scal_proizv = vector1[0]*vector2[0] + vector1[1]*vector2[1];
        ugli[i] = acos(scal_proizv/(dlina1*dlina2)); // ������� ���� ����� ���������
        sum = sum + ugli[i];
    }
    t = atan(1)*8;
    if(!(sum >= (t-0.0001) && (sum <= t+0.0001))) {
        resultat = 0; // ������������� ����� �� ����� ������ ��������������
        // �������� ����� �� ����� ������ ���� ���������������
        // ���� ����� �� ����� ������ �������������� �� ����� ������ ���� �����������, ������ ��� ������ ����� ������ ���� ���������������
        if(AB>=BC){ // �������������� �������������� ����� ��������� �� �������� BC � DA
            seredina1[0] = (Bx+Cx)/2;
            seredina1[1] = (By+Cy)/2;
            seredina2[0] = (Dx+Ax)/2;
            seredina2[1] = (Dy+Ay)/2;
            //1 ���������� (x - seredina1[0])^2 + (y - seredina1[1])^2 = radius^2
            //2 ���������� (x - seredina2[0])^2 + (y - seredina2[1])^2 = radius^2
            radius = BC/2;
            if( ((Tx-seredina1[0])*(Tx-seredina1[0]) + (Ty-seredina1[1])*(Ty-seredina1[1])) < (radius*radius) ){
                resultat = 1;
            }
            else if( ((Tx-seredina2[0])*(Tx-seredina2[0]) + (Ty-seredina2[1])*(Ty-seredina2[1])) < (radius*radius) ){
                resultat = 1;
            }
        }
        else{// �������������� �� �������� AB � CD
            seredina1[0] = (Ax+Bx)/2;
            seredina1[1] = (Ay+By)/2;
            seredina2[0] = (Cx+Dx)/2;
            seredina2[1] = (Cy+Dy)/2;
            radius = AB/2;
            if( ((Tx-seredina1[0])*(Tx-seredina1[0]) + (Ty-seredina1[1])*(Ty-seredina1[1])) < (radius*radius) ){
                resultat = 1;
            }
            else if( ((Tx-seredina2[0])*(Tx-seredina2[0]) + (Ty-seredina2[1])*(Ty-seredina2[1])) < (radius*radius) ){
                resultat = 1;
            }
        }
    }

    if(resultat == 1){
        return true;
    }
    else{
        return false;
    }
}