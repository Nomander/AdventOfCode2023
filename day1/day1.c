#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

char* find_first_and_last_digit(char line[]);
int calculate_sum(char digit1, char digit2);
char* convert_numbers_to_digits(char *value);

int main()
{
    int sum = 0;
    char* example_string[] = {"1abc2", "pqr3stu8vwx", "a1b2c3d4e5f", "treb7uchet"};
    int array_size = sizeof(example_string) / sizeof(example_string[0]);
    char string_numbers[array_size][2];

    for (int i = 0; i < array_size; i++)
    {
        char* result = find_first_and_last_digit(example_string[i]);

        sum += calculate_sum(result[0], result[1]);
    }

    printf("%i", sum);
}

char* find_first_and_last_digit(char line[]) 
{
    char* number = (char*)malloc(2 * sizeof(char));

    bool first_digit = false;

    for (int i = 0; line[i] != '\0'; i++)
    {
        if (isdigit(line[i]) && !first_digit)
        {
            number[0] = line[i];
            first_digit = true;
        }
        if (isdigit(line[i]))
        {
            number[1] = line[i];
        }
    }
    return number;
}

int calculate_sum(char digit1, char digit2)
{
    return (digit1 - '0') * 10 + (digit2 - '0');
}
