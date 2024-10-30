#include <iostream>
#include <cstring>
#include "childGames.h"
#include "media.h"

using namespace std;

videoGames::videoGames() {

}

char* videoGames::getPublisher(){
  return publisher;
}

int videoGames::getRating(){
  return rating;
}
