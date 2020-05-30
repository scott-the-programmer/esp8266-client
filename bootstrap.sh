#!/bin/bash

# A simple script to bootstrap dependencies

echo "These are the boards connected"
arduino-cli board list

echo "Updating arduino index"
arduino-cli core update-index