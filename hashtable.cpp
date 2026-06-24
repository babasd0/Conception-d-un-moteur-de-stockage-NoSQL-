#include "hashtable.h"
#include "list.h"
#include <iostream>

// Initialisation du tableau principal
Node *table[TABLE_SIZE] = {nullptr};

// Fonction de hachage DJB2
unsigned int hash_djb2(const std::string &key) {
    unsigned int hash = 5381;
    for (char c : key) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % TABLE_SIZE;
}

// SET key value
void cmd_set(const std::string &key, const std::string &value) {
    unsigned int index = hash_djb2(key);
    Node *current = table[index];

    // Chercher si la clé existe déjà
    while (current != nullptr) {
        if (current->key == key) {
            // Clé trouvée : mise à jour
            current->str_value = value;
            current->type = TYPE_STRING;
            std::cout << "OK" << std::endl;
            return;
        }
        current = current->next;
    }

    // Clé inexistante : créer un nouveau maillon
    Node *newNode = new Node();
    newNode->key = key;
    newNode->str_value = value;
    newNode->type = TYPE_STRING;
    newNode->list_value = nullptr;
    newNode->next = table[index];
    table[index] = newNode;
    std::cout << "OK" << std::endl;
}

// GET key
std::string cmd_get(const std::string &key) {
    unsigned int index = hash_djb2(key);
    Node *current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            if (current->type == TYPE_STRING) {
                return current->str_value;
            } else {
                return "(error) WRONGTYPE: cette clé contient une liste";
            }
        }
        current = current->next;
    }
    return "(nil)";
}

// DEL key
void cmd_del(const std::string &key) {
    unsigned int index = hash_djb2(key);
    Node *current = table[index];
    Node *prev = nullptr;

    while (current != nullptr) {
        if (current->key == key) {
            if (prev == nullptr) {
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            std::cout << "(integer) 1" << std::endl;
            return;
        }
        prev = current;
        current = current->next;
    }
    std::cout << "(integer) 0" << std::endl;
}
