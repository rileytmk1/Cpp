#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class Movie : public Media {
public:
  Movie();
  int& getRating();
  char* getDirector();
  int& getDuration();
private:
  int rating;
  char director[20];
  int duration;
};

#endif
