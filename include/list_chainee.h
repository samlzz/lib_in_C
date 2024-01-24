#ifndef CHAINEDLIST
#define CHAINEDLIST

#define CELL_SIZE sizeof(Cell)
#define LIST_SIZE sizeof(List)

typedef enum type {
    CHAR,
    STR,
    INT,
    LONG,
    DOUBLE,
    STRUCT
} type;

struct Cell {
    void *data;
    struct Cell *nextCell;
};
typedef struct Cell Cell;

struct List {
    Cell *first;
    int lenght;
};
typedef struct List List;


List *mkList(void *elem);
void rmList(List *liste);

int addCell(List *liste, void *elem);
void insertCell(List *liste, void *elem, int index);

Cell *deleteCell(List *liste, Cell *point);
Cell *delByIndex(List *liste, int index);
Cell *delByValu(List *liste, void *elem);

//* liste de int:
int isIn(List *liste, int *valu);
void displayList(List *liste);


#endif