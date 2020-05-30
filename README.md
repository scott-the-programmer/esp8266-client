# Humidity Sensor

A simple program that measures the humidity in the air

Soley for the ESP8266 board

## Prerequisites

* [Arduino CLI](https://arduino.github.io/arduino-cli/installation/)
* CP210x USB to UART Bridge VCP Driver

## Getting Started

Run the following script to list out your connected boards and update the ardunio-cli repository with the esp8266 index

```bash
./bootstrap.sh
```

Example output

```bash
These are the boards connected
Port                            Type              Board Name FQBN Core
/dev/cu.usbserial-143120        Serial Port (USB) Unknown
```

Take note of the port that you want to use, in this case, `/dev/cu.usbserial-143120`

## Build & Run the code

Run the following script to compile and run the code

```bash
./run.sh "/dev/cu.usbserial-143120"
```

Example output

```bash
Compiling code
Executable segment sizes:
IROM   : 228492          - code in flash         (default or ICACHE_FLASH_ATTR) 
IRAM   : 26784   / 32768 - code in IRAM          (ICACHE_RAM_ATTR, ISRs...) 
DATA   : 1248  )         - initialized variables (global, static) in RAM/HEAP 
RODATA : 688   ) / 81920 - constants             (global, static) in RAM/HEAP 
BSS    : 24880 )         - zeroed variables      (global, static) in RAM/HEAP 
Sketch uses 257212 bytes (24%) of program storage space. Maximum is 1044464 bytes.
Global variables use 26816 bytes (32%) of dynamic memory, leaving 55104 bytes for local variables. Maximum is 81920 bytes.
Deploying code to esp8266:esp8266:nodemcuv2:xtal=80  on /dev/cu.usbserial-143120
No new serial port detected.
esptool.py v2.8
Serial port /dev/cu.usbserial-143120
Connecting....
Chip is ESP8266EX
Features: WiFi
Crystal is 26MHz
MAC: 50:02:91:7a:1d:f2
Uploading stub...
Running stub...
Stub running...
Configuring flash size...
Auto-detected Flash size: 4MB
Compressed 261360 bytes to 192957...
Wrote 261360 bytes (192957 compressed) at 0x00000000 in 18.7 seconds (effective 111.8 kbit/s)...
Hash of data verified.

Leaving...
Hard resetting via RTS pin...
```
