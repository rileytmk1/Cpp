#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public Media{
public:
  Music();
  char* getArtist();
  char* getPublisher();
  int getDuration();
private:
  int duration;
  char publisher[20];
  char artist[20];
};

#endif
