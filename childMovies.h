#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <cstring>
#include "parent.h"

using namespace std;

class Movies : public Media {
public:
  Movies();
  int getRating();
  char* getDirector();
  int getDuration();
private:
  int rating;
  char director[20];
  int duration;
}

#endif
