/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "BigramFreq.h"

BigramFreq::BigramFreq(){
    this->_bigram.at(0) = '_';
    this->_bigram.at(1) = '_';
    this->_frequency = 0;
}

const Bigram& BigramFreq::getBigram() const {
    return this->_bigram;
}

int BigramFreq::getFrequency() const{
    return this->_frequency;
}

void BigramFreq::setBigram(const Bigram &bigram){
    this->_bigram.at(0) = bigram.at(0);
    this->_bigram.at(1) = bigram.at(1);
}

void BigramFreq::setFrequency(int frequency){
    this->_frequency = frequency;
}

std::string BigramFreq::toString() const{
    std::string result = _bigram.toString() + " " + std::to_string(this->getFrequency());
    return result;
}
