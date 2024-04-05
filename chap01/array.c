#include <stdio.h>

int main() {
    int array[5];

    /* 对数组array设置值 */
    for (int i = 0; i < 5; i++) {
        array[i] = i;
    }

    /* 输出其内容 */
    for (int i = 0; i < 5; i++) {
        printf("%d\n", array[i]);
    }

    /* 输出array中各元素的地址 */
    for (int i = 0; i < 5; i++) {
        printf("&array[%d]... %p\n", i, (void *) &array[i]);
    }

    return 0;
}