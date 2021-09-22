#include <stdio.h>

void printUnsignedChar(unsigned char num);
void printLongDouble(long double num);

int main() {

    unsigned char unsChar;
    unsigned char *pUnsChar = &unsChar;

    long double lonDouble;
    long double *pLonDouble = &lonDouble;

    int version = -1;
    int try = 2;


    while (1){
        printf("Enter action number: 1 - enter unsigned char, 2 - enter long double, 0 - end program.\n");
        scanf("%i",&version);
        if(version == 1){
            scanf("%d",&unsChar);
            printUnsignedChar(unsChar);
        }
        else if(version == 2){
            scanf("%Lf",&lonDouble);
            printf("%Lf\n",lonDouble);
            printLongDouble(lonDouble);
        }
        else if(version == 0){
            printf("End of program");
            return 0;
        }
        else{
            printf("ERROR_VERSION\n");
            if(try > 0){
                try--;
                continue;
            }
            return -1;
        }
    }
}

void printUnsignedChar(unsigned char num){
    int iterator, bit;
    printf("Unsigned char value in binary code: ");
    for(iterator = 8*sizeof(num)-1; iterator >= 0; iterator--){
        bit = num >> iterator;
        bit = bit & 1;
        printf("%i", bit);
    }
    printf("\n");
}

void printLongDouble(long double num){
    unsigned ofs;
    int i;

    union {
        long double x;
        char c[sizeof(long double)];
    } u;

    u.x = num;

    for (ofs = 0; ofs < sizeof(long double); ofs++) {
        for(i = 7; i >= 0; i--) {
            printf(((1 << i) & u.c[ofs]) ? "1" : "0");
        }
        printf(" ");
    }
    printf("\n");
}
