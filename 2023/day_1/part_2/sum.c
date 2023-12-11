#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char* file = "cal_doc.txt";

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

int is_named_int(char* str) {
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

Position find_first_named_int (char* str) {
    int i = 0;
    while (i < strlen(str))
    {
        int end_of_string = (strlen(str) - i) < 5 ? (strlen(str) - i) : 5;
        if(is_named_int(strndup(str + i, end_of_string)) > 0) {
            return (Position) {i, is_named_int(strndup(str + i, end_of_string))};
        } else {
            i++;
        }
    }
    return (Position) {-1, 0};
}


    Position find_last_named_int (char* str) {
        int i = strlen(str) - 1;
        while(i >= 0) {
            int len = (strlen(str) - i) < 5 ? (strlen(str) - i) : 5;
        if (is_named_int(strndup(str + i, len)) > 0) {
            return (Position){i, is_named_int(strndup(str + i, len))};
        } else {
            i--;
        }
        }
        return (Position) {-1, 0};
    }

    Position find_first_digit (char* str) {
        int i = 0;
        while (i < strlen(str)) {
            if (is_digit(str[i])){
                return (Position){i, parse_digit(str[i])};
            } else {
                i++;
            }
        }
        return (Position){-1, 0};
    }


    Position find_last_digit(char* str) {
        int i = strlen(str) - 1;
        while (i >= 0) {
            if (is_digit(str[i])) {
                return (Position){i, parse_digit(str[i])};
            } else {
                i--;
            }
        }
            return (Position){-1, 0};

    }
    
    int solve_day_day_part_part_1 (FILE* channel, int sum) {
        char line[1000];
        while(fgets(line, sizeof(line), channel) != NULL) {
            Position first_digit = min_position(find_first_digit(line), find_first_named_int(line));
            Position last_digit = max_position(find_last_digit(line), find_last_named_int(line));

            printf("line: %s first_digit: %d, last_digit: %d\n", line, first_digit.value, last_digit.value);
            sum += (first_digit.value * 10) + last_digit.value;
        }
        return sum;
    }

    int main () {
        FILE* ic = fopen(file, "r");
    printf("%d\n", solve_day_day_part_part_1(ic, 0));
    fclose(ic);
    return 0;
    }