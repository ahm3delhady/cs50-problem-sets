#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_valid_amount_of_dollars();
int get_change_owed(int cents);

int main(void)
{
    // get the amount of dollars.
    float dollars = get_valid_amount_of_dollars();

    // convert the dollars to cents and round it to the nearest integer.
    int cents = round(dollars * 100);

    // get the final change owed by user.
    int coins = get_change_owed(cents);

    // display the final coins that used.
    printf("%i\n", coins);
}

float get_valid_amount_of_dollars()
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);

    return dollars;
}

int get_change_owed(int cents)
{
    int counter = 0;

    // get the most coins possible by quarters.
    while (cents >= 25)
    {
        cents -= 25;
        counter += 1;
    }

    // get the most coins possible by dimes.
    while (cents >= 10)
    {
        cents -= 10;
        counter += 1;
    }

    // get the most coins possible by nickles.
    while (cents >= 5)
    {
        cents -= 5;
        counter += 1;
    }

    // get the most coins possible by pennies.
    while (cents >= 1)
    {
        cents -= 1;
        counter += 1;
    }

    return counter;
}