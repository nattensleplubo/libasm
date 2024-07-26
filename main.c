#include "libasm.h"
#include <errno.h>
#include <stdio.h>
#define BUFFER_SIZE 1000000

void fill_buffer(char* buffer) {
    int i = 0;
    while (i < (BUFFER_SIZE - 1)) {
        buffer[i] = 'a';
        i++;
    }
    buffer[i] = '\0';
}

int main(void) {
    char buffer[BUFFER_SIZE];

    fill_buffer(buffer);
    char* xd = ft_strdup(buffer);
    printf("%s%c\n", xd, 'c');
    printf("%d\n", errno);
}