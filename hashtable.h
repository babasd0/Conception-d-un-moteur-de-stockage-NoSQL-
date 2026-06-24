#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>

#define TABLE_SIZE 1024

// Types de valeurs supportées
#define TYPE_STRING 1
#define TYPE_LIST   2

// Forward declaration
struct DoublyLinkedList;

// Maillon de la liste chaînée (gestion des collisions)
struct Node {
    std::string key;
    std::string str_value;        // si type == TYPE_STRING
    DoublyLinkedList *list_value; // si type == TYPE_LIST
    int type;
    Node *next;
};

// Table de hachage principale
extern Node *table[TABLE_SIZE];

// Fonction de hachage DJB2
unsigned int hash_djb2(const std::string &key);

// Opérations sur les chaînes
void cmd_set(const std::string &key, const std::string &value);
std::string cmd_get(const std::string &key);
void cmd_del(const std::string &key);

#endif
