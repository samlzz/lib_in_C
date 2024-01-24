#ifndef HASH_TABLE
#define HASH_TABLE

#include "list_chainee.h"
#include "../include/console.h"

#define MAX 1000
#define ELEM_SIZE sizeof(Elem)
#define HTABLE_SIZE sizeof(Htable)


typedef enum size {
    XS = 10,
    S = 100,
    M = 1000,
    L = 10000,
    XL = 100000,
    XXL = 1000000
} size;

typedef struct Index {
    int key;
    int index;
} Index;

typedef struct Elem {
    int key;
    void *data;
} Elem;

typedef struct Htable {
    Elem **tableOfElem;
    List *conflictIndex;
    type typeOf;
    size size;
} Htable;

Htable *mkHtable(size size, type tableValu);
void rmHtable(Htable *tableToDel);

unsigned long hashed(char *str);
int getTheIndex(void *valu, Htable *table);
List *putList(Elem *conflict);

Index addElem(Htable *table, void *valu);
void *delElem(Htable *table, Index i);
void *removeElem(Htable *table, void *valu);


#endif