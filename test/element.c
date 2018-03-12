#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../inc/element.h"

element_t* element_new( ) {
    printf(" [ element_new ] Allocating new element . . . \n");
    element_t* newEl = malloc( sizeof( element_t ) ) ;
    //newEl->title = "Hello!";
    if ( newEl == NULL ) {
        // do some stuff to manage the error
    }
    //printf( " [ element_new ] allocating memory for title . . .\n");
    //newEl->title = ( char* ) malloc( ELEMENT_TITLE_MAX_SIZE * sizeof( char ) );
    printf(" [ element_new ] Assigning default values . . . \n");
    //printf(" [ element_new ] |-- title: '%s', with length: '%i' . . . \n", newEl->title, sizeof( newEl->title ) );
    element_setId( newEl, -1);
    char defaultTitle[] = "<Default Title>";
    element_setTitle(newEl, defaultTitle);
    return newEl;
}

void element_destroy(element_t* el) {
    if ( el != NULL ) {
        if ( el->title != NULL ) {
            free( el->title );
        }
        free ( el );
    }
}

void element_setId(element_t* el, const int id) {
    printf ( " [ element_setId ] Setting id to '%i'. . .\n", id);
    if ( el != NULL )
        el->id = id;
}

void element_setTitle(element_t* el, const char title[]) {
    printf ( " [ element_setTitle ] Setting title to '%s'. . .\n", title);
    if ( el != NULL ) {
        //printf( " [ element_setTitle ] freeing old title . . .\n");
        //free( el->title);
        //printf( " [ element_setTitle ] allocating memory for title . . .\n");
        //el->title = calloc(1, ELEMENT_TITLE_MAX_SIZE * sizeof( char ) );
        //el->title = "HELLO!";
        //char newTitle[ELEMENT_TITLE_MAX_SIZE] = &title;
        //strcpy( newTitle, title );
        //el->title = newTitle;
        el->title = malloc( ELEMENT_TITLE_MAX_SIZE * sizeof( char ) );
        /*el->title = malloc( ELEMENT_TITLE_MAX_SIZE * sizeof( char ) );
        if ( el->title == NULL ) {
            printf( " [ element_setTitle ] ERROR ON ALLOCATING el->title MEMORY!\n");
        }
        printf( " [ element_setTitle ] strcpy on title . . .\n");
        el->title = title;*/
        strcpy( el->title, title);
    }
}

char* element_toString(element_t* el) {
    char* objStr = "";
    sprintf(objStr, " [ element_toString ] { id: %i, title: %s }", el->id, el->title);
    return objStr;
}
