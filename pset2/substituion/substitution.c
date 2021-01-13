#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void encipher(string text, string key);

int main(int argc, string argv[])
{
    // check if the command-line arguments are only one argument.
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // get the key provided by the command-line arguments.
    string key = argv[1];

    // get the first char in the key.
    int current = (int)tolower(key[0]);

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        int next = (int)tolower(key[i]);
        // check if the key are only alpha chars.
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        // check if the length of the key is only 26
        else if (n != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        // check if the key does not contain any repeated charachters.
        if (current == next && i != 0)
        {
            printf("%i %i\n", current, next);
            printf("Key must not contain repeated characters.\n");
            return 1;
        }

        current = next;
    }

    // get the plain text from the user.
    string plain_text = get_string("plaintext: ");

    // get the final result.
    encipher(plain_text, key);

    return 0;

}

// encipher the text and get the cipher text at the end.
void encipher(string text, string key)
{
    int len_of_key = strlen(key);
    int key_mapped_to_indexes[len_of_key];

    // map the long key to alphabetic index (lowercase), then save it into array
    for (int i = 0; i < len_of_key; i++)
    {
        key_mapped_to_indexes[i] = tolower(key[i]);
    }

    // map every char in the plain text to the desired char in the mapped keys.
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            if (islower(text[i]))
            {
                printf("%c", tolower(key_mapped_to_indexes[text[i] - 97]));
            }
            else
            {
                printf("%c", toupper(key_mapped_to_indexes[text[i] - 65]));
            }
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}