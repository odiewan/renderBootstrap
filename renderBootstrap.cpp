#include "renderBootstrap.h"
#include <ESP8266WiFi.h>

String buttonStyleNames[] = {
    "btn",
    "btn btn-primary",
    "btn btn-secondary",
    "btn btn-success",
    "btn btn-info",
    "btn btn-warning",
    "btn btn-danger",
    "btn btn-dark",
    "btn btn-light",
    "btn btn-link"
};

//=================================================================================================
render_bootstrap::render_bootstrap()
{
    // rbsClient = NULL;
}

//=================================================================================================
String render_bootstrap::genLinkButton(String nName, String nUrl, buttonStyles nStyle) {
  return "<a href='" + nUrl + "' class='" + buttonStyleNames[nStyle] + "' role='button'>" + nName + "</a>";
}

  //=================================================================================================
  void render_bootstrap::renderButton(String nName, buttonStyles nStyle) {
    String _html = "<button type='button' class='" + buttonStyleNames[nStyle] + "'>" + nName + "</button>";
    rbsClient.print(_html);
}

//=================================================================================================
void render_bootstrap::renderButtonLink(String nUrl, String nName, buttonStyles nStyle) {
    String _html = "<a href='" + nUrl + "' class='" + buttonStyleNames[nStyle] + "'>" + nName + "</a>";
    rbsClient.print(_html);
}

//=================================================================================================
void render_bootstrap:: renderButtonGroup(String nID, String nName, buttonGroupStyles nBGStyle) {
  String _html;
  String _arg;
  switch (nBGStyle) {
    default:
    case BGS_H_BINARY:
    case BGS_H_TRINARY:
    case BGS_H_FOUR_STATE:
    case BGS_V_BINARY:
    case BGS_V_TRINARY:
    case BGS_V_FOUR_STATE:
        break;

    case BGS_H_ON_OFF:
        _html = "<div class='btn-group'>";
        _html += "<a href='#' class='btn btn-basic'>ON</a>";
        _html += "<a href='#' class='btn btn-basic'>OFF</a>";
        _html += "</div>";
        break;

    case BGS_H_COLOR_SET:
      _arg = "/neopixel?colorID=";
      _arg += nID;

      _html = "<div class='btn-group'>";
      _html += genLinkButton("MAX", _arg + "&max", BTN_STYLE_LIGHT);
      _html += genLinkButton("+",   _arg + "&inc", BTN_STYLE_LIGHT);
      _html += genLinkButton("MID", _arg + "&mid", BTN_STYLE_LIGHT);
      _html += genLinkButton("-",   _arg + "&dec", BTN_STYLE_LIGHT);
      _html += genLinkButton("MIN", _arg + "&min", BTN_STYLE_LIGHT);
      _html += genLinkButton("OFF", _arg + "&off", BTN_STYLE_LIGHT);

      _html += "</div>";
      break;

    case BGS_H_COLOR_SET_RED:
      _arg = "/neopixel?colorID=";
      _arg += nID;

      _html = "<div class='btn-group'>";
      _html += genLinkButton("MAX", _arg + "&max", BTN_STYLE_DANGER);
      _html += genLinkButton("+",   _arg + "&inc", BTN_STYLE_DANGER);
      _html += genLinkButton("MID", _arg + "&mid", BTN_STYLE_DANGER);
      _html += genLinkButton("-",   _arg + "&dec", BTN_STYLE_DANGER);
      _html += genLinkButton("MIN", _arg + "&min", BTN_STYLE_DANGER);
      _html += genLinkButton("OFF", _arg + "&off", BTN_STYLE_DANGER);
      _html += "</div>";
      break;

    case BGS_H_COLOR_SET_BLUE:
      _arg = "/neopixel?colorID=";
      _arg += nID;

      _html = "<div class='btn-group'>";
      _html += genLinkButton("MAX", _arg + "&max", BTN_STYLE_PRIMARY);
      _html += genLinkButton("+",   _arg + "&inc", BTN_STYLE_PRIMARY);
      _html += genLinkButton("MID", _arg + "&mid", BTN_STYLE_PRIMARY);
      _html += genLinkButton("-",   _arg + "&dec", BTN_STYLE_PRIMARY);
      _html += genLinkButton("MIN", _arg + "&min", BTN_STYLE_PRIMARY);
      _html += genLinkButton("OFF", _arg + "&off", BTN_STYLE_PRIMARY);
      _html += "</div>";
      break;

    case BGS_H_COLOR_SET_GREEN:
        _arg = "/neopixel?colorID=";
        _arg += nID;

        _html = "<div class='btn-group'>";
        _html += genLinkButton("MAX", _arg + "&max", BTN_STYLE_SUCCESS);
        _html += genLinkButton("+",   _arg + "&inc", BTN_STYLE_SUCCESS);
        _html += genLinkButton("MID", _arg + "&mid", BTN_STYLE_SUCCESS);
        _html += genLinkButton("-",   _arg + "&dec", BTN_STYLE_SUCCESS);
        _html += genLinkButton("MIN", _arg + "&min", BTN_STYLE_SUCCESS);
        _html += genLinkButton("OFF", _arg + "&off", BTN_STYLE_SUCCESS);
        _html += "</div>";
        break;

    case BGS_V_ON_OFF:
      _html = "<div class='btn-group-vertical'>";
      _html += "<a href='#' class='btn btn-basic'>ON</a>";
      _html += "<a href='#' class='btn btn-basic'>OFF</a>";
      _html += "</div>";
      break;

    case BGS_V_COLOR_SET:
        _arg = "/neopixel?colorID=";
        _arg += nID;

        _html = "<div class='btn-group-vertical'>";
        _html += genLinkButton("MAX", _arg + "&max", BTN_STYLE_LIGHT);
        _html += genLinkButton("+",   _arg + "&inc", BTN_STYLE_LIGHT);
        _html += genLinkButton("MID", _arg + "&mid", BTN_STYLE_LIGHT);
        _html += genLinkButton("-",   _arg + "&dec", BTN_STYLE_LIGHT);
        _html += genLinkButton("MIN", _arg + "&min", BTN_STYLE_LIGHT);
        _html += genLinkButton("OFF", _arg + "&off", BTN_STYLE_LIGHT);

        _html += "</div>";
        break;

    case BGS_V_COLOR_SET_RED:
      _arg = "/neopixel?colorID=";
      _arg += nID;

      _html = "<div class='btn-group-vertical'>";
      _html += genLinkButton("MAX", _arg + "&red&max", BTN_STYLE_DANGER);
      _html += genLinkButton("+",   _arg + "&red&inc", BTN_STYLE_DANGER);
      _html += genLinkButton("MID", _arg + "&red&mid", BTN_STYLE_DANGER);
      _html += genLinkButton("-",   _arg + "&red&dec", BTN_STYLE_DANGER);
      _html += genLinkButton("MIN", _arg + "&red&min", BTN_STYLE_DANGER);
      _html += genLinkButton("OFF", _arg + "&red&off", BTN_STYLE_DANGER);
      _html += "</div>";
      break;

    case BGS_V_COLOR_SET_BLUE:
      _arg = "/neopixel?colorID=";
      _arg += nID;

      _html = "<div class='btn-group-vertical'>";
      _html += genLinkButton("MAX",  _arg + "&blue&max", BTN_STYLE_PRIMARY);
      _html += genLinkButton("+",    _arg + "&blue&inc", BTN_STYLE_PRIMARY);
      _html += genLinkButton("MID",  _arg + "&blue&mid", BTN_STYLE_PRIMARY);
      _html += genLinkButton("-",    _arg + "&blue&dec", BTN_STYLE_PRIMARY);
      _html += genLinkButton("MIN",  _arg + "&blue&min", BTN_STYLE_PRIMARY);
      _html += genLinkButton("OFF",  _arg + "&blue&off", BTN_STYLE_PRIMARY);

      _html += "</div>";
      break;

    case BGS_V_COLOR_SET_GREEN:
      _arg = "/neopixel?colorID=";
      _arg += nID;

      _html = "<div class='btn-group-vertical'>";
      _html += genLinkButton("MAX",  _arg + "&blue&max", BTN_STYLE_SUCCESS);
      _html += genLinkButton("+",    _arg + "&blue&inc", BTN_STYLE_SUCCESS);
      _html += genLinkButton("MID",  _arg + "&blue&mid", BTN_STYLE_SUCCESS);
      _html += genLinkButton("-",    _arg + "&blue&dec", BTN_STYLE_SUCCESS);
      _html += genLinkButton("MIN",  _arg + "&blue&min", BTN_STYLE_SUCCESS);
      _html += genLinkButton("OFF",  _arg + "&blue&off", BTN_STYLE_SUCCESS);
      _html += "</div>";
      break;

  }
  rbsClient.print(_html);
}

