#ifndef LIST_H
#define LIST_H

//#include "../beans/ride.h"

typedef struct _Node {
    struct Node* next;
    void* element;
} Node;

/*
#define list_new() (typeof (ll)) _ll_new(ll, sizeof(*ll))
#define ll_pop(ll) (typeof (ll)) _ll_pop(ll)
#define ll_next(ll) (typeof (ll)) _ll_next(ll)
#define ll_reduce(ll, fn, val) (typeof (ll)) _ll_reduce(ll, fn, val)

#define ll_foreach(ll, item) \
    for (typeof (ll) item = ll; item; item = _ll_next(item))

#define LL_REDUCE_FN(type, name1, name2) \
    (void *_a, void *_b) { \
        type name1 = _a, name2 = _b;
*/
Node* node_createList(int listSize);
void  node_destroyList(Node* head);
Node* node_new(void* pr, size_t sizeOfElement);
void  node_destroy(Node* n);
Node* node_createList(int length);
Node* node_addElementToPos(Node* head, void* pr, int sizeOfEl, int pos);
Node* node_addElementTail(Node* head, void* pr, int sizeOfEl);
void  node_setElementInPos(Node* head, void* pr, int pos);
void* node_getElementAtPos(Node* head, int pos);
void* node_deleteElementByObj(void* pr);
void* node_deleteElementByPos(int ep);
int   node_listLength(Node* head);
void  node_toString(Node* node);

#endif
