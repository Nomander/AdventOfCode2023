#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

struct IndexInfo {
    int lowest_index;
    int highest_index;
    int lowest_number;
    int highest_number;
};

char* find_first_and_last_digit(char line[]);
int calculate_sum(char digit1, char digit2);
struct IndexInfo index_and_num(char *value);

int main()
{
    int sum = 0;

    FILE* file = fopen("day1.txt", "r");
    char line[100];

    while (fgets(line, sizeof(line), file))
    {
        int array_size = strlen(line);
        char string_numbers[array_size][2];

        char* result = find_first_and_last_digit(line);

        sum += calculate_sum(result[0], result[1]);
    }

    fclose(file);

    printf("%i", sum);
}

char* find_first_and_last_digit(char line[]) 
{
    char* number = (char*)malloc(2 * sizeof(char));
    struct IndexInfo index_info = index_and_num(line);

    bool first_digit = false;

    for (int i = 0; line[i] != '\0'; i++)
    {
        if (!first_digit) 
        {
            if (index_info.lowest_index == i)
            {
                number[0] = index_info.lowest_number + '0';
                first_digit = true;
            }
            else if (isdigit(line[i]))
            {
                number[0] = line[i];
                first_digit = true;
            }
        }
        if (i <= index_info.highest_index)
        {
            number[1] = index_info.highest_number + '0';
        }
        else if (isdigit(line[i]))
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

int get_number_value(const char* number)
{
    if (strcmp(number, "one") == 0) return 1;
    else if (strcmp(number, "two") == 0) return 2;
    else if (strcmp(number, "three") == 0) return 3;
    else if (strcmp(number, "four") == 0) return 4;
    else if (strcmp(number, "five") == 0) return 5;
    else if (strcmp(number, "six") == 0) return 6;
    else if (strcmp(number, "seven") == 0) return 7;
    else if (strcmp(number, "eight") == 0) return 8;
    else if (strcmp(number, "nine") == 0) return 9;
    else return 0;
}
struct IndexInfo index_and_num(char *value)
{
    char* numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    struct IndexInfo index_info = {-1, -1, -1, -1};

    int array_size = sizeof(numbers) / sizeof(numbers[0]);
    for (int i = 0; i < array_size; i++)
    {
        char* s = strstr(value, numbers[i]);

         while (s != NULL)
        {
            int index = (int)(s - value);

            if (index_info.lowest_index == -1 || index < index_info.lowest_index)
            {
                index_info.lowest_index = index;
                index_info.lowest_number = get_number_value(numbers[i]);
            }

            if (index > index_info.highest_index)
            {
                index_info.highest_index = index;
                index_info.highest_number = get_number_value(numbers[i]);
            }

            s = strstr(s + 1, numbers[i]);
        }
    }

    return index_info;
}
