#include <iostream>
#include <string>
#include "interface.h"

std::string name = "name";
std::string age = "age";
std::string tbl_name = "people";

std::string cols[2] = {"name", "age"};


int main() {
  interface * ctrl = new interface();

  ctrl->new_table(tbl_name, cols, 2);
  row_builder * nr = ctrl->new_row(tbl_name);

  char my_name[5];
  strcpy(my_name, "James");

  ctrl->update_row(nr, name, my_name);
  ctrl->update_row(nr, age, 32);
  ctrl->insert_row(nr);
  ctrl->print_table(tbl_name);
  return 0;
}
