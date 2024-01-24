#ifndef DYNAMIC
#define DYNAMIC

#define ARR_SIZE sizeof(Array)
#define False -1
#define True 0

typedef enum {
    FALSE = False,
    TRUE = True
} Bool;

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


#endif