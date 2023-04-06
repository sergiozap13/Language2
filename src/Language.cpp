/*
 * Metodología de la Programación: Language2
 * Curso 2022/2023
 */

/** 
 * @file Language.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 29 January 2023, 11:00
 */

#include "Language.h"

using namespace std;

const string Language::MAGIC_STRING_T="MP-LANGUAGE-T-1.0";

Language::Language(){
    this->_languageId = "unknown";
    this->_size = 0;
}

Language::Language(int numberBigrams){
    if(numberBigrams > DIM_VECTOR_BIGRAM_FREQ || numberBigrams < 0){
        throw std::out_of_range("const char Bigram::at(int index) invalid position (" + std::to_string(numberBigrams) + ")"
                    + " and it can only be 0 or 1");
    }
    
    this->_size = numberBigrams;
    this->_languageId = "unknown";
    for(int i = 0; i < numberBigrams; i++){
        Bigram b;
        this->_vectorBigramFreq[i].setBigram(b);
        this->_vectorBigramFreq[i].setFrequency(0);
    }
}

const std::string& Language::getLanguageId() const{
    return this->_languageId;
}

void Language::setLanguageId(std::string id){
    this->_languageId = id;
}

const BigramFreq& Language::at(int index) const{
    if(index < 0 || index > DIM_VECTOR_BIGRAM_FREQ){
        throw std::out_of_range("const char Bigram::at(int index) invalid position (" + std::to_string(index) + ")"
                    + " and it can only be 0 or 1");
    }
    return this->_vectorBigramFreq[index];
}

BigramFreq& Language::at(int index){
    if(index < 0 || index > DIM_VECTOR_BIGRAM_FREQ){
        throw std::out_of_range("const char Bigram::at(int index) invalid position (" + std::to_string(index) + ")"
                    + " and it can only be 0 or 1");
    }
    return this->_vectorBigramFreq[index];
}

int Language::getSize() const{
    return this->_size;
}

int Language::findBigram(const Bigram &bigram) const{
    
    for(int i = 0; i < getSize(); i++){
        if(at(i).getBigram().getText() == bigram.getText()){
           return i; 
        }
    }
    return -1;
}

std::string Language::toString() const {
    
}

void Language::sort(){

    int max_index = 0;
    for (int i = 0; i < getSize(); i++){
        max_index = i;
        for (int j = i +1; j < getSize(); j++){
            if(at(j).getFrequency() > at(max_index).getFrequency())
                max_index = j;
            else if(at(j).getFrequency() == at(max_index).getFrequency() &&
                        at(j).getBigram().getText() < at(max_index).getBigram().getText())
                max_index = j;
        }
        swapElements(i, max_index);
    }
   
}

void Language::save(char fileName[]){
    
}

void Language::load(char fileName[]){
    
}

void Language::append(BigramFreq bigramFreq){
    
}

void Language::join(Language language){
    
}

void Language::swapElements(int first, int second){
    
    if(first < getSize() && second < getSize() && first >= 0 && second >= 1 && first != second){
        BigramFreq temp = at(first);
        at(first) = at(second);
        at(second) = temp;
    }
}