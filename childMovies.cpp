#include <iostream>
#include <cstring>
#include "media.h"
#include "childMovies.h"

using namespace std;

Movie::Movie(){ //empty consturctor
 
}

int& Movie::getDuration(){ //int function with reference to access variable directly
  return duration;
}

int& Movie::getRating(){ //int function with reference to access variable directly
  return rating;
}

char* Movie::getDirector(){ //return director (char array)
  return director;
}
