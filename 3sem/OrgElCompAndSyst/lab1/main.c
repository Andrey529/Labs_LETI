#include <stdio.h>

void printUnsignedChar(unsigned char num);
void printLongDouble(long double num);

int main() {

    unsigned char unsChar;

    long double lonDouble;

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
    int iterator, j, bit;
    int arrayBits[8 * sizeof(unsigned char)];

    int countBits, numberOfBit, newValueOfBit;
    int tryCountBits, tryNumberBits, tryValueBit;
    tryCountBits = 3;
    tryNumberBits = 3;
    tryValueBit = 3;

    printf("Unsigned char value in binary code: ");
    for(iterator = 8*sizeof(num)-1; iterator >= 0; iterator--){
        bit = num >> iterator;
        bit = bit & 1;
        arrayBits[iterator] = bit;
        printf("%i", bit);
    }
    printf("\n");


    printf("Enter the count of bits, their numbers and new values to change\n"
           "Count bits:");
    scanf("%d",&countBits);

    for(iterator = 0; ; iterator++){
        if((countBits >= 0) && (countBits <= 8* sizeof(unsigned char )))
            break;
        else{
            tryCountBits--;
            if(tryCountBits > 0){
                printf("Please enter count bits correct\n");
                scanf("%d",&countBits);
            }
            else{
                printf("Error count bits in unsigned char\n");
                return;
            }
        }
    }

    for(iterator = 0; iterator < countBits; iterator++){
        printf("Number of bit = ");
        scanf("%d",&numberOfBit);

        for(j = 0; ; j++){
            if((numberOfBit >= 0) && (numberOfBit < 8*sizeof(unsigned char )))
                break;
            else{
                tryNumberBits--;
                if(tryNumberBits > 0){
                    printf("Please enter number of the bit correct\n");
                    scanf("%d",&numberOfBit);
                }
                else{
                    printf("Error number of the bit in unsigned char\n");
                    return;
                }
            }
        }

        printf("New value of the bit = ");
        scanf("%d",&newValueOfBit);

        for(j = 0; ; j++){
            if((newValueOfBit == 0) || (newValueOfBit == 1))
                break;
            else{
                tryValueBit--;
                if(tryValueBit > 0){
                    printf("Please enter value of the bit correct\n");
                    scanf("%d",&newValueOfBit);
                }
                else{
                    printf("Error value of the bit in unsigned char\n");
                    return;
                }
            }
        }

        arrayBits[numberOfBit] = newValueOfBit;

    }
    printf("unsigned char after changes: ");
    for(iterator = 8*sizeof(unsigned char) - 1; iterator >= 0; iterator--){
        printf("%d",arrayBits[iterator]);
    }
    printf("\n");

}
void printLongDouble(long double num){
    int i,j;
    int arrayBits[sizeof(long double)][8];
    int tmpArray[sizeof(long double)][8];
    union {
        long double x;
        char c[sizeof(long double)];
    } u;

    int countBits, numberOfBit, newValueOfBit;
    int tryCountBits, tryNumberBits, tryValueBit;
    tryCountBits = 3;
    tryNumberBits = 3;
    tryValueBit = 3;

    u.x = num;

    for (i = 0; i < sizeof(long double); i++) {
        for(j = 7; j >= 0; j--) {
            arrayBits[i][j] = ((1 << j) & u.c[i]) ? 1 : 0;
        }
    }

    for (i = 0; i < sizeof(long double)/2; i++) {
        for(j = 0; j < 8; j++) {
            tmpArray[i][j] = arrayBits[sizeof(long double)-i-1][j];
            arrayBits[sizeof(long double)-i-1][j] = arrayBits[i][j];
            arrayBits[i][j] = tmpArray[i][j];
        }
    }

    for(i = 0; i < sizeof(long double );i++){
        for (j = 0; j < 4; j++){
            tmpArray[i][j] = arrayBits[i][7-j];
            arrayBits[i][7-j] = arrayBits[i][j];
            arrayBits[i][j] = tmpArray[i][j];
        }
    }
    printf("long double value in binary code: ");
    for (i = 0; i < sizeof(long double); i++) {
        for(j = 0; j < 8; j++) {
            printf("%d",arrayBits[i][j]);
        }
    }
    printf("\n");

    printf("Sign: %d\n",arrayBits[0][0]);

    printf("Exponenta: ");
    for (i = 0; i < sizeof(long double) - (sizeof(long double) - 2); i++) {
        for(j = 0; j < 8; j++) {
            if ((i == 0) && (j == 0)){
                continue;
            } else {
                printf("%d", arrayBits[i][j]);
            }
        }
    }
    printf("\n");

    printf("Mantisa: ");
    for (i = 2; i < sizeof(long double); i++) {
        for(j = 0; j < 8; j++) {
            printf("%d", arrayBits[i][j]);
        }
    }
    printf("\n");


    printf("Enter the count of bits, their numbers and new values to change\n"
           "Count bits:");
    scanf("%d",&countBits);

    for(i = 0; ; i++){
        if((countBits >= 0) && (countBits <= 8* sizeof(long double)))
            break;
        else{
            tryCountBits--;
            if(tryCountBits > 0){
                printf("Please enter count bits correct\n");
                scanf("%d",&countBits);
            }
            else{
                printf("Error count bits in unsigned char\n");
                return;
            }
        }
    }

    for(i = 0; i < countBits; i++){
        printf("Number of bit = ");
        scanf("%d",&numberOfBit);

        for(j = 0; ; j++){
            if((numberOfBit >= 0) && (numberOfBit < 8*sizeof(long double)))
                break;
            else{
                tryNumberBits--;
                if(tryNumberBits > 0){
                    printf("Please enter number of the bit correct\n");
                    scanf("%d",&numberOfBit);
                }
                else{
                    printf("Error number of the bit in unsigned char\n");
                    return;
                }
            }
        }

        printf("New value of the bit = ");
        scanf("%d",&newValueOfBit);

        for(j = 0; ; j++){
            if((newValueOfBit == 0) || (newValueOfBit == 1))
                break;
            else{
                tryValueBit--;
                if(tryValueBit > 0){
                    printf("Please enter value of the bit correct\n");
                    scanf("%d",&newValueOfBit);
                }
                else{
                    printf("Error value of the bit in unsigned char\n");
                    return;
                }
            }
        }
        numberOfBit = 8*sizeof(long double)-1-numberOfBit;
        if(numberOfBit == 80)
            numberOfBit--;
        arrayBits[numberOfBit / 8][numberOfBit % 8] = newValueOfBit;
    }
    printf("long double after changes: ");
    for(i = 0; i < sizeof(long double); i++){
        for(j = 0; j < 8; j++){
            printf("%d",arrayBits[i][j]);
        }
        printf(" ");
    }
    printf("\n");

}