Speak Easy
==========

Speak easy is an memory database I am building as an experiment and to learn C++.
It is currently in progress, so in lieu of docs here is an example of how it is used:

```c++
#include <iostream>
#include <string>
#include "interface.h"

std::string name = "name";
std::string age = "age";
std::string tbl_name = "people";

std::string cols[2] = {"name", "age"};


int main() {
  // the main interface for the library
  interface * ctrl = new interface();

  // adds a table named "people" with two columns "name" and "age"
  ctrl->new_table(tbl_name, cols, 2);

  // to add a row you use the new_row() method which returns a
  // row builder object
  row_builder * nr = ctrl->new_row(tbl_name);

  char my_name[5];
  strcpy(my_name, "James");

  // the row using the update_row method of the interface
  // it takes the row builder, the column name, and either an int or a char *
  ctrl->update_row(nr, name, my_name);
  ctrl->update_row(nr, age, 32);

  // inserting the row will delete the row builder
  ctrl->insert_row(nr);

  // print out the contents of our table
  ctrl->print_table(tbl_name);
  
  return 0;
}

```
