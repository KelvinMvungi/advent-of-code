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
    } esle {
        return b;
    }
}
