#ifndef RENDER_BOOTSTRAP_H_
#define RENDER_BOOTSTRAP_H_

#include "Arduino.h"
#include <String.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

class render_bootstrap {
    public:
        WiFiClient rbsClient;

        render_bootstrap();

        void renderCont(String s);
        void renderAryCont(String ary[]);
        void renderH(int hLvl, String s);
        void renderLink(String nUrl, String nName);
        void renderDataRowCell(String st);
        void renderH1(String s);
        void renderH2(String s);
        void renderH3(String s);
        void renderH4(String s);
        void renderH5(String s);
        void setClient(WiFiClient nClient);
};

#endif