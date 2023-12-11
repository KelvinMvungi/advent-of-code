#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *file = "cal_doc.txt";

bool is_digit(char ch) {
    return ch >= '0' && ch <= '9';
}