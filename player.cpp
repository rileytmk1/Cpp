#include <iostream>
#include <cstring>
#include <vector>
#include "room.h"
#include "player.h"
#include "item.h"

using namespace std;

Player::Player() {

}

void Player::addItem(Item* newItem){ //add to item to vector hollding inventory
  inventory.push_back(newItem);
}

void Player::dropItem(Item* item){
  for (auto it = inventory.begin(); it != inventory.end(); ++it) { //remove wanted item from inventory vector
    if (*it == item) {
      inventory.erase(it);
      break;
    }
    
  }
}

Item* Player::getItem(const char* itemName){ //get Item* from inventory
  for (auto& item : inventory) {
    if (strcmp(item->getDescription(), itemName) == 0) {
      return item;
    }
  }
  return nullptr;
}

void Player::printInventory(){ 
  cout << "Inventory:";
  for(auto& item: inventory){
    cout << " " << item->getDescription() << endl;
  }
}

bool Player::hasItem(const char* itemName){ //same as getItem bur returns a boolean if it exists or not
  for (auto item : inventory){
    if (strcmp(item->getDescription(), itemName) == 0){
      return true;
    }
  }
  return false;
}
