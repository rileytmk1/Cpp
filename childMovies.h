// header guard
#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie : public Media { //Movie: child class | Media: parent class
public:
  Movie();
  //functions
  int& getRating();
  char* getDirector();
  int& getDuration();
private: //class's private variables
  int rating;
  char director[20];
  int duration;
};

#endif
