#include "../include/myLib.h"
#include <string.h>

Bool intCompare(const void *nb1, const void *nb2) {
    if (*(int *)nb1 == *(int *)nb2) {
        return True;
    }
    return False;
}

Bool charCompare(const void *nb1, const void *nb2) {
    if (*(char *)nb1 == *(char *)nb2) {
        return True;
    }
    return False;
}

Bool longCompare(const void *nb1, const void *nb2) {
    if (*(long *)nb1 == *(long *)nb2) {
        return True;
    }
    return False;
}

Bool doubleCompare(const void *nb1, const void *nb2) {
    if (*(double *)nb1 == *(double *)nb2) {
        return True;
    }
    return False;
}

Bool floatCompare(const void *nb1, const void *nb2) {
    if (*(float *)nb1 == *(float *)nb2) {
        return True;
    }
    return False;
}

Bool strCompare(const void *str1, const void *str2) {
    if (strcmp(((char *)str1), ((char *)str2)) == 0) {
        return True;
    }
    return False;
}