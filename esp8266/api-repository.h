
#ifndef ApiRepository_h
#define ApiRepository_h

#include "Arduino.h"

class ApiRepository
{
public:
  ApiRepository(char* url);
  void send();

private:
  char* _url;
};

#endif