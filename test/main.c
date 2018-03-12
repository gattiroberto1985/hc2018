#ifndef MAIN
#define MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/element.h"


int main(int argc, char const *argv[]) {

    /*example_t *ex = malloc ( sizeof( example_t ) );
    printf(" Copying new name . . .\n");
    strcpy(ex->name ,"Hello World!!");
    printf("%s\n", ex->name);


    example_t *ex2 = malloc ( sizeof( example_t ) );
    printf(" Copying new name . . .\n");
    strcpy(ex2->name ,"Hello World!!");
    printf("%s\n", ex2->name);*/
    /*element2_t* p2El2 = malloc( sizeof ( element2_t ) );
    //p2El2->id = 100;
    strcpy(p2El2->title, "default title");
    printf("%s\n", p2El2->title);
    char newtitle[] = "The title set by strcpy ( p2El2->title, \"<thestring>\")";
    //setTitle(p2El2, newtitle);
    printf(" [ element_toString ] { id: %i, title: %s }\n", p2El2->id, p2El2->title);*/

    /*printf(" Playing with example_t . . .\n");
    example_t *s = malloc ( sizeof( example_t ) );
    printf(" Copying new name . . .\n");
    strcpy(s->name ,"Hello World!!");
    printf("%s\n", s->name);
    char name[] = "Saying hellooooo!";
    printf(" Changing name . . .\n");
    setName(s, name);
    printf("%s\n", s->name);*/

    /*element_t* pEl2 = malloc( sizeof ( element_t ) );
    pEl2->id = 100;
    strcpy( newtitle, "The title set by strcpy ( pEl2->title, \"<thestring>\")" );
    element_setTitle(pEl2, newtitle);
    element_toString(pEl2);*/



    element_t* pEl = element_new();
    printf(" [ main ] Object is: %s\n", element_toString( pEl ) );
    pEl->id = 0;
    strcpy(pEl->title, "This is the new title");
    printf(" [ main ] Same object post update is: %s\n", element_toString( pEl ) );
    element_destroy(pEl);
    return 0;
}
#endif
