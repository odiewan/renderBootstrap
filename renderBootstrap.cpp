#include "renderBootstrap.h"
#include <ESP8266WiFi.h>

String buttonStyleNames[] = {
    "btn",
    "btn-default",
    "btn-primary",
    "btn-success",
    "btn-info",
    "btn-warning",
    "btn-danger",
    "btn-link"
};

//=================================================================================================
render_bootstrap::render_bootstrap()
{
    // rbsClient = NULL;
}

//=================================================================================================
void render_bootstrap::renderButton(String nName, buttonStyles nStyle) {
    String _html = "<button type='button' class='btn " + buttonStyleNames[nStyle] + "'>" + nName + "</button>";
    rbsClient.print(_html);
}

//=================================================================================================
void render_bootstrap::renderButtonLink(String nUrl, String nName, buttonStyles nStyle) {
    String _html = "<a href='" + nUrl + "' class='btn " + buttonStyleNames[nStyle] + "'>" + nName + "</a>";
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