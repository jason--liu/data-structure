#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int EleType;
#define LIST_SIZE 1024

#define TRUE 1
#define FALSE 0

typedef struct {
    EleType data[LIST_SIZE];
    int     last;
} SequenList;
