#include <stdio.h>
#include <iomanip>
using namespace std;
int main() {
    float x,x2,a,b,T,P,y;
    setlocale(0,"rus");
    printf("%s\n%s\n%s\n","Блюдин Андрей Игоревич, группа 0302",
           "Даты: начало разработки 27.09.2020, окончание 7.10.2020","Версия: 1.47");
    printf("%s%s%s","  ___/\\    ___/\\ \n"," /     \\  /     \\ \n","/       \\/       \\ \n");
    printf("%s","Введите x, a, b:");
    scanf("%f%f%f",&x,&a,&b);
    x2 = x;
    // перевод х в первый период
    T = x/(4*a);
    P = int (T);
    T = T - P;

    if (T < 0)
        T = 1 + T;
    x = T*4*a;
    if (x < 0)
        x = -x;

    a = abs(a);
    // вычисление у по х исходя из положения х
    if (x < a)
        y = ((2*b)/a)*x - 2*b;
    if (x >= a && x < 2*a)
        y = 0;
    if (x >= 2*a && x < 3*a)
        y = x*(b/a) - 2*b;
    if (x >= 3*a && x <= 4*a)
        y = x*(-3)*(b/a) + 10*b;
    if (a != 0)
        printf("%s%.7f%s%.7f","Для заданного значения x = ",x2,", значение y = ", y);
    else
        printf("%s","При а = 0 график не будет существовать");
    return 0;
}
