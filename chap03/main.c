#include <stdio.h>
#include <string.h>

int main() {
    // P151 P173 P176 P180 P188 P194

//    int a[3];
//    int(*ptr)[3]=a;
//
//    printf("%p\n",ptr[0]);
//    printf("%d\n",*ptr[0]);
//
//    ptr++;
//    printf("%p\n",ptr[0]);
//    printf("%d\n",*ptr[0]);

//    printf("%d\n",*(a+3));

//    int* ptr_=a;
//    printf("%d\n",ptr_[0]);
//    ptr_++;
//    printf("%d\n",ptr_[0]);

    char *str = "abc";
    *(str + 1) = 'F';


    puts(str);

    printf("-------------");


    return 0;
}