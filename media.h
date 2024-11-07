//header guard
#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>

using namespace std;

class Media {
 public:
  Media();
  virtual ~Media(){} //virtual destructor
  virtual int& getYear(); //virtual functions in the parent class so all child classes can access
  virtual char* getTitle();
 private:
  int year;
  char title[20];
  
};
#endif
