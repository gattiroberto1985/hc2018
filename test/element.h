#ifndef ELEMENT
#define ELEMENT

#define ELEMENT_TITLE_MAX_SIZE 64

#include <stdlib.h>
#include <string.h>

typedef struct Element {
    int id;
    char *title;
} element_t;

element_t* element_new();

void element_destroy(element_t* el);

void element_setId(element_t* el, const int id);

void element_setTitle(element_t* el, const char title[]);

char* element_toString(element_t* el);

#endif
