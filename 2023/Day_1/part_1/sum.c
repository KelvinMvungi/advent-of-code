#include <stdio.h>

int main () {
    FILE *file = fopen("cal_doc.txt", "r");

    char str[1000];
    int totalSum = 0;

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

        int first_digit_number = first_digit - '0';
        int last_digit_number = last_digit - '0';

        int two_digit_number = first_digit_number * 10 + last_digit_number;

        totalSum += two_digit_number;
    }
    printf("The total sum of two-digit number: %d\n", totalSum);
    
fclose(file);
return 0;
}