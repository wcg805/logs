////////////////////////////////////////////////////////////////////////////////
// FileName: logs.cpp
// Author: Minho
// Create: 17/10/2018
// Edit:
// V0.1		17/10/2018	-Initial Version
////////////////////////////////////////////////////////////////////////////////

#include "logs.h"

int Logs::init()
{
    printf("function init output strings\n");
}

int Logs::setLogPath(const char *szPath)
{
    sprintf(m_szLogPath, "%s", szPath);
    mkcd(m_szLogPath);
    return 0;
}

int Logs::setLogName(const char *szName)
{
    sprintf(m_szLogName, "%s", szName);
    return 0;
}

int Logs::setLogLevel(int nLevel)
{
    if (nLevel > LOGS_LEVEL_OFF || nLevel < LOGS_LEVEL_ALL)
    {
        return LOGS_RETURN_CODE_ERROR; //无效的参数
    }
    else
    {
        m_eLogLevel = LOGS_LEVEL(nLevel);
        return LOGS_RETURN_CODE_SUCCESS; //参数有效, 设置成功
    }
}

int Logs::trace(const char *szMsg)
{
    if (LEVEL_ALL >= m_eLogLevel)
    {
        write(LEVEL_ALL, szMsg);
        return LOGS_RETURN_CODE_SUCCESS;
    }
    else
    {
        return LOGS_RETURN_CODE_ERROR;
    }
}

int Logs::debug(const char *szMsg)
{
    if (LEVEL_DEBUG >= m_eLogLevel)
    {
        write(LEVEL_DEBUG, szMsg);
        return LOGS_RETURN_CODE_SUCCESS;
    }
    else
    {
        return LOGS_RETURN_CODE_ERROR;
    }
}

int Logs::info(const char *szMsg)
{
    if (LEVEL_INFO >= m_eLogLevel)
    {
        write(LEVEL_DEBUG, szMsg);
        return LOGS_RETURN_CODE_SUCCESS;
    }
    else
    {
        return LOGS_RETURN_CODE_ERROR;
    }
}

int Logs::warn(const char *szMsg)
{
    if (LEVEL_WARN >= m_eLogLevel)
    {
        write(LEVEL_WARN, szMsg);
        return LOGS_RETURN_CODE_SUCCESS;
    }
    else
    {
        return LOGS_RETURN_CODE_ERROR;
    }
}

int Logs::error(const char *szMsg)
{
    if (LEVEL_ERROR >= m_eLogLevel)
    {
        write(LEVEL_ERROR, szMsg);
        return LOGS_RETURN_CODE_SUCCESS;
    }
    else
    {
        return LOGS_RETURN_CODE_ERROR;
    }
}

int Logs::fatal(const char *szMsg)
{
    if (LEVEL_FATAL >= m_eLogLevel)
    {
        write(LEVEL_FATAL, szMsg);
        return LOGS_RETURN_CODE_SUCCESS;
    }
    else
    {
        return LOGS_RETURN_CODE_ERROR;
    }
}

int Logs::write(LOGS_LEVEL eLevel, const char *szMsg)
{
    char szLevel[20] = {0};
    char szTime[70] = {0};
    char szLogText[4096] = {0};
    getLevelString(szLevel, eLevel);
    getLogTime(szTime);
    sprintf(szLogText, "%s %s %s\r\n", szTime, szLevel, szMsg);
    printf("%s", szLogText);
    writeFile((const char *)szLogText);
    return 0;
}

int Logs::writeFile(const char *szMsg)
{
    FILE *file;

    char szFullPath[4096] = {0};
    sprintf(szFullPath, "%s%s", m_szLogPath, m_szLogName);

    //打开文件
    if ((file = fopen(szFullPath, "a+")) == NULL)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    fwrite(szMsg, 1, strlen(szMsg), file); //写入语句
    fclose(file);
    return 0;
}

int Logs::getLevelString(char *szOut, LOGS_LEVEL eLevel)
{
    if (LEVEL_ALL == eLevel)
    {
        sprintf(szOut, "[TRACE]");
    }
    else if (LEVEL_DEBUG == eLevel)
    {
        sprintf(szOut, "[DEBUG]");
    }
    else if (LEVEL_INFO == eLevel)
    {
        sprintf(szOut, "[INFO]");
    }
    else if (LEVEL_WARN == eLevel)
    {
        sprintf(szOut, "[WARN]");
    }
    else if (LEVEL_ERROR == eLevel)
    {
        sprintf(szOut, "[ERROR]");
    }
    else if (LEVEL_FATAL == eLevel)
    {
        sprintf(szOut, "[FATAL]");
    }
    else if (LEVEL_OFF == eLevel)
    {
        sprintf(szOut, "[OFF]");
    }
    return 0;
}

int Logs::getLogTime(char *szTime)
{
    struct timeval tv;
    char buf[64];
    gettimeofday(&tv, NULL);
    strftime(buf, sizeof(buf) - 1, "%Y-%m-%d %H:%M:%S", localtime(&tv.tv_sec));
    sprintf(szTime, "%s", buf);
    return 0;
}

int Logs::output(const char *szMsg)
{
    return 0;
}
