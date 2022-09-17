#include "renderBootstrap.h"

//=================================================================================================
render_bootstrap::render_bootstrap::render_bootstrap()
{
    rbsClient = nullptr;
}

//=================================================================================================
render_bootstrap::render_bootstrap(WiFiClient nClient)
{
    rbsClient = nClient;
}

//=================================================================================================
void render_bootstrap::renderH(int hLvl, String s)
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