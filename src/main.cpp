#include <Arduino.h>

#include <ESP8266WiFi.h>

#include <webserver.cpp>

// SSID & Password
const char *ssid = "Nixi Clock - ESP"; //SSID of the ap
const char *password = NULL;            //password of the ap

// IP configuration
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

// Create Webserver Object
MyWebServer server = MyWebServer(80);

void setup() {
    // Create SoftAP
    WiFi.softAPConfig(local_ip, gateway, subnet);
    WiFi.softAP(ssid, password);

    server.setup();
}

void loop() {
}