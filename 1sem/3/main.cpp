#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
int main() {
    float x,eps; int i; long double U,S,k;
    fstream f;
    f.open("C:\\Users\\andre\\CLionProjects\\3\\repeat_f.txt",ios::out);
    setlocale(0,"rus");
    cout << "������ ������ ��������, ������ 0302\n" << "����: ������ ���������� 10.10.2020, ��������� 11.10.2020\n"
         << "������: 1.56\n" << "������������: U(i)=(x^(3i+2))/(3i+2)!.\n"<< endl;
    f << "������ ������ ��������, ������ 0302\n"<< "����: ������ ���������� 10.10.2020, ��������� 11.10.2020\n"
      << "������: 1.56\n" << "������������: U(i)=(x^(3i+2))/(3i+2)!.\n"<< endl;
    i = 0;
    // ������ �������, ���� �� �� ����� ��������� ����������� ��� i ������ ������ 3.
    do {
        cout << "������� �������:";
        cin >> eps;
        i ++;
    }
    while(((eps<=0)||(eps>((1.0/10)*(1.0/10)*(1.0/10)*(1.0/10)*(1.0/10)*(1.0/10))))&&(i<3));
    //������� ��������� �� ������ ��� ������� ������� ����� �������
    if ((i>=3)&&((eps<=0)||(eps>((1.0/10)*(1.0/10)*(1.0/10)*(1.0/10)*(1.0/10)*(1.0/10))))) {
        cout << "Error" << endl;
        f << "Error" << endl;
    }
    else {
        i = 0;
        cout << "������� x:";
        cin >> x;
        U = (x*x) / 2.0;
        S = U;
        cout << "\n|     i     |     U     |     S     |\n" << "|     " << i << "     |" << setiosflags(ios::scientific)
             << setw(6) << setprecision(4) << setiosflags(ios::showpos) << U << "|" << S << "|\n";
        f << "\n|     i     |     U     |     S     |\n" << "|     " << i << "     |"<< setiosflags(ios::scientific)
          << setw(6) << setprecision(4) << setiosflags(ios::showpos) << U << "|" << S << "|\n";
        while ((fabs(U) > eps) && (i <= 1000)) {
            k = ((x * x * x) / ((3 * i + 3) * (3 * i + 4) * (3 * i + 5)));
            i ++;
            U = U * k;
            S = S + U;
            cout << "|" << setw(6) << resetiosflags(ios::showpos) << i << "     |" << setiosflags(ios::scientific)
                 << setiosflags(ios::showpos) << setiosflags(ios::showpoint) << setprecision(4)
                 << U << "|" << S << "|" << endl;
            f << "|" << setw(6) << resetiosflags(ios::showpos) << i << "     |" << setiosflags(ios::scientific)
              << setiosflags(ios::showpos) << setiosflags(ios::showpoint) << setprecision(4)
              << U << "|" << S << "|" << endl;
        }
        i += 1;
        cout << "\n" << resetiosflags(ios::showpos) << "�� " << i << " ����� ��������� ����� = " << S << endl;
        f << "\n" << resetiosflags(ios::showpos) << "�� " << i << " ����� ��������� ����� = " << S << endl;
    }
    f.close();
}
