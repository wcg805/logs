#include "utils.h"

void mkcd(const char *dir)
{
    int nIndex = 1;
    char *tmp = (char *)dir;
    while (nIndex < strlen(dir) + 1)
    {
        if (*(dir + nIndex) == '/' || *(dir + nIndex) == '\0')
        {
            char parent[256] = {0};
            strncpy(parent, dir, nIndex);
            if (0 != access(parent, 6))
            {
                mkdir(parent, 0755);
            }
        }
        nIndex++;
    }
}