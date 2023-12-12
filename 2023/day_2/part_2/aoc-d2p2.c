#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

int isValidColor(const char *color) {
    return strcmp(color, "red") == 0 || strcmp(color, "green") == 0 || strcmp(color, "blue") == 0;
}

int main() {
    FILE *file = fopen("aoc-d2p2.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int max_counts[3] = {0};

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strlen(line) == 1) {
            continue;
        }

        char *game_str = strtok(line + 2, "\n"); 

        char *game_set = strtok(game_str, ";");
        while (game_set) {
            char *cube = strtok(game_set, ",");
            while (cube) {
                char *color_str = strtok(cube, " ");
                int count = atoi(strtok(NULL, " "));

                if (!isValidColor(color_str)) {
                    fprintf(stderr, "Error: Invalid color in cube: %s\n", color_str);
                    fclose(file);
                    return 1;
                }

                if (strcmp(color_str, "red") == 0) {
                    max_counts[0] = (count > max_counts[0]) ? count : max_counts[0];
                } else if (strcmp(color_str, "green") == 0) {
                    max_counts[1] = (count > max_counts[1]) ? count : max_counts[1];
                } else if (strcmp(color_str, "blue") == 0) {
                    max_counts[2] = (count > max_counts[2]) ? count : max_counts[2];
                }

                cube = strtok(NULL, ",");
            }

            game_set = strtok(NULL, ";");
        }
    }

    fclose(file);

    int newMax = max_counts[0] * max_counts[1] * max_counts[2];

    printf("%d\n", newMax);

    return 0;
}
