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
  char* getDescription(); //description of room
  Room* getExit(const char* direction); //next room given direction
  Room* getRoom(const char*, map<const char*, Room*>&); //access room from map
  char* getExitString(); //return string with exits and items
  void setExit(const char*, Room*); //set room exits
  void setItem(Item*); //set items in room
  Item* getItem(const char*); //get Item*
  void removeItem(Item*); //remove item from room
  //void addItem(const char*);


 private:
  char name[50];
  char description[500];
  vector<Item*> items;
  map<const char*, Room*> exits;
};

#endif
