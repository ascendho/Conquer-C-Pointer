#include <stdio.h>

void func(int a, int b);

int main() {
    int a, b;

    printf("main:&a..%p &b..%p\n", (void *) &a, (void *) &b);
    func(1, 2);

    return 0;
}

void func(int a, int b) {
    int c, d;

    printf("func:&a..%p &b..%p\n", (void *) &a, (void *) &b);
    printf("func:&c..%p &d..%p\n", (void *) &c, (void *) &d);
}