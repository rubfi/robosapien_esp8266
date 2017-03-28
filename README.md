# Controlling the Robosapien using the ESP8266

This is a collection of tools and sketches for controlling the Robosapien V1 using an ESP8266 and an infrared led.

The sketches require the infrared remote library for ESP8266 modified for supporting the Robosapien commands (This library can be found here: https://github.com/rubfi/IRremoteESP8266 . Please, follow the installation instructions in order to add the library to the Arduino IDE)

* **robosapien_serial_cmd:** Shows how to use the serial port in order to send commands to the robot

* **robosapien_wifi_cmd:** It is similar to *robosapien_serial_cmd*, but this time the commands are received through a WiFi connection.
