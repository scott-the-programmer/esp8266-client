
#include <ESP8266HTTPClient.h>
#include "Arduino.h"
#include "api-repository.h"

ApiRepository::ApiRepository(char *url)
{
    _url = url;
}

void ApiRepository::send()
{
    HTTPClient http;

    http.begin(_url);
    int httpCode = http.GET();

    if (httpCode > 0)
    {
        String payload = http.getString();
        Serial.println(payload);
    }
    http.end();
}
