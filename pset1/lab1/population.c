#include <cs50.h>
#include <stdio.h>

int get_start_size();
int get_end_size(int start_size);

int main(void)
{
    // TODO: Prompt for start size
    int start_size = get_start_size();

    // TODO: Prompt for end size
    int end_size = get_end_size(start_size);

    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (start_size < end_size)
    {
        start_size += (int)(start_size / 3) - (int)(start_size / 4);
        years += 1;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}

int get_start_size()
{
    int start_size;
    do
    {
        start_size = get_int("Start size: ");
    }
    while (start_size < 9);

    return start_size;
}

int get_end_size(int start_size)
{
    int end_size;
    do
    {
        end_size = get_int("End size: ");
    }
    while (end_size < start_size);

    return end_size;
}