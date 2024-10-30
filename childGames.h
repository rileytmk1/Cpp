#ifndef VIDEOGAMES_H
#define VIDEOGAME_H

#include <iostream>
#include <cstring>
#include "media.h"


using namespace std;

class videoGames : public Media {
public:
  videoGames();
  char* getPublisher();
  int getRating();
private:
  int rating;
  char publisher[10];
  
};

#endif
