
#ifndef ApiRepository_h
#define ApiRepository_h

#include "Arduino.h"

class ApiRepository
{
public:
  ApiRepository(char *url, char *thumbPrint);
  bool send();

private:
  char *_url;
  char *_thumbPrint;
};

#endif