#include <stdio.h>

int main () {
    FILE *file = fopen("cal_doc.txt", "r");

    char str[1000];

    while (fscanf(file, "%999s", str) == 1)
    {
        char first_digit, last_digit;

        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= '0' && str[i] <= '9') {
                first_digit = str[i];
                break;
            }
        }

        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= '0' && str[i] <= '9') 
            {
                last_digit = str[i];
            }
            
        }

        printf("First digit in str: %c\n", first_digit);
        printf("Last digit in str: %c\n", last_digit);
    }
    
fclose(file);
return 0;
}