//=================================================================================================
void render_bootstrap::renderCont(String s)
{
    String _html = "<div class='container'>";
    _html += s;
    _html += "</div>";
    rbsClient.print(_html);
}

//=================================================================================================
void render_bootstrap::renderAryCont(String ary[]) {
    String _html = "<div class='container'>%%";
    int idx = 0;

    while(ary[idx] != NULL) {
        _html += "<div class='container'>";
        _html += idx;
        _html += ":";
        _html += ary[idx];
        _html += "</div>";
        idx++;
    }
    _html += "</div>";
    rbsClient.print(_html);

}

//=================================================================================================
void render_bootstrap::renderH(int hLvl, String s)
{
    String _html = "<h" + String(hLvl) + ">";
    _html += s;
    _html += "</h" + String(hLvl) + ">";
    rbsClient.print(_html);
}

//=================================================================================================
void render_bootstrap::renderHDiv(int hLvl, String s)
{
    String _html = "<div class='container'>";
    _html += "<h" + String(hLvl) + ">";
    _html += s;
    _html += "</h" + String(hLvl) + ">";
    _html += "</div>";
    rbsClient.print(_html);
}

//=================================================================================================
void render_bootstrap::renderLink(String nUrl, String nName)
{
    String _html = "<a href='" + nUrl + "'>";
    _html += nName;
    _html += "</a>";
    rbsClient.print(_html);
}

//=================================================================================================
void render_bootstrap::renderDataRowCell(String st)
{
    String _html;
    _html += "<td>";
    _html += st;
    _html += "</td>";
    rbsClient.print(_html);
}

//=================================================================================================
void render_bootstrap::renderH1(String s)
{
    renderH(1, s);
}

//=================================================================================================
void render_bootstrap::renderH2(String s)
{
    renderH(2, s);
}

//=================================================================================================
void render_bootstrap::renderH3(String s)
{
    renderH(3, s);
}

//=================================================================================================
void render_bootstrap::renderH4(String s)
{
    renderH(4, s);
}

//=================================================================================================
void render_bootstrap::renderH5(String s)
{
    renderH(5, s);
}

//=================================================================================================
void render_bootstrap::setClient(WiFiClient nClient)
{
    rbsClient = nClient;
}