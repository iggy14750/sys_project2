
#include <stdio.h>
#define SIZE 100

int printable(char c) {return 32 < c && c <= 126;}

int main(int argc, char *argv[])
{
    char c;
    FILE* file;
    int i = 0;
    char buff[SIZE];
    if (argc < 2) {
        printf("Please enter a valid filename.\n");
        return 1;
    }
    file = fopen(argv[1], "r");
    if (!file) {
        printf("Please enter a valid filename.\n");
        return 1;
    }


    while ((c = fgetc(file)) != EOF) {
        if (printable(c)) {
            if (i < SIZE-1) {
                buff[i++] = c;
            } else {
                buff[i] = '\0';
                printf(buff);
                i = 0;
            }
        } else {
            if (i <= 3) {
                buff[i] = '\0';
                printf("%s\n", buff);
            }
            i = 0;
        }
    }
    return 0;
}









