#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "room.h"
#include "item.h"

using namespace std;

Room::Room(){

}

char* Room::getDescription(){
  return description;
}

void Room::setExit(char* direction, Room* neighbor){
  exits[direction] = neighbor;
}

void setItem(Item* newItem){
  items.push_back(newItem);
}
