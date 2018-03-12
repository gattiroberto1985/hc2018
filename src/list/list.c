#include "../../inc/list/list.h"
#include "../../inc/beans/position.h" // for emergency matter!
#include <stdlib.h>
#include <stdio.h>

Node* node_new(Ride* pRide ) {
    Node* node = malloc( sizeof( Node ) );
    if ( node == NULL ) {
        //TODO: manage NULL!
    }
    node->next = NULL;
    node->ride = *( ride_new() );
    return node;
}

void node_destroy(Node* n) {

    while( n != NULL ) {
        printf(" [ node_destroy ] Request for node destroying @ %p\n", n);
        printf( " [ node_destroy ] Destroying node->ride . . .\n");
        ride_destroy( &( n->ride ) );
        printf( " [ node_destroy ] Destroying node . . .\n");
        free( n );
        n = NULL;
    }
}

Node* node_createList(int listSize) {
    // First node created by hand
    Node* head = malloc( sizeof ( Node ) );
    Node* n = head;
    for ( int i = 0; i < listSize; i++ ) {
        n->next = malloc( sizeof( Node ) );
        n = ( Node* ) n->next;
    }
    return head;
}

void node_destroyList(Node* head) {
    Node* n = head;
    while ( n != NULL ) {
        Node* current = n;
        n = ( Node* ) current->next;
        node_destroy( current );
    }
}

Node* node_addElementToPos(Node* head, Ride* pRide, int pos) {
    if ( head == NULL ) {
        //TODO: boh
    }

    if ( pos > node_listLength(head) ) {
        // pos greater than listlengh: adding over the last element! Whoaaa!
        return NULL;
    }

    int cnt = 0;
    Node* n = head;

    while ( cnt < pos ) {
        cnt++;
        n = (Node*) n->next;
    }

    // n is the element before the one at the position
    Node* theNext = ( Node* ) n->next; // May be null if adding in tail
    Node* newNode = node_new(pRide); // Defining the new node
    // So, switching the nodes:
    n->next = newNode;       // the "next" of the previous is the new node
    newNode->next = theNext; // the "next" of the new node is the "old" next
    return newNode;          // returning the new node
}


void node_setElementInPos(Node* head, Ride* pRide, int pos) {
    if ( head == NULL ) {
        //TODO: boh
        printf ( " [ node_setElementInPos ] HEAD IS NULL!\n");
    }
    println( " [ node_setElementInPos ] Printing element . . .");
    printf(" [ node_setElementInPos ] pRide is: %p, while its size is %i\n", pRide, sizeof(pRide) );
    //ride_toString( pRide );
    printf( " [ node_setElementInPos ]  pRide contains ");
    ride_toString( pRide );
    if ( pos > node_listLength(head) ) {
        // pos greater than listlengh: adding over the last element! Whoaaa!
        return;
    }
    int cnt = 0;
    Node* n = head;

    while ( cnt < pos ) {
        cnt++;
        n = ( Node* ) n->next;
    }
    printf(" [ node_setElementInPos ] Adding ride at position %i . . .\n", cnt);
    n->ride = *pRide;
}

Ride* node_getElementAtPos(Node* head, int pos) {
    if ( pos > node_listLength(head) ) {
        // pos greater than listlengh: adding over the last element! Whoaaa!
        return NULL;
    }
    Node* n = head;
    int curPos = 0;
    while ( curPos < pos ) {
        n = ( Node* ) n->next;
        curPos++;
    }
    return & ( n->ride );
}


Ride* node_deleteElementByObj(Ride* pRide) {
    return NULL;
}

Ride* node_deleteElementByPos(int ep) {
    return NULL;
}

int node_listLength(Node* head) {
    Node* n = head;
    int size = 0;

    while ( n->next != NULL ) {
        size++;
        n = ( Node* ) n->next;
    }

    return size;
}
