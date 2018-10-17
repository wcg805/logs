#include "logs.h"

int Logs::init()
{
    printf("function init output strings\n");
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
        write(szMsg);
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
        write(szMsg);
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
        write(szMsg);
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
        write(szMsg);
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
        write(szMsg);
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
        write(szMsg);
        return LOGS_RETURN_CODE_SUCCESS;
    }
    else
    {
        return LOGS_RETURN_CODE_ERROR;
    }
}

int Logs::write(const char *szMsg)
{
    printf("%s\n", szMsg);
    return 0;
}

int Logs::output(const char *szMsg)
{
    return 0;
}
