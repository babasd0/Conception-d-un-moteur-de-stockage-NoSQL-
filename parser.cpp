#include "parser.h"
#include "hashtable.h"
#include "list.h"
#include <iostream>
#include <sstream>
#include <vector>

// Découpe une ligne en tokens
static std::vector<std::string> tokenize(const std::string &line) {
    std::vector<std::string> tokens;
    std::istringstream iss(line);
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

// Parse et exécute une commande
void parse_and_execute(const std::string &line) {
    std::vector<std::string> tokens = tokenize(line);

    if (tokens.empty()) return;

    std::string cmd = tokens[0];
    for (char &c : cmd) c = toupper(c);

    if (cmd == "SET") {
        if (tokens.size() < 3) {
            std::cout << "(error) Usage: SET key value" << std::endl;
            return;
        }
        cmd_set(tokens[1], tokens[2]);

    } else if (cmd == "GET") {
        if (tokens.size() < 2) {
            std::cout << "(error) Usage: GET key" << std::endl;
            return;
        }
        std::cout << cmd_get(tokens[1]) << std::endl;

    } else if (cmd == "DEL") {
        if (tokens.size() < 2) {
            std::cout << "(error) Usage: DEL key" << std::endl;
            return;
        }
        cmd_del(tokens[1]);

    } else if (cmd == "LPUSH") {
        if (tokens.size() < 3) {
            std::cout << "(error) Usage: LPUSH key value" << std::endl;
            return;
        }
        cmd_lpush(tokens[1], tokens[2]);

    } else if (cmd == "RPUSH") {
        if (tokens.size() < 3) {
            std::cout << "(error) Usage: RPUSH key value" << std::endl;
            return;
        }
        cmd_rpush(tokens[1], tokens[2]);

    } else if (cmd == "LPOP") {
        if (tokens.size() < 2) {
            std::cout << "(error) Usage: LPOP key" << std::endl;
            return;
        }
        std::cout << cmd_lpop(tokens[1]) << std::endl;

    } else if (cmd == "RPOP") {
        if (tokens.size() < 2) {
            std::cout << "(error) Usage: RPOP key" << std::endl;
            return;
        }
        std::cout << cmd_rpop(tokens[1]) << std::endl;

    } else if (cmd == "LRANGE") {
        if (tokens.size() < 4) {
            std::cout << "(error) Usage: LRANGE key start end" << std::endl;
            return;
        }
        int start = std::stoi(tokens[2]);
        int end   = std::stoi(tokens[3]);
        cmd_lrange(tokens[1], start, end);

    } else if (cmd == "KEYS") {
        cmd_keys();

    } else if (cmd == "FLUSHALL") {
        cmd_flushall();

    } else if (cmd == "TYPE") {
        if (tokens.size() < 2) {
            std::cout << "(error) Usage: TYPE key" << std::endl;
            return;
        }
        std::cout << cmd_type(tokens[1]) << std::endl;

    } else if (cmd == "HELP") {
        std::cout << "Commandes disponibles:" << std::endl;
        std::cout << "  SET key value" << std::endl;
        std::cout << "  GET key" << std::endl;
        std::cout << "  DEL key" << std::endl;
        std::cout << "  LPUSH key value" << std::endl;
        std::cout << "  RPUSH key value" << std::endl;
        std::cout << "  LPOP key" << std::endl;
        std::cout << "  RPOP key" << std::endl;
        std::cout << "  LRANGE key start end" << std::endl;
        std::cout << "  KEYS" << std::endl;
        std::cout << "  FLUSHALL" << std::endl;
        std::cout << "  TYPE key" << std::endl;
        std::cout << "  EXIT / QUIT" << std::endl;

    } else if (cmd == "EXIT" || cmd == "QUIT") {
        std::cout << "Bye!" << std::endl;
        exit(0);

    } else {
        std::cout << "(error) Commande inconnue: " << cmd << std::endl;
    }
}
