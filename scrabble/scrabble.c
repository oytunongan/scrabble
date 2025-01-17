#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins! \n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins! \n");
    }
    else
    {
        printf("Tie! \n");
    }
    // printf("Player 1: %i and Player 2: %i\n", score1, score2);
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                      'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int length = strlen(word);
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 26; j++)
        {

            if (islower(word[i]) == 0)
            {
                char c = tolower(word[i]);
                word[i] = c;
            }
            if (word[i] == letters[j])
            {
                sum += POINTS[j];
            }
        }
    }
    return sum;
}
