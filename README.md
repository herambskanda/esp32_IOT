# esp32_IOT

ESP32 model: DOIT DEVkit V1 (ram: 327680 bytes | flash mem: 1310720 bytes | UART: silabs cp2102)

Humidity sensor: DHT11

Ultrasonic sensor: HC-SR04

Load cell: CLZ601-20kg-0.02prec

# REQUIREMENTS:

Before flashing your esp32 change wifi login and password macros on ./src/wifi_login.h

UART-USB drivers for esp32 devkit v1 its cp210x module link to the drivers "https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads".

PlatformIO extension on vscode.

ADAFRUIT_SENSOR library just download it from platformIO libraries or else you need to include it to the linker on the iso image before flashing esp32 which is a pain.

# WHAT IT DOES?

simple local network standalone host.

displays temperature, humidity from DHT11 sensor, distance from ultrasonic sensor, and weight from load cell.
