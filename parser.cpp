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
    cout << "vending: " << nextRoom->getRoom("vending", roomsMap) << endl;
    cout << "next room: " << nextRoom << endl;
    if (nextRoom != nullptr && nextRoom != nextRoom->getRoom("vending", roomsMap)){
      currentRoom = nextRoom;
      cout << currentRoom->getDescription() << endl;
      cout << currentRoom->getExitString() << endl;
    }
    else if (nextRoom == nextRoom->getRoom("vending", roomsMap) && player.hasItem("quarter") == false){
      currentRoom = nextRoom;
      cout << currentRoom->getDescription() << endl;
      cout << "The vending machine is selling keys? It accepts a coin slot....." << endl;
      cout << "Exits: east west" << endl;
    }
    else if (nextRoom == nextRoom->getRoom("vending", roomsMap) && player.hasItem("quarter") == true){
      currentRoom = nextRoom;
      cout << currentRoom->getDescription() << endl;
      cout << "You have a quarter! You use it to access the key." << endl;
      cout << "Exits: east west" << endl;
      cout << "Items: key" << endl;
    }
    else if (nextRoom == nextRoom->getRoom("vault", roomsMap) && player.hasItem("key") == false){
      currentRoom = nextRoom;
      cout << "You've made it to the vault room." << endl;
      cout << "You try to open the vault but it is locked!" << endl;
      cout << "Exits: south" << endl;
    }
    else if (nextRoom == nextRoom->getRoom("vault", roomsMap) && player.hasItem("key") == true){
      currentRoom = nextRoom;
      cout << "You open the vault with your key and the alarms are blaring! Get the jewel and get back to the lobby as fast as possible!" << endl;
      cout << "Exits: south" << endl;
      cout << "Items: jewel" << endl;
    }
    else if(nextRoom == nextRoom->getRoom("lobby", roomsMap) && player.hasItem("jewel") == true){
      cout << "Well done fellow agent." << endl;
      cout << "We will meet again soon." << endl;
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
