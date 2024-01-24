#include "../include/myLib.h"
#include <stdio.h>
#include <stdlib.h>

// https://www.youtube.com/watch?v=DMQ_HcNSOAI

Htable *mkHtable(size size, type tableValu) {
    Htable *hashT = malloc(HTABLE_SIZE);
    checkAlloc(hashT);
    hashT->tableOfElem = calloc(size, ELEM_SIZE);
    hashT->conflictIndex = NULL;
    hashT->typeOf = tableValu;
    hashT->size = size;
    return hashT;
}

void rmHtable(Htable *tableToDel) {
    if (tableToDel->conflictIndex != NULL) {
        while (tableToDel->conflictIndex->lenght != 0) {
            Cell *deleted = delByIndex(tableToDel->conflictIndex, 0);
            int *i = (int *)deleted->data;
            rmList(tableToDel->tableOfElem[*i]->data);
        }
        rmList(tableToDel->conflictIndex);
    }
    free(tableToDel->tableOfElem);
    free(tableToDel);
}

unsigned long hashed(char *str) {
    unsigned long hash = 5381;
    int c = 0;

    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}

int getTheIndex(void *valu, Htable *table) {
    char str[MAX];
    switch (table->typeOf) {
    case CHAR:
        sprintf(str, "%d", *(char *)valu);
        break;
    case INT:
        sprintf(str, "%d", *(int *)valu);
        break;
    case LONG:
        sprintf(str, "%ld", *(long *)valu);
        break;
    case DOUBLE:
        sprintf(str, "%lf", *(double *)valu);
        break;
    case STRUCT:
        // todo demander de choisir une valeur str, char, int, long ou double
        break;
    case STR:
        break;
    }

    unsigned long hash = hashed(valu);
    return hash % table->size;
}

List *putList(Elem *conflict) {
    Cell *firstCell = malloc(CELL_SIZE);
    List *liste = malloc(LIST_SIZE);
    checkAlloc(firstCell);
    checkAlloc(liste);

    firstCell->data = conflict->data;
    firstCell->nextCell = NULL;

    liste->first = firstCell;
    liste->lenght = 1;

    return liste;
}

Index addElem(Htable *table, void *valu) {
    int key = getTheIndex(valu, table), pos = 0;
    Elem *newElem = malloc(ELEM_SIZE), *point = table->tableOfElem[key];
    if (point == NULL) {
        newElem->data = valu;
        newElem->key = key;
        table->tableOfElem[key] = newElem;
    } else {
        newElem->data = putList(point);
        pos = addCell(newElem->data, valu);
        newElem->key = key;
        table->tableOfElem[key] = newElem;
        table->conflictIndex = mkList(&newElem->key);
    }
    Index *i = malloc(sizeof(*i));
    i->key = key;
    i->index = pos;
    return *i;
}

void *delElem(Htable *table, Index i) {
    Elem *deleted = table->tableOfElem[i.key];

    if (isIn(table->conflictIndex, &i.key)) {
        delByIndex(deleted->data, i.index);
    } else {
        deleted->key = 0;
        deleted->data = NULL;
    }

    return deleted;
}

void *removeElem(Htable *table, void *valu) {
    int i = getTheIndex(valu, table);
    Elem *deleted = table->tableOfElem[i];

    if (isIn(table->conflictIndex, &i)) {
        delByValu(deleted->data, valu);
    } else {
        deleted->key = 0;
        deleted->data = NULL;
    }

    return deleted;
}