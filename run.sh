#!/bin/bash

serial_port=$1
board_identifier="esp8266:esp8266:nodemcuv2:xtal=80 "

echo "Compiling code"
arduino-cli compile --fqbn $board_identifier sensor

echo "Deploying code to $board_identifier on $serial_port"
arduino-cli upload -p $serial_port --fqbn $board_identifier sensor