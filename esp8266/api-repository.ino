
#include <ESP8266HTTPClient.h>
#include "Arduino.h"
#include "api-repository.h"

ApiRepository::ApiRepository(char *url, char *thumbPrint)
{
    _url = url;
    _thumbPrint = thumbPrint;
}

bool ApiRepository::send()
{
    HTTPClient http;

    bool ret = false;

    if (_thumbPrint)
    {
        http.begin(_url, _thumbPrint);
    }
    else
    {
        http.begin(_url);
    }

    int httpCode = http.GET();

    if (httpCode >= 200 && httpCode < 300) //Returned successful error code
    {
        ret = true;
    }

    http.end();

    return ret;
}
