#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int target_counts[3] = {12, 13, 14}; 

  FILE *file = fopen("aoc-d2p1.txt", "r");
  if (file == NULL) {
    printf("Error opening file");
    return 1;
  }

  char line[1024];
  int valid_games = 0;
  while (fgets(line, sizeof(line), file)) {
    if (strlen(line) == 1) {
      continue;
    }

    char *game_id_str = strtok(line, ":");
    char *game_str = strtok(NULL, "\n");
    int game_id = atoi(strtok(game_id_str, " "));

    int valid_lines = 1;
    char *game_line = strtok(game_str, ";");
    while (game_line) {
      int valid_cubes = 1;
      char *cube = strtok(game_line, ",");
      while (cube) {
        char *color_str = strtok(cube, " ");
        int count = atoi(strtok(NULL, " "));

        int color;
        if (strcmp(color_str, "red") == 0) {
          color = 0;
        } else if (strcmp(color_str, "green") == 0) {
          color = 1;
        } else if (strcmp(color_str, "blue") == 0) {
          color = 2;
        } else {
          valid_cubes = 0;
          break;
        }

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

    if (valid_lines) {
      valid_games += game_id;
    }
  }

  fclose(file);

  printf("%d\n", valid_games);

  return 0;
}
