#include <iostream>
#include <cstring>
#include "room.h"
#include "item.h"

using namespace std;

Item::Item(char* setItem){
  name = setItem;
}

char* Item::getDescription(){
  return name;
}
