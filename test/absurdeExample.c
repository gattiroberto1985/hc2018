#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct example {
    char* name;
} example_t;

int main(int argc, char const *argv[]) {

    example_t *ex = malloc ( sizeof( example_t ) );
    ex->name = malloc( 30*sizeof( char ) );
    printf(" Copying new name on ex . . .\n");
    strcpy(ex->name ,"Hello World 1");
    printf("%s\n", ex->name);

    example_t *ex2 = malloc ( sizeof( example_t ) );
    ex2->name = malloc( 30*sizeof( char ) );
    printf(" Copying new name on ex2. . .\n");
    strcpy(ex2->name ,"Hello World 2");
    printf("%s\n", ex2->name);

    return 0;
}
