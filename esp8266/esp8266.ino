#include <ESP8266WiFi.h>
#include "api-repository.h"

#include "health-check-endpoint.h"
#include "values.h"

ApiRepository api = ApiRepository(endpoint);

void setup()
{
    setupLed();
    setupSerial();
    setupWifi();
}

void loop()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        return;
    }

    bool healthy = api.send();

    if (healthy)
    {
        Serial.println("healthy");
        digitalWrite(LED_BUILTIN, LOW);
        delay(5000);
    }
    else
    {
        Serial.println("unhealthy");
        digitalWrite(LED_BUILTIN, HIGH);
        delay(5000);
    }
}

void setupLed()
{
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
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting...");
    }
}
