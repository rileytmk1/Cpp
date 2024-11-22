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

Item* Room::getItem(const char* itemName){
  for (int i = 0; i < items.size(); i++){
    if(strcmp(items[i]->getDescription(), itemName) == 0){
      return items[i];
    }
  }
  return nullptr;
}

void Room::removeItem(Item* item){
  for (auto it = items.begin(); it != items.end(); ++it){
    if (*it == item){
      items.erase(it);
      break;
    }
  }
}

Room* Room::getExit(const char* direction){
  for (auto& exit : exits){
    if (strcmp(exit.first, direction) == 0){
      return exit.second;
    }
  }
  return nullptr;
}

char* Room::getExitString(){
  static char exitString[500];
  strcpy(exitString, "Exits:");
  for (auto& exit : exits){
    strcat(exitString, " ");
    strcat(exitString, exit.first);
  }
  strcat(exitString, "\nItems in this room:");
  if (items.empty()){
    strcat(exitString, "No Items.");
  }
  else{
    for (auto& item: items){
      strcat(exitString, " ");
      strcat(exitString, item->getDescription());
    }
  }
  return exitString;
}

void Room::setExit(const char* direction, Room* neighbor){
  exits[direction] = neighbor;
}

void Room::setItem(Item* newItem){
  items.push_back(newItem);
}
