#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>

string get_valid_credit_card(long card_number);
bool checksum(long card_number);
int get_length_of_number(long card_number);
int get_first_two_digits(long card_number);
int get_first_digit(long card_number);
int get_last_digit(long card_number);

int main(void)
{
    // get the credit card number from the user.
    long number = get_long("Number: ");

    bool is_checksum_valid = checksum(number);

    // check if it's valid or not.
    if (is_checksum_valid)
    {
        string credit_card_name = get_valid_credit_card(number);
        printf("%s\n", credit_card_name);
    }
    else
    {
        printf("INVALID\n");
    }
}

bool checksum(long card_number)
{
    int first_to_last_digit = 0;
    int sum_first_to_last_digit = 0;
    int second_to_last_digit = 0;
    int sum_second_to_last_digit = 0;
    int final_sum = 0;
    while (card_number != 0)
    {
        // get the right-most digit
        first_to_last_digit = card_number % 10;

        // add it the sum of the numbers that weren't multiplied by zero
        sum_first_to_last_digit += first_to_last_digit;

        // remove that number to work with the 1th digit in second-to-last digits.
        card_number /= 10;

        // get that number and multiply it by zero.
        second_to_last_digit = (card_number % 10) * 2;

        // get its product's digits if this number was larger than 9, and add its digits.
        if (second_to_last_digit > 9)
        {
            int local_first_digit = get_first_digit(second_to_last_digit);
            int local_last_digit = get_last_digit(second_to_last_digit);
            sum_second_to_last_digit += local_first_digit + local_last_digit;
        }
        else
        {
            sum_second_to_last_digit += second_to_last_digit;
        }

        // remove that number from the credit card number.
        card_number /= 10;

    }

    final_sum = sum_first_to_last_digit + sum_second_to_last_digit;

    int final_sum_last_digit = get_last_digit(final_sum);

    if (final_sum_last_digit == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// get the final valid credit card number.
string get_valid_credit_card(long card_number)
{
    int length = get_length_of_number(card_number);
    int first_two_digits = get_first_two_digits(card_number);
    int first_digit = get_first_digit(card_number);

    if (length == 15 && (first_two_digits == 34 || first_two_digits == 37))
    {
        return "AMEX";
    }
    else if (length == 16 && (first_two_digits == 51 || first_two_digits == 52 || first_two_digits == 53 || first_two_digits == 54
                              || first_two_digits == 55))
    {
        return "MASTERCARD";
    }
    else if ((length == 13 || length == 16) && first_digit == 4)
    {
        return "VISA";
    }
    else
    {
        return "INVALID";
    }
}

// get the length of the credit card number.
int get_length_of_number(long card_number)
{
    int count = 0;
    while (card_number != 0)
    {
        card_number /= 10;
        count++;
    }
    return count;
}

// get the first two digits of the credit card number.
int get_first_two_digits(long card_number)
{
    long temp = card_number;

    while (temp >= 100)
    {
        temp /= 10;
    }

    return temp;
}

// get the first digit of the credit card number.
int get_first_digit(long card_number)
{
    long temp = card_number;

    while (temp >= 10)
    {
        temp /= 10;
    }

    return temp;
}

// get the last digit of a credit card number.
int get_last_digit(long card_number)
{
    return card_number % 10;
}