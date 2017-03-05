#ifndef INTERFACE_H_
#define INTERFACE_H_

#include "table.h"

class row_builder {
  // add bit array to test for "fullness"
public:
  table * tbl;
  row * rw;
  row_builder(table *);
};

class interface {
private:
  int size;
  std::string table_names[20];
  table * tables;
public:
  interface();
  row_builder * new_row(std::string);
  table * get_table(std::string);
  void new_table(std::string, std::string[], int);
  void update_row(row_builder *, std::string, int);
  void update_row(row_builder *, std::string, char *);
  void insert_row(row_builder *);
  void print_table(std::string);
};

#endif
