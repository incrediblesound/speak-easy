#ifndef VALUE_H_
#define VALUE_H_

#include <string>

class value {
private:
  char type;
  union {
    int number;
    char * text;
  };
public:
  value();
  value(int num);
  value(char * text);
  void print();
};

#endif
