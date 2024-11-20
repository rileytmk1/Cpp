#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

class Room{
 public:
  Room();
  char* getDescription();
  char* getExits();
  Item* getItem(char*);
  void addItem(char*);


 private:
  char name[50];
  char description[500];
  vector<Item*> items;
  map<char*, Room*> exits;
};

#endif
