#include "All_Strings.h"

int search_count_sentences(All_Strings* txt){
    int sentence = 0;
    for(int row = 0; row < 5; row++){
        int column = 0;
        while((txt->getStr(row,column)) != txt->getMark()){
            if((txt->getStr(row,column)) == '.'){
                sentence++;
            }
            else if((txt->getStr(row,column)) == '!'){
                sentence++;
            }
            else if((txt->getStr(row,column)) == '?'){
                sentence++;
            }
            column++;
        }
    }
    return sentence;
}
