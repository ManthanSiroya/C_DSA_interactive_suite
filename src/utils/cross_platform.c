#include "cross_platform.h"

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

void sleep_seconds(float seconds)
{
#ifdef _WIN32
    Sleep(seconds * 1000);
#else
    usleep(seconds * 1000000);
#endif
}