#include <iostream>
#include "diminas_logger.h"


int main() {
    setlocale(LC_ALL, "Russian");
    diminas_logger logger;
    logger.say_hello();
    auto lang = "C++";
    std::cout << "Hello and welcome to " << lang << "!\n";

    for (int i = 1; i <= 5; i++) {

        std::cout << "i = " << i << std::endl;
    }

    return 0;
}