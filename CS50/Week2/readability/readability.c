#include <cs50.h>
#include <math.h>
#include <stdio.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    int n_letters = count_letters(text);
    // printf("%i letters\n", n_letters);
    int n_words = count_words(text);
    // printf("%i words\n", n_words);
    int n_sentences = count_sentences(text);
    // printf("%i sentences\n", n_sentences);
    float L = n_letters * (100.0 / n_words);
    float S = n_sentences * (100.0 / n_words);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (round(index) < 1)
    {
        printf("Before Grade 1");
    }
    else if (round(index) >= 16)
    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i", (int) round(index));
    }
    printf("\n");
}

int count_letters(string text)
{
    int i = 0;
    int sum = 0;
    while (text[i] != '\0')
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            sum += 1;
        }
        i++;
    }
    return sum;
}

int count_words(string text)
{
    int isspace = 1;
    int count = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        if (text[i] != ' ')
        {
            if (isspace == 1)
            {
                count++;
                isspace = 0;
            }
        }
        else
        {
            isspace = 1;
        }
        i++;
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    int i = 0;
    while (text[i] != '\0')
    {
        if ((text[i] == '.') || (text[i] == '!') || (text[i] == '?'))
        {
            count++;
        }
        i++;
    }
    return count;
}
