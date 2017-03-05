#include <iostream>
#include <string>
#include <stdexcept>
#include "table.h"
#include "row.h"
#include "interface.h"

interface::interface(){
  this->size = 0;
  this->tables = new table[10];
}

row_builder::row_builder(table * t){
  this->tbl = t;
  this->rw = new row();
}

void interface::new_table(std::string name, std::string cols[], int size){
  table * t = new table();
  t->set_cols(cols, size);
  this->tables[this->size] = *t;
  this->table_names[this->size] = name;
  this->size++;
}

table * interface::get_table(std::string name){
  for(int i = 0; i < this->size; i++){
    if(!name.compare(this->table_names[i])){
      return &this->tables[i];
    }
  }
  throw new std::invalid_argument("No table with that name.");
}

row_builder * interface::new_row(std::string table_name){
  table * t = this->get_table(table_name);
  row_builder * rb = new row_builder(t);
  return rb;
}

void interface::update_row(row_builder * rb, std::string col, int num){
  int idx = rb->tbl->get_col_idx(col);
  value * val = new value(num);
  rb->rw->insert(idx, val);
}

void interface::update_row(row_builder * rb, std::string col, char * text){
  int idx = rb->tbl->get_col_idx(col);
  value * val = new value(text);
  rb->rw->insert(idx, val);
}

void interface::insert_row(row_builder * rb){
  rb->tbl->insert(rb->rw);
  delete(rb);
}

void interface::print_table(std::string table_name){
  table * t = this->get_table(table_name);
  t->print();
}
