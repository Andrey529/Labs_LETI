#include <stdio.h>
#include <iomanip>
using namespace std;
int main() {
    float x,x2,a,b,T,P,y;
    setlocale(0,"rus");
    printf("%s\n%s\n%s\n","������ ������ ��������, ������ 0302",
           "����: ������ ���������� 27.09.2020, ��������� 7.10.2020","������: 1.47");
    printf("%s%s%s","  ___/\\    ___/\\ \n"," /     \\  /     \\ \n","/       \\/       \\ \n");
    printf("%s","������� x, a, b:");
    scanf("%f%f%f",&x,&a,&b);
    x2 = x;
    // ������� � � ������ ������
    T = x/(4*a);
    P = int (T);
    T = T - P;

    if (T < 0)
        T = 1 + T;
    x = T*4*a;
    if (x < 0)
        x = -x;

    a = abs(a);
    // ���������� � �� � ������ �� ��������� �
    if (x < a)
        y = ((2*b)/a)*x - 2*b;
    if (x >= a && x < 2*a)
        y = 0;
    if (x >= 2*a && x < 3*a)
        y = x*(b/a) - 2*b;
    if (x >= 3*a && x <= 4*a)
        y = x*(-3)*(b/a) + 10*b;
    if (a != 0)
        printf("%s%.7f%s%.7f","��� ��������� �������� x = ",x2,", �������� y = ", y);
    else
        printf("%s","��� � = 0 ������ �� ����� ������������");
    return 0;
}
