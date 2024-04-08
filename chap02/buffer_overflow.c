#include <stdio.h>

void hello();

void func();

int main() {
    int buf[1000];
    buf[999] = 10;

    func();

    return 0;
}

void hello() {
    fprintf(stderr, "hello!\n");
}

void func() {
    void *buf[10];
    static int i;

    for (i = 0; i < 100; i++) { // ←溢出!!
        buf[i] = hello;
    }
}