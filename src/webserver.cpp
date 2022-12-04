#include <Arduino.h>
// #include <FS.h>
#include <LittleFS.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

class MyWebServer : public AsyncWebServer {
    private:

    public:
        MyWebServer(int port) : AsyncWebServer(port) {}

        void setup() {
            LittleFS.begin();

            this->on("/", HTTP_GET, [](AsyncWebServerRequest *request){
                request->send(LittleFS, "/index.html", "text/html");
            });

            this->on("/scripts.js", HTTP_GET, [](AsyncWebServerRequest *request){
                request->send(LittleFS, "/scripts.js", "text/javascript");
            });

            this->on("/jquery.min.js", HTTP_GET, [](AsyncWebServerRequest *request){
                request->send(LittleFS, "/jquery.min.js", "text/javascript");
            });

            this->on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){
                request->send(LittleFS, "/style.css", "text/css");
            });

            this->on("/fonts/fira-code-regular.ttf", HTTP_GET, [](AsyncWebServerRequest *request){
                request->send(LittleFS, "/fonts/fira-code-regular.ttf", "");
            });

            this->on("/fonts/fira-code-regular.woff", HTTP_GET, [](AsyncWebServerRequest *request){
                request->send(LittleFS, "/fonts/fira-code-regular.woff", "");
            });

            this->on("/fonts/fira-code-regular.woff2", HTTP_GET, [](AsyncWebServerRequest *request){
                request->send(LittleFS, "/fonts/fira-code-regular.woff2", "");
            });

            this->begin();
        }
};