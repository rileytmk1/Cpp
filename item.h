#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>
#include "room.h"


using namespace std;

class Item{
 public:
  Item(const char*); //item constructor
  const char* getDescription(); //name of item
 private:
  char name[50];
};

#endif
