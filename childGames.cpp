#include <iostream>
#include <cstring>
#include "childGames.h"
#include "media.h"

using namespace std;

videoGame::videoGame() {

}

char* videoGame::getPublisher(){
  return publisher;
}

int& videoGame::getRating(){
  return rating;
}
