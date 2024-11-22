#include <iostream>
#include <cstring>
#include "room.h"
#include "parser.h"
#include "player.h"

using namespace std;

int main()
{
  cout << "A precious jewel has been taken from the local museum. It is rumored that the jewel is stashed in the vault of the hotel. It is your job to take the jewel from the vault and escape as fast as possible!" << endl;
  cout << "Use the go command with a direction to go to different rooms and use the get command to pick up items." << endl;
  map <const char*, Room*> roomsMap;
  Room* lobby = new Room();
  strcpy(lobby->getDescription(), "You are in the hotel lobby.");
  roomsMap.insert(pair<const char*, Room*>("lobby", lobby));
  Room* showers = new Room();
  strcpy(showers->getDescription(), "You are in the hotel shower room.");
  Room* sauna = new Room();
  strcpy(sauna->getDescription(), "You are in the hotel sauna.");
  Room* pool = new Room();
  strcpy(pool->getDescription(), "You are in the hotel pool.");
  Room* gym = new Room();
  strcpy(gym->getDescription(), "You are in the hotel gym.");
  Room* breakfast = new Room();
  strcpy(breakfast->getDescription(), "You are in the hotel breakfast room");
  Room* resturant = new Room();
  strcpy(resturant->getDescription(), "You are in the hotel resturant.");
  Room* wait = new Room();
  strcpy(wait->getDescription(), "You are in the resturant waiting room.");
  Room* vending = new Room();
  strcpy(vending->getDescription(), "You are in the hotel's vending machine room.");
  roomsMap.insert(pair<const char*, Room*> ("vending", vending));
  //roomsMap["vending"] = vending;
  Room* movie = new Room();
  strcpy(movie->getDescription(), "You are in hotel movie theater.");
  Room* washing = new Room();
  strcpy(washing->getDescription(), "You are in the hotel washing machine room.");
  Room* closet = new Room();
  strcpy(closet->getDescription(), "You are in the janitor's closet.");
  Room* arcade = new Room();
  strcpy(arcade->getDescription(), "You are in the arcade.");
  Room* ice = new Room();
  strcpy(ice->getDescription(), "You are in the ice room.");
  Room* vault = new Room();
  strcpy(vault->getDescription(), "You have found the vault! Get the jewel and get back to the lobby as fast as you can!");

  cout << roomsMap["vending"];

  lobby->setExit("north", breakfast);
  lobby->setExit("west", showers);
  lobby->setExit("east", washing);

  showers->setExit("north", sauna);
  showers->setExit("west", pool);

  pool->setExit("east", showers);

  sauna->setExit("west", gym);
  sauna->setExit("south", showers);

  gym->setExit("east", sauna);

  breakfast->setExit("north", resturant);
  breakfast->setExit("south", lobby);
  breakfast->setExit("east", arcade);

  washing->setExit("west", lobby);
  washing->setExit("east", closet);

  closet->setExit("west", washing);
  closet->setExit("north", arcade);

  arcade->setExit("west", breakfast);
  arcade->setExit("north", ice);

  resturant->setExit("south", breakfast);
  resturant->setExit("west", wait);
  resturant->setExit("east", ice);

  wait->setExit("west", vending);
  wait->setExit("east", resturant);

  vending->setExit("north", movie);
  vending->setExit("east", wait);

  movie->setExit("south", vending);

  ice->setExit("west", resturant);
  ice->setExit("south", arcade);
  ice->setExit("north", vault);

  vault->setExit("south", ice);

  gym->setItem(new Item("dumbbell"));
  breakfast->setItem(new Item("fork"));
  closet->setItem(new Item("quarter"));
  vending->setItem(new Item("key"));
  vault->setItem(new Item("jewel"));

  Parser parser;
  Player player;
  Room* currentRoom = lobby;
  bool play = true;
  char input[10];
  cout << currentRoom->getDescription() << endl;
  cout << currentRoom->getExitString() << endl;
  while(play){
    cin.get(input, 10);
    cin.get();
    play = parser.processCommand(input, currentRoom, player, roomsMap);
  }
  
}
