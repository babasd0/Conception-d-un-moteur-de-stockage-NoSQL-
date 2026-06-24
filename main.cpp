#include "parser.h"
#include <iostream>
#include <string>

int main() {
    std::string line;

    std::cout << "==============================" << std::endl;
    std::cout << "   α-Redis - Moteur NoSQL     " << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "Commandes: SET, GET, DEL, LPUSH, RPUSH, LPOP, RPOP, EXIT" << std::endl;
    std::cout << std::endl;

    while (true) {
        std::cout << "α-Redis> ";
        if (!std::getline(std::cin, line)) break;
        if (line.empty()) continue;
        parse_and_execute(line);
    }

    return 0;
}
