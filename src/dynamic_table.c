#include "../include/myLib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Array *mkArr(void *valu) {
    Array *arr = malloc(ARR_SIZE);
    checkAlloc(arr);

    arr->capacity = 10;
    arr->table = calloc(sizeof(void *), arr->capacity);
    checkAlloc(arr->table);

    if (valu == NULL) {
        arr->lenght = 0;
        return arr;
    }

    arr->table[0] = valu;
    arr->lenght = 1;
    arr->capacity--;
    return arr;
}

void rmArr(Array *arr) {
    if (arr->table != NULL) {
        free(arr->table);
    }
    free(arr);
}

void realocTable(Array *arr) {
    if (arr == NULL) {
        return;
    }
    arr->capacity = arr->lenght;
    arr->table = reallocarray(arr->table, arr->lenght * 2, sizeof(void *));
    checkAlloc(arr->table);
}

void push(Array *arr, void *valu) {
    if (arr == NULL || valu == NULL) {
        return;
    }
    if (arr->capacity < 1) {
        realocTable(arr);
    }
    arr->table[arr->lenght] = valu;
    arr->lenght++;
    arr->capacity--;
}

void insert(Array *arr, void *valu, long index) {
    if (arr == NULL || index > arr->lenght - 1 || index < 0) {
        return;
    }
    if (index == arr->lenght) {
        push(arr, valu);
        return;
    }

    if (arr->capacity < 1) {
        realocTable(arr);
    }
    for (long i = arr->lenght - 1; i > index; i--) {
        arr->table[i] = arr->table[i - 1];
    }
    arr->table[index] = valu;
    arr->lenght++;
    arr->capacity--;
}

void *pop(Array *arr, long index) {
    if (arr == NULL || index > arr->lenght - 1 || index < 0) {
        return NULL;
    }
    void *valu = arr->table[index], *deleted = NULL;
    deleted = valu;
    arr->table[index] = NULL;

    for (long i = index; i < arr->lenght - 1; i++) {
        arr->table[i] = arr->table[i + 1];
    }

    arr->lenght--;
    arr->capacity++;
    return deleted;
}

long find(Array *arr, void *valu, CompareFunc cmp) {
    if (arr == NULL || valu == NULL || cmp == NULL) {
        return False;
    }
    for (long i = 0; i < arr->lenght; i++) {
        if (cmp(valu, arr->table[i]) == 0) {
            return i;
        }
    }
    return False;
}

Array *concat(Array *arr1, Array *arr2) {
    if (arr1 != NULL && arr2 != NULL) {

        Array *res = mkArr(NULL);
        for (long i = 0; i < arr1->lenght; i++) {
            push(res, arr1->table[i]);
        }
        for (long i = 0; i < arr2->lenght; i++) {
            push(res, arr2->table[i]);
        }
        return res;
    }
    if (arr1 == NULL) {
        return arr2;
    }
    if (arr2 == NULL) {
        return arr1;
    }
    return NULL;
}

Array *duplicate(Array *arr) {
    Array *resp = mkArr(NULL);
    for (long i = 0; i < arr->lenght; i++) {
        push(resp, arr->table[i]);
    }
    return resp;
}
