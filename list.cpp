#include "list.h"
#include "hashtable.h"
#include <iostream>

// Récupère ou crée un Node de type LIST pour la clé donnée
static Node* get_or_create_list_node(const std::string &key) {
    unsigned int index = hash_djb2(key);
    Node *current = table[index];

    // Chercher si la clé existe déjà
    while (current != nullptr) {
        if (current->key == key) {
            if (current->type == TYPE_LIST) {
                return current;
            } else {
                std::cout << "(error) WRONGTYPE: cette clé contient une string" << std::endl;
                return nullptr;
            }
        }
        current = current->next;
    }

    // Clé inexistante : créer un nouveau Node de type LIST
    Node *newNode = new Node();
    newNode->key = key;
    newNode->type = TYPE_LIST;
    newNode->list_value = new DoublyLinkedList();
    newNode->next = table[index];
    table[index] = newNode;
    return newNode;
}

// LPUSH key value : insère en tête
void cmd_lpush(const std::string &key, const std::string &value) {
    Node *node = get_or_create_list_node(key);
    if (node == nullptr) return;

    DLNode *newDL = new DLNode();
    newDL->value = value;
    newDL->prev = nullptr;
    newDL->next = node->list_value->head;

    if (node->list_value->head != nullptr) {
        node->list_value->head->prev = newDL;
    } else {
        node->list_value->tail = newDL;
    }

    node->list_value->head = newDL;
    node->list_value->size++;
    std::cout << "(integer) " << node->list_value->size << std::endl;
}

// RPUSH key value : insère en queue
void cmd_rpush(const std::string &key, const std::string &value) {
    Node *node = get_or_create_list_node(key);
    if (node == nullptr) return;

    DLNode *newDL = new DLNode();
    newDL->value = value;
    newDL->next = nullptr;
    newDL->prev = node->list_value->tail;

    if (node->list_value->tail != nullptr) {
        node->list_value->tail->next = newDL;
    } else {
        node->list_value->head = newDL;
    }

    node->list_value->tail = newDL;
    node->list_value->size++;
    std::cout << "(integer) " << node->list_value->size << std::endl;
}

// LPOP key : extrait en tête
std::string cmd_lpop(const std::string &key) {
    unsigned int index = hash_djb2(key);
    Node *current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            if (current->type != TYPE_LIST) {
                return "(error) WRONGTYPE: cette clé contient une string";
            }
            DoublyLinkedList *list = current->list_value;
            if (list->head == nullptr) return "(nil)";

            DLNode *toDelete = list->head;
            std::string val = toDelete->value;

            list->head = toDelete->next;
            if (list->head != nullptr) {
                list->head->prev = nullptr;
            } else {
                list->tail = nullptr;
            }
            list->size--;
            delete toDelete;
            return val;
        }
        current = current->next;
    }
    return "(nil)";
}

// RPOP key : extrait en queue
std::string cmd_rpop(const std::string &key) {
    unsigned int index = hash_djb2(key);
    Node *current = table[index];

    while (current != nullptr) {
        if (current->key == key) {
            if (current->type != TYPE_LIST) {
                return "(error) WRONGTYPE: cette clé contient une string";
            }
            DoublyLinkedList *list = current->list_value;
            if (list->tail == nullptr) return "(nil)";

            DLNode *toDelete = list->tail;
            std::string val = toDelete->value;

            list->tail = toDelete->prev;
            if (list->tail != nullptr) {
                list->tail->next = nullptr;
            } else {
                list->head = nullptr;
            }
            list->size--;
            delete toDelete;
            return val;
        }
        current = current->next;
    }
    return "(nil)";
}
