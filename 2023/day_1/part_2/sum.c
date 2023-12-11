#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *file = "cal_doc.txt";

bool is_digit(char ch) {
    return ch >= '0' && ch <= '9';
}

int parse_digit(char ch) {
        return ch - '0';
}

typedef struct {
    int index;
    int value;
} Position;

Position min_position(Position a, Position b) {
    if (a.index == -1 && b.index == -1) {
        return b;
    } else if (a.index == -1) {
        return b;
    } else if (b.index == -1) {
        return a;
    } else if (a.index < b.index) {
        return a;
    } else {
        return b;
    }
}

Position max_position(Position a, Position b) {
    if(a.index == -1 && b.index == -1) {
        return b;
    } else if(a.index == -1) {
        return b;
    } else if(b.index == -1){
        return a;
    } else if (a.index > b.index) {
        return a;
    } else {
        return b;
    }
}

int is_named_int (char* str) {
    if (strncmp(str, "one", 3) == 0) return 1;
    if (strncmp(str, "two", 3) == 0) return 2;
    if (strncmp(str, "three", 5) == 0) return 3;
    if (strncmp(str, "four", 4) == 0) return 4;
    if (strncmp(str, "five", 4) == 0) return 5;
    if (strncmp(str, "six", 3) == 0) return 6;
    if (strncmp(str, "seven", 5) == 0) return 7;
    if (strncmp(str, "eight", 5) == 0) return 8;
    if (strncmp(str, "nine", 4) == 0) return 9;
    return -1;
}