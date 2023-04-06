/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * @file:   Bigram.cpp
 * @author estudiante1: Sergio Zapata De la Hoz <sergiozap@correo.ugr.es>
 * 
 * Created on 5 de marzo de 2023, 13:44
 */

#include <cstring>

#include "Bigram.h"

Bigram::Bigram(const std::string& text) {
    if(text.size() == 2){
        std::strcpy(this->_text, text.c_str());
    } else {
        std::strcpy(this->_text, "__");
    }
}

Bigram::Bigram(char first,char second){
    char cadena[3];
    cadena[0] = first;
    cadena[1] = second;
    
    std::strcpy(this->_text, cadena);
}

Bigram::Bigram(const char text[]){
    if(std::strlen(text) == 2){
        for(int i = 0; i < strlen(text); i++){
            this->_text[i] = text[i];
        }
    } else {
        std::strcpy(this->_text, "__");
    }
}

std::string Bigram::getText() const{
    return this->_text;
}

std::string Bigram::toString() const{
    return this->_text;
}

const char& Bigram::at(int index) const{
    if(index < 0 || index > 1){
        throw std::out_of_range("const char Bigram::at(int index) invalid position (" + std::to_string(index) + ")"
                    + " and it can only be 0 or 1");
    } else{
        return _text[index];
    }     
}

char& Bigram::at(int index){
    if(index < 0 || index > 1){
        throw std::out_of_range("char Bigram::at(int index) invalid position (" + std::to_string(index) + ")"
                    + " and it can only be 0 or 1");
    } else{
        return _text[index];
    }
}

void Bigram::toUpper(){
    int tam = strlen(_text);
    
    for (int i = 0; i < tam; i++){
        if(islower(_text[i])){
            _text[i] = std::toupper(_text[i]); 
        }
    }
}

bool isValidCharacter(char character, const std::string& validCharacters){
    
    return validCharacters.find(character) != std::string::npos;
}

void toLower(Bigram &bigram){
    int tam = bigram.getText().length();
    
    for (int i = 0; i < tam; i++){
        if(isupper(bigram.at(i))){
            bigram.at(i) = std::tolower(bigram.at(i)); 
        }
    }
}
