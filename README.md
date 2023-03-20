# esp32_IOT

REQUIREMENTS:

Before flashing your esp32 change wifi login and password macros on ./src/wifi_login.h

UART-USB drivers for esp32 devkit v1 its cp210x module link to the drivers "https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads".

PlatformIO extension on vscode.

ADAFRUIT_SENSOR library just download it from platformIO libraries or else you need to include it to the linker on the iso image before flashing esp32 which is a pain.

WHAT IT DOES?

simple local network standalone host.

displays temperature, humidity from DHT11 sensor, distance from ultrasonic sensore, and weight from load cell.
