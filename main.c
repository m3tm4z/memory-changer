#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lib/darwin/xnumem.h"

int main(int argc, const char *argv[]) {
    size_t size = sizeof(int);  // data size
    pid_t pid;
    long int address;
    unsigned char *currentData, *newData;

    printf("---[ Processs Memory Changer ]---\n");

    printf("Enter PID :");
    scanf("%d", &pid);
    printf("[%d] PID selected\n", pid);

    printf("Enter memory address :");
    scanf("%ld", &address);
    printf("[%ld] Memory address selected\n", address);

    currentData = xnu_read(pid, (int *const) address, &size);
    printf("Current Value :%i\n", (int) *currentData);

    newData = (unsigned char *) malloc(size);
    printf("Enter new value :");
    scanf("%d", newData);

    xnu_write(pid, (int *const) address, newData, size);

    currentData = xnu_read(pid, (int *const) address, &size);
    printf("%i\n", (int) *currentData);

    getchar();

    return 0;
}
