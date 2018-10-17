////////////////////////////////////////////////////////////////////////////////
// FileName: logs.h
// Author: Minho
// Create: 17/10/2018
// Edit:
// V0.1		17/10/2018	-Initial Version
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <iostream>

using namespace std;
#define LOGS_LEVEL_ALL 0
#define LOGS_LEVEL_DEBUG 1
#define LOGS_LEVEL_INFO 2
#define LOGS_LEVEL_WARN 3
#define LOGS_LEVEL_ERROR 4
#define LOGS_LEVEL_FATAL 5
#define LOGS_LEVEL_OFF 6

#define LOGS_RETURN_CODE_SUCCESS 0
#define LOGS_RETURN_CODE_ERROR -1

enum LOGS_LEVEL
{
    LEVEL_ALL,
    LEVEL_DEBUG,
    LEVEL_INFO,
    LEVEL_WARN,
    LEVEL_ERROR,
    LEVEL_FATAL,
    LEVEL_OFF
};

class Logs
{
  private:
    LOGS_LEVEL m_eLogLevel = LEVEL_FATAL;

  public:
    int init();
    int setLogLevel(int nLevel);
    int trace(const char *szMsg);
    int debug(const char *szMsg);
    int info(const char *szMsg);
    int warn(const char *szMsg);
    int error(const char *szMsg);
    int fatal(const char *szMsg);

  private:
    int write(const char *szMsg);
    int output(const char *szMsg);
};
