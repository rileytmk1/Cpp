#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"

class Player {
 public:
  Player();
  void addItem(Item*); //function to add to inventory
  void dropItem(Item*); //function to remove from inventory
  void printInventory(); //print inventory
  Item* getItem(const char*); //get Item* 
  bool hasItem(const char*); // check if item exits in inventory
 private:
  vector<Item*> inventory;
};

#endif
