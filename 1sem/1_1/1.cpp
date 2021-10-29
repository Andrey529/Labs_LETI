/*
 јвтор: Ѕлюдин јндрей »горевич, группа: 0302
 ¬ерси€: 1.
 ‘ормулировка: P = x^8+ x^2 Ц x + 1. Q = Ц2,24x^12Ц23,73x^8 + 24,53x^2.
 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    float x,P1,P2,P3,Q1,Q2,Q3,res;
    setlocale(LC_CTYPE, "rus");
    cout << "Ѕлюдин јндрей »горевич, группа 0302\n" << "ƒаты: начало разработки 23.09.2020, окончание 24.09.2020\n"
    << "¬ерси€: 1.23\n" << "‘ормулировка: P = x^8+ x^2 Ц x + 1; Q = Ц2,24x^12Ц23,73x^8 + 24,53x^2.\n" << "¬ведите x: " << endl;
    cin >> x;
    P1 = x*x*x*x*x*x + 1;
    P2 = x*P1 - 1;
    P3 = x*P2 + 1;
    cout << "Ўаг 1: P1 = " << setw(9) << setprecision(5) << fixed << P1 << "\n";
    cout << "Ўаг 2: P2 = " << setw(9) << setprecision(5) << fixed <<P2 << "\n";
    cout << "Ўаг 3: P(x) = " << setw(9) << setprecision(5) << fixed << P3 << "\n";
    Q1 = x*x*x*x*(-2.24)-23.73;
    Q2 = x*x*x*x*x*x*Q1 + 24.53;
    Q3 = x*x*Q2;
    cout << "Ўаг 4: Q1 = " << setw(9) << setprecision(5) << fixed << Q1 << "\n";
    cout << "Ўаг 5: Q2 = " << setw(9) << setprecision(5) << fixed << Q2 << "\n";
    cout << "Ўаг 6: Q(x) = " << setw(9) << setprecision(5) << fixed << Q3 << "\n";
    res = P3/Q3;
    cout << "ƒл€ x = "<< setprecision(6) << x << " ; –езультат равен: " << res;
    return 0;
}