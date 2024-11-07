
#include <iostream>
#include <cstring>

#include "childMusic.h"
#include "media.h"

using namespace std;

Music::Music(){ //empty constructior

}

char* Music::getPublisher(){ //return publisher (char array)
  return publisher;
}

char* Music::getArtist(){ //return artist (char array)
  return artist;
}

int& Music::getDuration(){ //int function with reference to access variable directly
  return duration;
}

