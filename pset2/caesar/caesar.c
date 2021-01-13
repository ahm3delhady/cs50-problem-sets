#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void cipher(string plain_text, int key);

int main(int argc, string argv[])
{
    // check for command-Line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isdigit(argv[1][i]))
            {
                printf("Usage: ./caesar key\n");

                // return an exit code if one of the key chars is not a digit.
                return 1;
            }
        }
    }

    // convert the key from string to int.
    int key = atoi(argv[1]);

    string plain_text = get_string("plaintext: ");

    // cipher the text and get the final result.
    cipher(plain_text, key);

    return 0;
}

void cipher(string plain_text, int key)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plain_text); i < n; i++)
    {
        // check if the current char is alpha and an uppercase.
        if (isalpha(plain_text[i]) && isupper(plain_text[i]))
        {
            // map the char to and index, then make the formula (uppercase)
            printf("%c", ((plain_text[i] - 65 + key) % 26) + 65);
        }
        else if (isalpha(plain_text[i]) && islower(plain_text[i]))
        {
            // map the char to and index, then make the formula (lowercase)
            printf("%c", ((plain_text[i] - 97 + key) % 26) + 97);
        }
        else
        {
            // preserve the case for the non alpha chars.
            printf("%c", plain_text[i]);
        }
    }
    printf("\n");
}
