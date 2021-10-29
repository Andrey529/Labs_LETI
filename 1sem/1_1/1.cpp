/*
 �����: ������ ������ ��������, ������: 0302
 ������: 1.
 ������������: P = x^8+ x^2 � x + 1. Q = �2,24x^12�23,73x^8 + 24,53x^2.
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float x,P1,P2,P3,Q1,Q2,Q3,res;
    setlocale(LC_CTYPE, "rus");
    cout << "������ ������ ��������, ������ 0302\n" << "����: ������ ���������� 23.09.2020, ��������� 24.09.2020\n"
    << "������: 1.23\n" << "������������: P = x^8+ x^2 � x + 1; Q = �2,24x^12�23,73x^8 + 24,53x^2.\n" << "������� x: " << endl;
    cin >> x;
    P1 = x*x*x*x*x*x + 1;
    P2 = x*P1 - 1;
    P3 = x*P2 + 1;
    cout << "��� 1: P1 = " << setw(9) << setprecision(5) << fixed << P1 << "\n";
    cout << "��� 2: P2 = " << setw(9) << setprecision(5) << fixed <<P2 << "\n";
    cout << "��� 3: P(x) = " << setw(9) << setprecision(5) << fixed << P3 << "\n";
    Q1 = x*x*x*x*(-2.24)-23.73;
    Q2 = x*x*x*x*x*x*Q1 + 24.53;
    Q3 = x*x*Q2;
    cout << "��� 4: Q1 = " << setw(9) << setprecision(5) << fixed << Q1 << "\n";
    cout << "��� 5: Q2 = " << setw(9) << setprecision(5) << fixed << Q2 << "\n";
    cout << "��� 6: Q(x) = " << setw(9) << setprecision(5) << fixed << Q3 << "\n";
    res = P3/Q3;
    cout << "��� x = "<< setprecision(6) << x << " ; ��������� �����: " << res;
    return 0;
}