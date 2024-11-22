#include <iostream>
#include <vector>
#include <cstring>
#include "room.h"
#include "item.h"
#include "parser.h"
#include "player.h"

using namespace std;

bool Parser::processCommand(char* command, Room*& currentRoom, Player& player, map<const char*, Room*>& roomsMap){  
  if (strcmp(command, "go") == 0){
    char direction[10];
    cout << "What direction? ";
    cin.get(direction, 10);
    cin.get();
    Room* nextRoom = currentRoom->getExit(direction);
    cout << "vending: " << roomsMap["vending"] << endl;
    cout << "next room: " << nextRoom << endl;
    if (nextRoom != nullptr && (nextRoom != roomsMap["vending"])){
      currentRoom = nextRoom;
      cout << currentRoom->getDescription() << endl;
      cout << currentRoom->getExitString() << endl;
    }
    else{
      cout << "You can't go there!" << endl;
    }
  }
  else if (strcmp(command, "get") == 0){
    char item[50];
    cout << "What item do you want to get? ";
    cin.get(item, 50);
    cin.get();
    Item* itemGot = currentRoom->getItem(item);
    if (itemGot != nullptr){
      player.addItem(itemGot);
      currentRoom->removeItem(itemGot);
      cout << "You picked up: " << item << endl;
    }
    else{
      cout << "Item not found." << endl;
    }
  }
  else if (strcmp(command, "drop") == 0) {
    char itemDrop[50];
    cout << "What item do you want to drop? ";
    cin.get(itemDrop, 50);
    cin.get();
    Item* itemToDrop = player.getItem(itemDrop);
    if (itemToDrop != nullptr){
      player.dropItem(itemToDrop);
      currentRoom->setItem(itemToDrop);
      cout << "You dropped: " << itemToDrop->getDescription() << endl;
    }
    else{
      cout << "You don't have that item!" << endl;
    }
  }
  else if (strcmp(command, "inventory") == 0){
    player.printInventory();
  }
  else if (strcmp(command, "quit") == 0){
    return false;
  }
  return true;
}
