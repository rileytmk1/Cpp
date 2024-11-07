#include <iostream>
#include <cstring>
#include "media.h"

using namespace std;

Media::Media(){ //empty constructor
  
}

int& Media::getYear(){ //int function with reference to access variable directly
  return year;
}

char* Media::getTitle(){ //return title (char array)
  return title;
}

