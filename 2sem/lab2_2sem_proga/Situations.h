#ifndef LAB2_2SEM_PROGA_SITUATIONS_H
#define LAB2_2SEM_PROGA_SITUATIONS_H

enum class Situations{
    END_OF_FILE,      // в блоке конец файла в строке и в предыдущих строках тоже конец
    END_OF_FILE___RIGHT_BLOC, // в блоке конец файла в строке, но в предыдущих строках не конец в текущем блоке
                              // надо делать блок справа
    END_OF_FILE___LAST_BLOC,  // в предыдущих блоках слева был конец файла, но предыдущии строки кончаются только в этом блоке
    END_OF_FILE___CURENT_BLOC, // в предыдущих блоках слева был конец файла, но предыдущии строки кончаются только в последующих блоках
    END_OF_FILE_IN_STRING,
    NEW_LINE,
    GOOG,
    BAD,
};
#endif //LAB2_2SEM_PROGA_SITUATIONS_H
