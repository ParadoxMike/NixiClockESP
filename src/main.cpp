#include <Arduino.h>

#include <FS.h>
#include <LittleFS.h>

#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

// SSID & Password
const char *ssid = "Nixi Clock - ESP"; //SSID of the ap
const char *password = NULL;            //password of the ap

// IP configuration
IPAddress local_ip(192, 168, 1, 1);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

// Create Webserver Object
AsyncWebServer server(80);

void setup() {
    // Create SoftAP
    WiFi.softAPConfig(local_ip, gateway, subnet);
    WiFi.softAP(ssid, password);

    LittleFS.begin();

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/index.html", "text/html");
    });

    server.on("/scripts.js", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/scripts.js", "text/javascript");
    });

    server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(LittleFS, "/style.css", "text/css");
    });

    server.begin();
}

void loop() {
}