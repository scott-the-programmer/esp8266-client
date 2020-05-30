#include <ESP8266WiFi.h>
#include "api-repository.h"

ApiRepository api = ApiRepository("http://jsonplaceholder.typicode.com/users/1");

void setup()
{
    setupLed();
    setupSerial();
    setupWifi();
}

void loop()
{
    if (WiFi.status() == WL_CONNECTED)
    {
        api.send();
        digitalWrite(LED_BUILTIN, HIGH);
        delay(5000);
    }

    digitalWrite(LED_BUILTIN, LOW);
    delay(5000);
}

void setupLed()
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void setupSerial()
{

    Serial.begin(9600);
    while (!Serial)
    {
        ; // wait for serial port to connect. Needed for native USB port only
    }
}

void setupWifi()
{
#include "values.h"
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting...");
    }
}
