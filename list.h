#ifndef LIST_H
#define LIST_H

#include <string>

struct DLNode {
    std::string value;
    DLNode *prev;
    DLNode *next;
};

struct DoublyLinkedList {
    DLNode *head;
    DLNode *tail;
    int size;

    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
};

// Opérations sur les listes
void cmd_lpush(const std::string &key, const std::string &value);
void cmd_rpush(const std::string &key, const std::string &value);
std::string cmd_lpop(const std::string &key);
std::string cmd_rpop(const std::string &key);
void cmd_lrange(const std::string &key, int start, int end);

#endif
