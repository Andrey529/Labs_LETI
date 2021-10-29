/*
 јвтор: Ѕлюдин јндрей »горевич, группа: 0302
 ¬ерси€: 1.23
 ‘ормулировка: P = x^8+ x^2 Ц x + 1. Q = Ц2,24x^12Ц23,73x^8 + 24,53x^2.
 */
#include <stdio.h>
#include <iomanip>

using namespace std;

int main() {
    float x,P1,P2,P3,Q1,Q2,Q3,res;
    setlocale(LC_CTYPE, "rus");
    printf("%s\n%s\n%s\n%s\n%s","Ѕлюдин јндрей »горевич, группа 0302",
           "ƒаты: начало разработки 23.09.2020, окончание 24.09.2020","¬ерси€: 1.23",
           "‘ормулировка: P = x^8+ x^2 Ц x + 1; Q = Ц2,24x^12Ц23,73x^8 + 24,53x^2.","¬ведите x:");
    scanf("%f",&x);
    P1 = x*x*x*x*x*x + 1;
    P2 = x*P1 - 1;
    P3 = x*P2 + 1;
    printf("%s%.4f\n","Ўаг 1: P1 = ", P1);
    printf("%s%.4f\n","Ўаг 2: P2 = " ,P2);
    printf("%s%.4f\n","Ўаг 3: P(x) = ",P3);
    Q1 = x*x*x*x*(-2.24) - 23.73;
    Q2 = x*x*x*x*x*x*Q1 + 24.53;
    Q3 = x*x*Q2;
    printf("%s%.4f\n","Ўаг 4: Q1 = ", Q1);
    printf("%s%.4f\n","Ўаг 5: Q2 = " ,Q2);
    printf("%s%.4f\n","Ўаг 6: Q(x) = ",Q3);
    res = P3/Q3;
    printf("%s%.4f%s%.4f","ƒл€ x = ",x," ; –езультат равен: ",res);
    return 0;
}
