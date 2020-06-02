
#include <ESP8266HTTPClient.h>
#include "Arduino.h"
#include "api-repository.h"

ApiRepository::ApiRepository(char *url)
{
    _url = url;
}

bool ApiRepository::send()
{
    HTTPClient http;

    bool ret = false;

    http.begin(_url);

    int httpCode = http.GET();

    if (httpCode >= 200 && httpCode < 300) //Returned successful error code
    {
        ret = true;
    }

    http.end();

    return ret;
}
