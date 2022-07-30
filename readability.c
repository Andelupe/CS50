#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    float L = 100.0 * count_letters(text) / count_words(text);
    float S = 100.0 * count_sentences(text) / count_words(text);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        int test = (int) index;
        if (index - test >= 0.5)
        {
            printf("Grade cd
            %i\n", (int) index + 1);
        }
        else
        {
            printf("Grade %i\n", (int) index);
        }
    }
}

int count_letters(string text)
{
    int rslt = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (('a' <= text[i] && text[i] <= 'z') || ('A' <= text[i] && text[i] <= 'Z'))
        {
            rslt++;
        }
    }
    return rslt;
}

int count_words(string text)
{
    int rslt = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            rslt++;
        }
    }
    if (text[strlen(text) - 1] != ' ')
    {
        rslt++;
    }
    return rslt;
}

int count_sentences(string text)
{
    int rslt = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            rslt++;
        }
    }
    return rslt;
}
