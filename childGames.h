// header guard
#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

class videoGame : public Media { // videogame: child class | Media: parent class
public:
  videoGame();
  //functions
  char* getPublisher();
  int& getRating();
private: //class's private variables
  int rating;
  char publisher[20];
  
};

#endif
