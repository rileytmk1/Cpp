#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include "room.h"


using namespace std;

class Item{
 public:
  Item(const char*);
  const char* getDescription();
 private:
  char name[50];
};

#endif
