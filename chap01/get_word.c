#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int get_word(char *buf, int buf_size, FILE *fp);

int main() {
    char buf[256];

    while (get_word(buf, 256, stdin) != EOF) {
        printf("<<%s>>\n", buf);
    }

    return 0;
}

int get_word(char *buf, int buf_size, FILE *fp) {
    int len;
    int ch;

    /* 跳过空白字符 */
    while ((ch = getc(fp)) != EOF && !isalnum(ch));

    if (ch == EOF)
        return EOF;

    /* 此处ch里存放着单词的首字母 */
    len = 0;

    do {
        buf[len] = ch;
        len++;
        if (len >= buf_size) {
            /* 因单词过长而报错 */
            fprintf(stderr, "word too long.\n");
            exit(1);
        }

    } while ((ch = getc(fp)) != EOF && isalnum(ch));

    buf[len] = '\0';

    return len;
}