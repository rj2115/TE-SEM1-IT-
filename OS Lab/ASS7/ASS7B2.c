// NOTE : THIS IS THE SECOND PROCESS

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX 1000

int count_chars(char *str)
{

    int count = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '\n' && str[i] != ' ')
            count++;
        i++;
    }
    count++;
    return count;
}

int count_lines(char *str)
{

    int count = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '\n')
            count++;
        i++;
    }
    count++;

    return count;
}

int count_words(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ' || str[i] == '\n')
            count++;
        i++;
    }
    count++;

    return count;
}

