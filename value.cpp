#include "value.h"
#include <iostream>

value::value(){
  this->type = 'n';
}

value::value(int num){
  this->type = 'i';
  this->number = num;
}

value::value(char * text){
  this->type = 't';
  this->text = text;
}

void value::print(){
  if(this->type == 'i'){
    std::cout << this->number;
  } else if(this->type == 't'){
    std::cout << '"' << this->text << '"';
  } else {
    std::cout << "NULL";
  }
}
