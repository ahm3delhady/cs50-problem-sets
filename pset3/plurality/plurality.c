#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int count = 0;
    // sort the candidate from smallest to largest (selection_sort).
    for (int i = 0; i < candidate_count - 1; i++)
    {
        int smallest = i;

        for (int j = i + 1; j < candidate_count; j++)
        {
            if (candidates[j].votes < candidates[i].votes)
            {
                smallest = j;
            }

        }
        candidate temp = candidates[i];
        candidates[i] = candidates[smallest];
        candidates[smallest] = temp;
    }

    // get the last element since it is the largest number
    printf("%s\n", candidates[candidate_count - 1].name);

    // prints multiple winners in case of tie
    int f_candidate = candidate_count;
    for (int i = candidate_count - 2; i >= 0; i--)
    {
        if (candidates[f_candidate - 1].votes == candidates[i].votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }

}
