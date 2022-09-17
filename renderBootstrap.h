#ifndef RENDER_BOOTSTRAP_H_
#define RENDER_BOOTSTRAP_H_

#include "Arduino.h"
#include <String.h>
#include <WiFiClient.h>

class render_bootstrap {
    public:
        WiFiClient rbsClient;

        render_bootstrap();
        render_bootstrap(WiFiClient rbsClient);

        void renderH(int hLvl, String s);
        String renderLink(String nUrl, String nName)
        String renderDataRowCell(String st)
        void renderH1(String s)
        void renderH2(String s)
        void renderH3(String s)
        void renderH4(String s)
        void renderH5(String s)
};

#endif