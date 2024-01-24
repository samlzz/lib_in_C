#include "../include/myLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//! For pointer
void checkAlloc(void *pointeur) {
    if (pointeur == NULL) {
        printf("Erreur d'alocation mémoire");
        exit(0);
    }
}

//* Console

void waitTillEnter() {
    int input = 0;
    while (input != '\n') {
        input = getchar();
        // if (input == 'd') {
        //     __action__
        // }
    }
}
void emptyBuff() {
    int c = 0;
    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}

void *read(char *entry, int size, readParam arg) {
    // -> *char | *long | *double
    char *output = NULL, *theEnter = NULL;
    long *result = NULL;
    double *resp = NULL;
    output = calloc(size, sizeof(char));
    result = calloc(size, sizeof(long));
    resp = calloc(size, sizeof(double));

    printf("%s", entry);
    fgets(output, size, stdin);
    if (output == NULL) {
        // user a rien écrit
        emptyBuff();
        return NULL;
    }
    theEnter = strchr(output, '\n'); //? cherche un retour a la ligne
    if (theEnter != NULL) {
        *theEnter = '\0'; //? le remplace par caratère de fin de chaine
    } else {
        emptyBuff();
    }

    switch (arg) {
    case 'e':
        //? entier
        *result = strtol(output, NULL, 10);

        free(resp);
        free(output);
        return result;
        break;
    case 'd':
        //?decimal
        *resp = strtod(output, NULL);

        free(result);
        free(output);
        return resp;
        break;
    }
    free(result);
    free(resp);
    return output;
}