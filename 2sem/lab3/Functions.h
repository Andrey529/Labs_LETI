#include "header.h"

#ifndef LAB3_FUNCTIONS_H
#define LAB3_FUNCTIONS_H

bool notEmptyPointer(elementList *pointer);
void newElement(elementList **pointer);
void addNextElement();
void addFirstElement();

void inputList(std::fstream &f_in, elementList **head);
//void DeleteAllList(elementList **head);

#endif //LAB3_FUNCTIONS_H
