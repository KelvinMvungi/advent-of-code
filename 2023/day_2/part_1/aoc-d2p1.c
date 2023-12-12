#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    int red;
    int green;
    int blue;
} TargetCounts;

void processLine(char *line, TargetCounts targetCounts, int **validGames, int *validGamesCount);

int main() {
    FILE *file = fopen("aoc-d2p1.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    TargetCounts targetCounts = {12, 13, 14};
    int *validGames = NULL;
    int validGamesCount = 0;

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (buffer[0] == '\n') {
            continue;
        }

        // Remove the newline character if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        processLine(buffer, targetCounts, &validGames, &validGamesCount);
    }

    fclose(file);

    printf("Valid Games Count: %d\n", validGamesCount);
    for (int i = 0; i < validGamesCount; i++) {
        printf("Valid Game ID: %d\n", validGames[i]);
    }

    free(validGames); // Don't forget to free the allocated memory

    return 0;
}

void processLine(char *line, TargetCounts targetCounts, int **validGames, int *validGamesCount) {
    char *token;
    int gameId;

    // Extract game ID
    token = strtok(line, ":");
    if (token == NULL) {
        fprintf(stderr, "Error: Invalid line format (missing game ID)\n");
        return;
    }
    token = strtok(NULL, " ");
    if (token == NULL) {
        fprintf(stderr, "Error: Invalid line format (missing game ID)\n");
        return;
    }
    gameId = atoi(token);

    printf("Processing Game ID: %d\n", gameId);

    // Extract and process game sets
    token = strtok(NULL, ";");
    while (token != NULL) {
        int isValidSet = 1;

        // Extract and process each cube in the set
        char *cube = strtok(token, ",");
        while (cube != NULL) {
            char *color = strtok(cube, " ");
            char *count_str = strtok(NULL, " ");

            // Check if strtok returned a non-NULL value
            if (count_str != NULL) {
                int count = atoi(count_str);

                // Now you have the color and count, you can continue with the logic
                // For example, you might check if count is within targetCounts, etc.

                if (count > targetCounts.red || count > targetCounts.green || count > targetCounts.blue) {
                    fprintf(stderr, "Error: Invalid count in cube\n");
                    return;
                }

                // Continue processing the cube, e.g., update total counts, etc.
            } else {
                // Handle the error, e.g., print an error message
                fprintf(stderr, "Error: Invalid line format (missing count)\n");
                return;
            }

            cube = strtok(NULL, ",");
        }

        // Check if the entire set is valid
        if (isValidSet) {
            printf("Adding Valid Game ID: %d\n", gameId);
            (*validGamesCount)++;
            *validGames = realloc(*validGames, (*validGamesCount) * sizeof(int));
            if (*validGames == NULL) {
                perror("Memory allocation error");
                exit(EXIT_FAILURE);
            }

            (*validGames)[(*validGamesCount) - 1] = gameId;
            break; // Break after the first valid set for simplicity
        }

        token = strtok(NULL, ";");
    }
}
