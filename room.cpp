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

Item* Room::getItem(const char* itemName){ //get Item* requested
  for (int i = 0; i < items.size(); i++){
    if(strcmp(items[i]->getDescription(), itemName) == 0){
      return items[i];
    }
  }
  return nullptr;
}

void Room::removeItem(Item* item){ //remove item from item vector
  for (auto it = items.begin(); it != items.end(); ++it){
    if (*it == item){
      items.erase(it);
      break;
    }
  }
}

Room* Room::getExit(const char* direction){ //gets the room for the direction the player goes
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
  for (auto& exit : exits){ //get the exits from the map
    strcat(exitString, " "); 
    strcat(exitString, exit.first); //add them to  the return string
  }
  strcat(exitString, "\nItems in this room: ");
  if (items.empty()){
    strcat(exitString, "No Items.");
  }
  else{
    for (auto& item: items){ //go through items vector to get the items from the room
      strcat(exitString, " ");
      strcat(exitString, item->getDescription()); //add them to return string
    }
  }
  return exitString;
}

Room* Room::getRoom(const char* roomName, map<const char*, Room*>& roomsMap){ //gives Room* from the map (for the special rooms)
  for (auto it = roomsMap.begin(); it != roomsMap.end(); ++it) {
    if (strcmp(roomName, it->first) == 0){
      return it->second;
    }
  }
  return nullptr; //if doesn't exist
}

void Room::setExit(const char* direction, Room* neighbor){
  exits[direction] = neighbor;
}

void Room::setItem(Item* newItem){
  items.push_back(newItem);
}
