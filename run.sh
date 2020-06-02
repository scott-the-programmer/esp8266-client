#!/bin/bash
set -e

serial_port=$1
endpoint=$2
ssid=$3
password=$4

board_identifier="esp8266:esp8266:nodemcuv2:xtal=80"

echo "Writing configuration"
echo "const char * ssid=\"$ssid\";" > ./esp8266/values.h
echo "const char * password=\"$password\";" >> ./esp8266/values.h
echo "char * endpoint=\"$endpoint\";" > ./esp8266/health-check-endpoint.h

echo "Compiling code"
arduino-cli compile --fqbn $board_identifier esp8266

echo "Deploying code to $board_identifier on $serial_port"
arduino-cli upload -p $serial_port --fqbn $board_identifier esp8266