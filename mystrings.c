#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int printable(char c) {return 32 < c && c <= 126;}
void ensureCapacity(char**, int*, int);
void minBuff(char**, int*);

int main(int argc, char *argv[])
{
    char c;
    FILE* file;
    int i = 0;
    char *buff = malloc(SIZE);
    if (argc < 2) {
        printf("Please enter a valid filename.\n");
        return 1;
    }
    file = fopen(argv[1], "r");
    if (!file) {
        printf("Please enter a valid filename.\n");
        return 1;
    }


    while ((c = fgetc(file)) != EOF)
    {
        if (printable(c)) {
            if (i < SIZE)
            buff[i++] = c;
        } else {
            if (i <= 3) {
                buff[i] = '\0';
                printf("%s\n", buff)
                minBuff(&buff, &size);
            }
            i = 0;
        }
    }
    
    return 0;
}

// replace buff with one of minimal size
void minBuff(char** buff, int* size) {

    if (*size <= DEFAULT) return;
    *size = DEFAULT;
    free(*buff);
    *buff = malloc(size);
}

// Double the size of buff, if necessay
void ensureCapacity(char **buff, int *size, int curr) {

    if (curr < *size) return;
    *size = 2*curr;
    char *replace = malloc(*size);
    int i;
    for (i = 0; i < curr; i++) {
        replace[i] = (*buff)[i];
    }
    free(*buff);
    *buff = replace;
}









