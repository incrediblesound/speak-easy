#include "table.h"
#include "value.h"
#include "constants.h"
#include <stdexcept>
#include <string>
#include <iostream>

table::table(){
  this->rows = new row[table_size];
  this->num_rows = 0;
}

void table::insert(row * r){
  if(this->num_rows >= table_size){
    throw std::length_error("Table has reached maximum size.");
  } else {
    this->rows[this->num_rows] = *r;
    this->num_rows++;
  }
}

void table::set_cols(std::string cols[], int num_cols){
  this->num_cols = num_cols;
  for(int i = 0; i < num_cols; i++){
    this->cols[i] = cols[i];

  }
}

std::string table::col_at(int i){
  return this->cols[i];
}

int table::get_col_idx(std::string col){
  for(int i = 0; i < this->num_cols; i++){
    if(!this->cols[i].compare(col)){
      return i;
    }
  }
  throw std::invalid_argument("Invalid column name in get_col_idx");
}

void table::print(){
  for(int i = 0; i < this->num_rows; i++){
    std::cout << i << " - ";
    for(int k = 0; k < this->num_cols; k++){
      std::cout << this->cols[k] << ": ";
      this->rows[i].value_at_idx(k)->print();
      if(k == this->num_cols-1){
        std::cout << '\n';
      } else {
        std::cout << ", ";
      }
    }
  }
}
