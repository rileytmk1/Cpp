#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <cstring>
#include "parent.h"

using namespace std;

class Music : public Media{
public:
  child();
  char* getArtist;
  char* getPublisher;
  int getDuration;
private:
  int duration;
  char publisher[20];
  char artist[20];
}

#endif
