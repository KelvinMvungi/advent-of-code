#include <stdio.h>
#include <string.h>

int wordToNumber(char *word)
{
    if (strcmp(word, "one") == 0)
        return 1;
    else if (strcmp(word, "two") == 0)
        return 2;
    else if (strcmp(word, "three") == 0)
        return 3;
    else if (strcmp(word, "four") == 0)
        return 4;
    else if (strcmp(word, "five") == 0)
        return 5;
    else if (strcmp(word, "six") == 0)
        return 6;
    else if (strcmp(word, "seven") == 0)
        return 7;
    else if (strcmp(word, "eight") == 0)
        return 8;
    else if (strcmp(word, "nine") == 0)
        return 9;
        else return 0;
}

int main()
{
    FILE *file = fopen("cal_doc.txt", "r");

    char str[1000];
    int totalSum = 0;

    while (fscanf(file, "%999s", str) == 1)
    {
        char first_digit, last_digit;

        for (int i = 0; str[i] != '\0'; i++)
        {
            if ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z'))
            {
                first_digit = str[i];
                break;
            }
        }

        for (int i = strlen(str) -1; i >= 0; i--)
        {
            if ((str[i] >= '0' && str[i] <= '9') && (str[i] >= 'a' && str[i] <= 'z'))
            {
                last_digit = str[i];
                break;
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