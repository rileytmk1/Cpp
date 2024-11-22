#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"

using namespace std;

Item::Item(const char* setItem){
  strcpy(name, setItem);
}

const char* Item::getDescription(){
  return name;
}
