#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int get_number_of_letters(string text);
int get_number_of_words(string text);
int get_number_of_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");

    int number_of_words = get_number_of_words(text);
    int number_of_letters = get_number_of_letters(text);
    int number_of_sentences = get_number_of_sentences(text);

    // get the average of letters per 100 words [used float to not truncated to floating point number].
    float avg_of_letters = ((float)number_of_letters / number_of_words) * 100;

    // get the average of sentences per 100 words.
    float avg_of_sentences = ((float)number_of_sentences / number_of_words) * 100;

    // calculate the Coleman-liau index.
    int index = round(0.0588 * avg_of_letters - 0.296 * avg_of_sentences - 15.8);

    // check for some constraints.
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// get the number of letters in a text.
int get_number_of_letters(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(tolower(text[i])))
        {
            count += 1;
        }
    }

    return count;
}

// get the number of words in a text.
int get_number_of_words(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            count += 1;
        }
    }

    // returns the count + 1, because there's no space after the last word.
    return count + 1;
}

// get the number of sentences in a text.
int get_number_of_sentences(string text)
{
    int count = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count += 1;
        }
    }

    return count;
}