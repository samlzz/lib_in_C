#ifndef CONSOLE
#define CONSOLE

void checkAlloc(void *pointeur);

typedef enum readParam {
    ENTIER = 'e',
    DECIMAL = 'd',
} readParam ;

void *read(char *entry, int size, readParam arg);

void waitTillEnter();
void emptyBuff();

#endif