#ifndef LAB2_2SEM_PROGA_SITUATIONS_H
#define LAB2_2SEM_PROGA_SITUATIONS_H

enum class Situations{
    END_OF_FILE,      // � ����� ����� ����� � ������ � � ���������� ������� ���� �����
    END_OF_FILE___RIGHT_BLOC, // � ����� ����� ����� � ������, �� � ���������� ������� �� ����� � ������� �����
                              // ���� ������ ���� ������
    END_OF_FILE___LAST_BLOC,  // � ���������� ������ ����� ��� ����� �����, �� ���������� ������ ��������� ������ � ���� �����
    END_OF_FILE___CURENT_BLOC, // � ���������� ������ ����� ��� ����� �����, �� ���������� ������ ��������� ������ � ����������� ������
    END_OF_FILE_IN_STRING,
    NEW_LINE,
    GOOG,
    BAD,
};
#endif //LAB2_2SEM_PROGA_SITUATIONS_H
