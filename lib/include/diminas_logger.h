#pragma once

#include <iostream>

#ifdef _WIN32
#ifdef DIMINAS_LOGGER_EXPORTS
#define DIMINAS_LOGGER_API __declspec(dllexport)
#else
#define DIMINAS_LOGGER_API __declspec(dllimport)
#endif
#else
#define DIMINAS_LOGGER_API
#endif

class DIMINAS_LOGGER_API diminas_logger {
public:
    void say_hello();
};
