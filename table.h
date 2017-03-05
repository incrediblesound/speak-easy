#ifndef TABLE_H_
#define TABLE_H_

#include "value.h"
#include "row.h"
#include <string>

class table {
private:
  int num_cols;
  int num_rows;
  row * rows;
  std::string cols[20];
public:
  table();
  void insert(row *);
  void print();
  void set_cols(std::string cols[], int);
  int get_col_idx(std::string);
  std::string col_at(int);
};

#endif
