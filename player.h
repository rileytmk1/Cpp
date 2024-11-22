#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"

class Player {
 public:
  Player();
  void addItem(Item*);
  void dropItem(Item*);
  void printInventory();
  Item* getItem(const char*);
  bool hasItem(const char*);
 private:
  vector<Item*> inventory;
};

#endif
