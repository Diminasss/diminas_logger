#include <iostream>
#include "diminas_logger.h"


int main() {
    setlocale(LC_ALL, "Russian");
    diminas_logger logger("/home/diminas/CLionProjects/diminas_logger/log.log", "INFO");

    logger.log("a");
    logger.log("b");
    return 0;
}