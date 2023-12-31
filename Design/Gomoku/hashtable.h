//
// Created by Admin on 14/12/2023.
//

#ifndef C2023_CHALLENGE_HASHTABLE_H
#define C2023_CHALLENGE_HASHTABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


typedef struct {
    char name[100];
    int value;
    char conditions[10][100];
    int conditions_number;
} SpecialChessPattern;

typedef struct Node {
    SpecialChessPattern data;
    struct Node* next;
} Node;

#define TABLE_SIZE 100
Node* HashTable[TABLE_SIZE];

unsigned int hash(const char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash * 31) + *str++;
    }
    return hash % TABLE_SIZE;
}

void insertSpecialChessPattern(const SpecialChessPattern* pattern) {
    unsigned int index = hash(pattern->name);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = *pattern;
    newNode->next = NULL;

    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }
}

SpecialChessPattern* findSpecialChessPattern(const char* name) {
    unsigned int index = hash(name);
    Node* current = hashTable[index];

    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            return &current->data;
        }
        current = current->next;
    }

    return NULL;
}

static SpecialChessPattern pattern[11] =
        {{"Connect five", INFINITY, {"11111"}, 1},
         {"living four", 1000000, {"011110"}, 1},
         {"Connect four", 100, {"11110", "01111"}, 2},
         {"Threaten four", 90, {"10111", "11101", "11011"}, 3},
         {"Sleeping four", 100, { "211110", "011112", }, 2},
         {"Living three",10000,{"01110", "1101", "1011"}, 3 },
         {"Sleeping three", 100, {"1112", "10112", "11012", "2111", "21101"},5},
         {"Living two", 80, {"0220"}, 1},
         {"Sleeping two", 50, {"112", "211", "101"}, 3},
         {"Sleeping one", 50, {"12", "21", "201", "102"}, 4},
         {"Living one", 10, {010}, 1}
        };
char* pattern_names[10] = {"Connect_five", "living four", "Connect four", "Threaten four", "Sleeping four", "Living three", "Sleeping three", "Living two", "Living one"};


void initialise_table() {
        for(int i = 0;i<10;i++){
            insertSpecialChessPattern(&pattern[i]);
        }
}




#endif //C2023_CHALLENGE_HASHTABLE_H
