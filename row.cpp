#include "row.h"
#include "value.h"
#include "constants.h"
#include <string>
#include <iostream>

row::row(){
  this->values = new value[table_size];
}

void row::insert(int idx, value * val){
  this->values[idx] = *val;
}

value * row::value_at_idx(int idx){
  return &this->values[idx];
}
