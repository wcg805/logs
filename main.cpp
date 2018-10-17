////////////////////////////////////////////////////////////////////////////////
// FileName: main.cpp
// Author: Minho
// Create: 17/10/2018
// Edit:
// V0.1		17/10/2018	-Initial Version
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>
#include "logs.h"

using namespace std;

int main()
{
    // printf("start");
    Logs logs;
    logs.setLogLevel(LOGS_LEVEL_WARN);
    // logs.init();
    char szText[100] = {0};
    sprintf(szText, "The Trace log");
    logs.trace(szText);

    sprintf(szText, "The Debug log");
    logs.debug(szText);

    sprintf(szText, "The info log");
    logs.info(szText);

    sprintf(szText, "The Warn log");
    logs.warn(szText);

    sprintf(szText, "The Error log");
    logs.error(szText);

    sprintf(szText, "The Fatal log");
    logs.fatal(szText);
    return 0;
}