#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

#include "item.h"

using namespace std;

class Room{
 public:
  Room();
  char* getDescription();
  Room* getExit(const char* direction);
  char* getExitString();
  void setExit(const char*, Room*);
  void setItem(Item*);
  Item* getItem(const char*);
  void removeItem(Item*);
  void addItem(const char*);


 private:
  char name[50];
  char description[500];
  vector<Item*> items;
  map<const char*, Room*> exits;
};

#endif
