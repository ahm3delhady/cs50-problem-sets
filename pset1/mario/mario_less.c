#include <cs50.h>
#include <stdio.h>

int get_valid_height();
void display_hashes(int height);



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

void display_hashes(int height)
{
    for (int i = 0; i < height; i++)
    {
        // display spaces
        for (int s = 0; s < height - (i + 1); s++)
        {
            printf(" ");
        }

        // display hashes
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // print new line after every row.
        printf("\n");
    }
}