#ifndef RENDER_BOOTSTRAP_H_
#define RENDER_BOOTSTRAP_H_

#include "Arduino.h"
#include <String.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

enum buttonStyles {
  BTN_STYLE_BASIC,
  BTN_STYLE_PRIMARY,
  BTN_STYLE_SECONDARY,
  BTN_STYLE_SUCCESS,
  BTN_STYLE_INFO,
  BTN_STYLE_WARNING,
  BTN_STYLE_DANGER,
  BTN_STYLE_DARK,
  BTN_STYLE_LIGHT,
  BTN_STYLE_LINK,
  NUM_BUTTON_STYLES
};

enum buttonGroupStyles {
  BGS_H_BINARY,
  BGS_H_TRINARY,
  BGS_H_FOUR_STATE,
  BGS_H_ON_OFF,
  BGS_H_COLOR_SET,
  BGS_H_COLOR_SET_RED,
  BGS_H_COLOR_SET_BLUE,
  BGS_H_COLOR_SET_GREEN,
  BGS_V_BINARY,
  BGS_V_TRINARY,
  BGS_V_FOUR_STATE,
  BGS_V_ON_OFF,
  BGS_V_COLOR_SET,
  BGS_V_COLOR_SET_RED,
  BGS_V_COLOR_SET_BLUE,
  BGS_V_COLOR_SET_GREEN,
  NUM_BUTTON_GROUP_STYLES
};

class render_bootstrap {
  public:
    WiFiClient rbsClient;

    render_bootstrap();

    void renderCont(String s);
    void renderButton(String nName, buttonStyles nStyle);
    void renderButtonLink(String nUrl, String nName, buttonStyles nStyle);
    void renderButtonGroup(String nID, String nName, buttonGroupStyles nBGStyle);

    void renderAryCont(String ary[]);
    void renderH(int hLvl, String s);
    void renderHDiv(int hLvl, String s);
    void renderLink(String nUrl, String nName);
    void renderDataRowCell(String st);
    void renderH1(String s);
    void renderH2(String s);
    void renderH3(String s);
    void renderH4(String s);
    void renderH5(String s);
    void setClient(WiFiClient nClient);

  private:
   String genLinkButton(String nName, String nUrl, buttonStyles nStyle);
};

#endif