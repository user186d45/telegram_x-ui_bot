#ifndef LOG_H
#define LOG_H

#include <stdint.h>

enum logLevel {
    INFO,
    WARNING,
    ERROR

};

void applicationLog(uint8_t logLevel, const char* prettyFunc, const char* msg);

#endif

