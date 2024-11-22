#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include "room.h"
#include "item.h"
#include "player.h"

class Parser{
 public:
  bool processCommand(char*, Room*& , Player&, map<const char*, Room*>&);
 private:
  char* command[10];
};

#endif
