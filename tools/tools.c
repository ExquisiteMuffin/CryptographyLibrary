#include <stdio.h>

int length(char *string)
{   
    int size = 0;
    for (int i = 0; i )
}

int len_digit(int num)
{
    int count = 0;
    while (num != 0)
    {
        num -= num % 10;
        num /= 10;
        count++;
    }
    return count;
}

char *to_string(int num)
{
    int length = len_digit(num);
    for (int i = length, int j = 1; i >= 0; i++)
}