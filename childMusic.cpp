
#include <iostream>
#include <cstring>

#include "childMusic.h"
#include "media.h"

using namespace std;

Music::Music(){

}

char* Music::getPublisher(){
  return publisher;
}

char* Music::getArtist(){
  return artist;
}

int Music::getDuration(){
  return duration;
}

