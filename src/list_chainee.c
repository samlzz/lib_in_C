#include "../include/myLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List *mkList(void *valu) {
    //? Crée une nouvelle liste avec un seul élément.
    List *list = malloc(sizeof(*list));
    Cell *firstCell = malloc(sizeof(*firstCell));
    checkAlloc(list);
    checkAlloc(firstCell);

    firstCell->data = valu;
    firstCell->nextCell = NULL;

    list->first = firstCell;
    list->lenght = 1;

    return list;
}

void rmList(List *liste) {
    //? Supprime et libère la mémoire de toute la liste.
    Cell *point = liste->first, *next = NULL;

    while (point->nextCell != NULL) {
        next = point->nextCell;
        free(point);
        point = next;
    }
    free(point);
    free(liste);
}

int addCell(List *liste, void *valu) {
    //? Ajoute une nouvelle cellule à la fin de la liste.
    Cell *point = liste->first->nextCell, *newCell = malloc(sizeof(*newCell));
    checkAlloc(newCell);
    int i = 1;
    newCell->data = valu;
    newCell->nextCell = NULL;
    if (point == NULL) { //? si pointer du 1er elem...
        liste->first->nextCell = newCell;
    } else {
        while (point->nextCell != NULL) {
            point = point->nextCell;
            i++;
        }
        point->nextCell = newCell;
    }
    liste->lenght++;
    return liste->lenght;
}

void insertCell(List *liste, void *valu, int index) {
    //? Insère une cellule à un index donné.
    Cell *newCell = malloc(sizeof(*newCell)), *point = liste->first;
    checkAlloc(newCell);
    newCell->data = valu;
    newCell->nextCell = NULL;
    int i = 1;
    while (i != index && point->nextCell != NULL) {
        point = point->nextCell;
        i++;
    }
    newCell->nextCell = point->nextCell;
    point->nextCell = newCell;
}

Cell *deleteCell(List *liste, Cell *point) {
    //? Supprime l'élément suivant à l'élément donné
    Cell *delCell = NULL;
    delCell = point->nextCell;
    checkAlloc(point);
    checkAlloc(delCell);
    point->nextCell = delCell->nextCell;

    liste->lenght--;
    return delCell;
}

Cell *delByIndex(List *liste, int index) {
    Cell *point = liste->first;
    int i = 1;
    while (i != index - 1) {
        point = point->nextCell; //? prev elem
        i++;
    }
    return deleteCell(liste, point);
}

Cell *delByValu(List *liste, void *valu) {
    Cell *point = liste->first;
    while (point->data != valu) {
        point = point->nextCell;
    }
    return deleteCell(liste, point);
}

//* Pour les listes de int

int isIn(List *liste, int *valu) {
    Cell *point = liste->first, *search = NULL;
    while (point->nextCell != NULL) {
        if (*((int *)point->data) == *valu) {
            search = point;
            break;
        }
        point = point->nextCell;
    }
    return search != NULL;
};

void displayList(List *liste) {
    Cell *point = liste->first;
    while (point->nextCell != NULL) {
        printf("%d ->", *((int *)point->data));
    }
    printf("NULL");
}