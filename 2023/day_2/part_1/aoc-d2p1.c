#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // Define the target counts for each color
  int target_counts[3] = {12, 13, 14}; // red, green, blue

  // Open the file in read mode
  FILE *file = fopen("aoc-d2p1.txt", "r");
  if (file == NULL) {
    printf("Error opening file");
    return 1;
  }

  // Read the content of the file line by line
  char line[1024];
  int valid_games = 0;
  while (fgets(line, sizeof(line), file)) {
    // Skip empty lines
    if (strlen(line) == 1) {
      continue;
    }

    // Extract the game ID and the game string
    char *game_id_str = strtok(line, ":");
    char *game_str = strtok(NULL, "\n");
    int game_id = atoi(strtok(game_id_str, " "));

    // Check if all game lines are valid
    int valid_lines = 1;
    char *game_line = strtok(game_str, ";");
    while (game_line) {
      int valid_cubes = 1;
      char *cube = strtok(game_line, ",");
      while (cube) {
        // Extract the color and count of the cube
        char *color_str = strtok(cube, " ");
        int count = atoi(strtok(NULL, " "));

        // Convert the color string to an integer index
        int color;
        if (strcmp(color_str, "red") == 0) {
          color = 0;
        } else if (strcmp(color_str, "green") == 0) {
          color = 1;
        } else if (strcmp(color_str, "blue") == 0) {
          color = 2;
        } else {
          // Handle invalid color
          valid_cubes = 0;
          break;
        }

        // Check if the count is valid for the color
        if (count > target_counts[color]) {
          valid_cubes = 0;
          break;
        }

        cube = strtok(NULL, ",");
      }

      if (!valid_cubes) {
        valid_lines = 0;
        break;
      }

      game_line = strtok(NULL, ";");
    }

    // Add the game ID to the list of valid games if all lines are valid
    if (valid_lines) {
      valid_games += game_id;
    }
  }

  // Close the file
  fclose(file);

  // Print the sum of the valid game IDs
  printf("%d\n", valid_games);

  return 0;
}
