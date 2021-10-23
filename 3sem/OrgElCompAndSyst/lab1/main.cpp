#include <math.h>
#include <iostream>

void printUnsignedChar(unsigned char num);
void printLongDouble(long double num);

int main() {

    unsigned char unsChar;
    long double lonDouble;
    int version = -1;
    int Try = 2;

    while (1) {
        std::cout << "Enter action number: 1 - enter unsigned char, 2 - enter long double, 0 - end program." << std::endl;
        std::cin >> version;
        if (version == 1) {
            std::cin >> unsChar;
            printUnsignedChar(unsChar);
        }
        else if (version == 2) {
            std::cin >> lonDouble;
            printLongDouble(lonDouble);
        }
        else if (version == 0) {
            std::cout << "End of program" << std::endl;
            return 0;
        }
        else {
            std::cout << "ERROR_VERSION" << std::endl;
            if (Try > 0) {
                Try--;
                continue;
            }
            return -1;
        }
    }
}

void printUnsignedChar(unsigned char num) {
    int iterator, j, bit;
    int arrayBits[8 * sizeof(unsigned char)];

    int countBits, numberOfBit, newValueOfBit;
    int tryCountBits, tryNumberBits, tryValueBit;
    tryCountBits = 3;
    tryNumberBits = 3;
    tryValueBit = 3;

    std::cout << "Unsigned char value in binary code: ";
    for (iterator = 8 * sizeof(num) - 1; iterator >= 0; iterator--) {
        bit = num >> iterator;
        bit = bit & 1;
        arrayBits[iterator] = bit;
        std::cout << bit;
    }
    std::cout << std::endl;


    std::cout << "Enter the count of bits, their numbersand new values to change" << std::endl;
    std::cout << "Count bits:";
    std::cin >> countBits;

    for (iterator = 0; ; iterator++) {
        if ((countBits >= 0) && (countBits <= 8 * sizeof(unsigned char)))
            break;
        else {
            tryCountBits--;
            if (tryCountBits > 0) {
                std::cout << "Please enter count bits correct" << std::endl;
                std::cin >> countBits;
            }
            else {
                std::cout << "Error count bits in unsigned char" << std::endl;
                return;
            }
        }
    }

    for (iterator = 0; iterator < countBits; iterator++) {
        std::cout << "Number of bit = ";
        std::cin >> numberOfBit;

        for (j = 0; ; j++) {
            if ((numberOfBit >= 0) && (numberOfBit < 8 * sizeof(unsigned char)))
                break;
            else {
                tryNumberBits--;
                if (tryNumberBits > 0) {
                    std::cout << "Please enter number of the bit correct" << std::endl;
                    std::cin >> numberOfBit;
                }
                else {
                    std::cout << "Error number of the bit in unsigned char" << std::endl;
                    return;
                }
            }
        }

        std::cout << "New value of the bit = ";
        std::cin >> newValueOfBit;

        for (j = 0; ; j++) {
            if ((newValueOfBit == 0) || (newValueOfBit == 1))
                break;
            else {
                tryValueBit--;
                if (tryValueBit > 0) {
                    std::cout << "Please enter value of the bit correct" << std::endl;
                    std::cin >> newValueOfBit;
                }
                else {
                    std::cout << "Error value of the bit in unsigned char" << std::endl;
                    return;
                }
            }
        }

        arrayBits[numberOfBit] = newValueOfBit;

    }
    std::cout << "unsigned char after changes in binary code: ";
    for (iterator = 8 * sizeof(unsigned char) - 1; iterator >= 0; iterator--) {
        std::cout << arrayBits[iterator];
    }
    std::cout << std::endl;

    for (iterator = 0; iterator < 8 * sizeof(unsigned char) / 2; iterator++) {
        j = arrayBits[iterator];
        arrayBits[iterator] = arrayBits[8 * sizeof(unsigned char) - 1 - iterator];
        arrayBits[8 * sizeof(unsigned char) - 1 - iterator] = j;
    }

    std::cout << "unsigned char after changes: ";
    num = 0;
    for (iterator = 8 * sizeof(unsigned char) - 1; iterator >= 0; iterator--) {
        if (arrayBits[iterator] == 1) {
            num += pow(2, 8 * sizeof(unsigned char) - (iterator + 1));
        }
    }
    std::cout << num << std::endl;
}
void printLongDouble(long double num) {
    int i, j;

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
        for (j = 7; j >= 0; j--) {
            arrayBits[i][j] = ((1 << j) & u.c[i]) ? 1 : 0;
        }
    }

    for (i = 0; i < sizeof(long double) / 2; i++) {
        for (j = 0; j < 8; j++) {
            tmpArray[i][j] = arrayBits[sizeof(long double) - i - 1][j];
            arrayBits[sizeof(long double) - i - 1][j] = arrayBits[i][j];
            arrayBits[i][j] = tmpArray[i][j];
        }
    }

    for (i = 0; i < sizeof(long double); i++) {
        for (j = 0; j < 4; j++) {
            tmpArray[i][j] = arrayBits[i][7 - j];
            arrayBits[i][7 - j] = arrayBits[i][j];
            arrayBits[i][j] = tmpArray[i][j];
        }
    }
    std::cout << "long double value in binary code: ";
    for (i = 0; i < sizeof(long double); i++) {
        for (j = 0; j < 8; j++) {
            std::cout << arrayBits[i][j];
        }
    }
    std::cout << std::endl;

    std::cout << "Sign: " << arrayBits[0][0] << std::endl;

    std::cout << "Exponenta: ";
    for (i = 0; i < sizeof(long double) - (sizeof(long double) - 2); i++) {
        for (j = 0; j < 8; j++) {
            if ((i == 0) && (j == 0)) {
                continue;
            }
            else {
                std::cout << arrayBits[i][j];
            }
        }
    }
    std::cout << std::endl;

    std::cout << "Mantisa: ";
    for (i = 2; i < sizeof(long double); i++) {
        for (j = 0; j < 8; j++) {
            std::cout << arrayBits[i][j];
        }
    }
    std::cout << std::endl;


    std::cout << "Enter the count of bits, their numbers and new values to change" << std::endl;
    std::cout << "Count bits:";
    std::cin >> countBits;

    for (i = 0; ; i++) {
        if ((countBits >= 0) && (countBits <= 8 * sizeof(long double)))
            break;
        else {
            tryCountBits--;
            if (tryCountBits > 0) {
                std::cout << "Please enter count bits correct" << std::endl;
                std::cin >> countBits;
            }
            else {
                std::cout << "Error count bits in unsigned char" << std::endl;
                return;
            }
        }
    }


    for (i = 0; i < countBits; i++) {
        std::cout << "Number of bit = ";
        std::cin >> numberOfBit;

        for (j = 0; ; j++) {
            if ((numberOfBit >= 0) && (numberOfBit < 8 * sizeof(long double)))
                break;
            else {
                tryNumberBits--;
                if (tryNumberBits > 0) {
                    std::cout << "Please enter number of the bit correct" << std::endl;
                    std::cin >> numberOfBit;
                }
                else {
                    std::cout << "Error number of the bit in unsigned char" << std::endl;
                    return;
                }
            }
        }

        std::cout << "New value of the bit = ";
        std::cin >> newValueOfBit;

        for (j = 0; ; j++) {
            if ((newValueOfBit == 0) || (newValueOfBit == 1))
                break;
            else {
                tryValueBit--;
                if (tryValueBit > 0) {
                    std::cout << "Please enter value of the bit correct" << std::endl;
                    std::cin >> newValueOfBit;
                }
                else {
                    std::cout << "Error value of the bit in unsigned char" << std::endl;
                    return;
                }
            }
        }
        numberOfBit = 8 * sizeof(long double) - 1 - numberOfBit;
        if (numberOfBit == 80)
            numberOfBit--;
        arrayBits[numberOfBit / 8][numberOfBit % 8] = newValueOfBit;
    }

    std::cout << "Long double after changes" << std::endl;

    int exponentaCount = 0;
    long double result;
    int reverseArray[8 * sizeof(long double)];
    int reverse_2[64];

    if (countBits == 0) {
        std::cout << num << std::endl;
        return;
    }

    for (i = 0; i < sizeof(long double); i++) {
        for (j = 0; j < 8; j++) {
            reverseArray[8 * i + j] = arrayBits[i][j];
        }
    }


    for (i = 0; i < 64; i++) {
        reverse_2[i] = reverseArray[63 - i];
    }



    j = 0;

    for (i = 52; i < 63; i++)
    {
        exponentaCount = exponentaCount + (reverse_2[i] * pow(2, j)); j++;
    }

    exponentaCount = abs(exponentaCount - 1023);

    result = 0.0; j = 0;
    for (i = 52 - exponentaCount; i < 52; i++)
    {
        result = result + (reverse_2[i] * pow(2, j)); j++;
    }
    result = result + pow(2, j); j = 1;
    for (i = 51 - exponentaCount; i > -1; i--)
    {
        result = result + (reverse_2[i] * pow(2, -j)); j++;
    }

    if (reverse_2[63] == 1) result *= -1;
    std::cout << "Changed number in decimal: " << result << std::endl;

}