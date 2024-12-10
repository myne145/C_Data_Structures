//
// Created by antekk on 12/10/24.
//

#ifndef H_T_H
#define H_T_H

typedef struct h_t {
    int key;
    char* value;
    struct h_t* next;
    struct h_t* previous;
} h_t;

void free_h_t(h_t* map);

void print_h_t(h_t* map);

h_t* init(int key, char* value);

void put_value(h_t* map, int key, char* value);

h_t* get_key(h_t* map, int key);

void remove_key(h_t** map, int key);

int length_h_t(h_t* map);

char** get_all_values(h_t* map);

int* get_all_keys(h_t* map);

#endif //H_T_H
