#include <cs50.h>
#include <stdio.h>

int get_valid_height();
void display_hashes(int height);
void display_spaces(int height, int current_row);
void display_right_pyramid(int height, int current_row);
void display_left_pyramid(int height, int current_row);



int main(void)
{
    int height = get_valid_height();
    display_hashes(height);
}

// get the valid height between 1 and 8 inclusive
int get_valid_height()
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    return height;
}

// print the all hashes.
void display_hashes(int height)
{
    for (int i = 0; i < height; i++)
    {
        display_spaces(height, i);

        display_right_pyramid(height, i);

        // print two spaces between the two pyramids.
        printf("  ");

        display_left_pyramid(height, i);

        // print a space after every row.
        printf("\n");
    }
}

// display spaces
void display_spaces(int height, int current_row)
{
    for (int i = 0; i < height - (current_row + 1); i++)
    {
        printf(" ");
    }
}

// print the right hand pyramid
void display_right_pyramid(int height, int current_row)
{
    for (int i = 0; i < current_row + 1; i++)
    {
        printf("#");
    }
}

// print the left hand pyramid
void display_left_pyramid(int height, int current_row)
{
    for (int i = 0; i < current_row + 1; i++)
    {
        printf("#");
    }
}