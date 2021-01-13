#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // get the name of the user.
    string name = get_string("What is your name?\n");

    // display the name of the user.
    printf("hello, %s\n", name);
}