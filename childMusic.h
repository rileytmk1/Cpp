//header guard
#ifndef MUSIC_H
#define MUSIC_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Music : public Media{ // Music: child class | Media: parent class
public:
  Music();
  //functions
  char* getArtist();
  char* getPublisher();
  int& getDuration();
private: //class's private variables
  int duration;
  char publisher[20];
  char artist[20];
};

#endif
