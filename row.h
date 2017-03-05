#ifndef ROW_H_
#define ROW_H_

#include "value.h"
#include <string>

class row {
private:
  value * values;
public:
  row();
  void insert(int col, value *);
  value * value_at_idx(int);
};

#endif
