#ifndef MYLIB_H
#define MYLIB_H

// Chained List
#define CELL_SIZE sizeof(Cell)
#define LIST_SIZE sizeof(List)
// Hash Map
#define MAX 1000
#define ELEM_SIZE sizeof(Elem)
#define HTABLE_SIZE sizeof(Htable)
// Dynamic Table
#define ARR_SIZE sizeof(Array)
#define False -1
#define True 0

// Enum
typedef enum type {
    CHAR,
    STR,
    INT,
    LONG,
    DOUBLE,
    STRUCT
} type;
typedef enum size {
    XS = 10,
    S = 100,
    M = 1000,
    L = 10000,
    XL = 100000,
    XXL = 1000000
} size;

typedef enum {
    FALSE = False,
    TRUE = True
} Bool;
typedef enum readParam {
    ENTIER = 'e',
    DECIMAL = 'd',
} readParam ;

// Chained List
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

    //*int list:
    int isIn(List *liste, int *valu);
    void displayList(List *liste);

// Hash Map
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

// Dynamic Table
    typedef struct {
        void **table;
        long lenght;
        long capacity;
    } Array ;

    typedef Bool (*CompareFunc)(const void *, const void *);


    Array *mkArr(void *valu);
    void rmArr(Array *arr);
    void realocTable(Array *arr);

    void push(Array *arr, void *valu);
    void insert(Array *arr, void *valu, long index);

    void *pop(Array *arr, long index);

    long find(Array *arr, void *valu, CompareFunc cmp);

    Array *concat(Array *arr1, Array *arr2);

// Console
    void *read(char *entry, int size, readParam arg);

    void waitTillEnter();
    void emptyBuff();


// Divers
    void checkAlloc(void *pointeur);

#endif