#include <iostream>
#include <cstring>
#include "parent.h"


using namespace std;

class videoGames : public Media {
public:
  child();
  char* getPublisher();
  int getRating();
private:
  int rating;
  char publisher[10];
  
}

  
