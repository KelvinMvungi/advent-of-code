#include <stdio.h>

int main () {
    FILE *file = fopen("cal_doc.txt", "r");

    char str[100];

    while (fgets(str, 100, file))
    {
        char first_digit, last_digit;

        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= "0" && str[i] <= "9") {
                first_digit = str[i];
                break;
            }
        }

        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= "0" && str[i] <= "9") 
            {
                last_digit = str[i];
            }
            
        }

        printf("First digit in str: %c\n", first_digit);
        printf("First digit in str: %c\n", last_digit);
    }
    
fclose(file);
return 0;
}