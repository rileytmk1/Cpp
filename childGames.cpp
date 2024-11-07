#include <iostream>
#include <cstring>
#include "childGames.h"
#include "media.h"

using namespace std;

videoGame::videoGame() {

}

char* videoGame::getPublisher(){ //return char array
  return publisher;
}

int& videoGame::getRating(){ //int function using reference to access the variable directly
  return rating;
}
