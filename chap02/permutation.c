#include <stdio.h>

/* n的最大值 */
#define N_MAX (100)

/* 若数字已被使用，则将下标为该数字的元素设成1 */
int used_flag[N_MAX + 1];

int result[N_MAX];
int n, r;

void print_result();

void permutation(int nth);

int main(int argc, char **argv) {
    // n=3 r=3
    sscanf(argv[1], "%d", &n);
    sscanf(argv[2], "%d", &r);

    permutation(0);

    return 0;
}

void print_result() {
    for (int i = 0; i < r; i++) {
        printf("%d ", result[i]);
    }

    printf("\n");
}

void permutation(int nth) {
    // r=3
    if (nth == r) {
        print_result();
        return;
    }

    // n=3
    for (int i = 1; i <= n; i++) {
        if (used_flag[i] == 0) {
            result[nth] = i;
            used_flag[i] = 1;
            permutation(nth + 1);
            used_flag[i] = 0;
        }
    }
}