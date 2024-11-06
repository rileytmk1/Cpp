#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class videoGame : public Media {
public:
  videoGame();
  char* getPublisher();
  int& getRating();
private:
  int rating;
  char publisher[10];
  
};

#endif
