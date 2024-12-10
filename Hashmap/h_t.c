//
// Created by antekk on 12/10/24.
//
#include <stdlib.h>
#include "h_t.h"

#include <stdio.h>

h_t* init(int key, char* value) {
    h_t* map = malloc(sizeof(h_t*));
    if(map == NULL) {
        fprintf(stderr, "Failed to allocate memory for h_t!\n");
        return NULL;
    }

    map->value = malloc(sizeof(char*));
    if(value == NULL) {
        fprintf(stderr, "Failed to allocate memory for h_t's value \"%s\"!\n", value);
        return NULL;
    }

    map->key = key;
    map->value = value;
    map->next = NULL;
    map->previous = NULL;

    return map;
}

void print_h_t(h_t* map) {
    while(map != NULL) {
        printf("[%d, %s]\t", map->key, map->value);
        map = map->next;
    }
    printf("\n");
}

void free_h_t(h_t* map) {
    while(map != NULL) {
        free(map);
        map = map->next;
    }
}

void put_value(h_t* map, int key, char* value) {
    h_t* newNode = init(key, value);

    if(newNode == NULL) {
        fprintf(stderr, "Cannot put element to h_t - memory allocation failed!\n");
        return;
    }

    h_t* nodeWithKey = get_key(map, key);
    if(nodeWithKey != NULL) {
        nodeWithKey->value = value;
        return;
    }

    while(map->next != NULL) {
        map = map->next;
    }

    newNode->previous = map;
    map->next = newNode;
}

h_t* get_key(h_t* map, int key) {
    while(map != NULL) {
        if(map->key == key) {
            return map;
        }
        map = map->next;
    }
    return NULL;
}

void remove_key(h_t** map, int key) {
    h_t* nodeWithKey = get_key(*map, key);
    if(nodeWithKey == NULL) {
        fprintf(stderr, "Key %d not found!\n", key);
        return;
    }

    if(nodeWithKey->previous == NULL) {
        h_t* temp = *map;
        h_t* temp2 = temp->next;

        *map = temp2;

        if(temp2 == NULL)
            return;

        temp2->previous = NULL;

        free(temp);
        return;
    }

    nodeWithKey->previous->next = nodeWithKey->next;
}

int length_h_t(h_t* map) {
    int n = 0;
    while(map != NULL) {
        ++n;
        map = map->next;
    }

    return n;
}

char** get_all_values(h_t* map) {
    char** values = malloc(sizeof(char*) * length_h_t(map));

    int iter = 0;
    while(map != NULL) {
        values[iter] = map->value;

        ++iter;
        map = map->next;
    }
    return values;
}

int* get_all_keys(h_t *map) {
    int* keys = malloc(sizeof(int) * length_h_t(map));

    int iter = 0;
    while(map != NULL) {
        keys[iter] = map->key;

        ++iter;
        map = map->next;
    }
    return keys;
}
