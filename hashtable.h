#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

#define TABLE_SIZE 1024

#define TYPE_STRING 1
#define TYPE_LIST   2

struct DoublyLinkedList;

struct Node {
    std::string key;
    std::string str_value;
    DoublyLinkedList *list_value;
    int type;
    Node *next;
};

extern Node *table[TABLE_SIZE];

unsigned int hash_djb2(const std::string &key);

// Opérations strings
void cmd_set(const std::string &key, const std::string &value);
std::string cmd_get(const std::string &key);
void cmd_del(const std::string &key);

// Opérations bonus
void cmd_keys();
void cmd_flushall();
std::string cmd_type(const std::string &key);

#endif
