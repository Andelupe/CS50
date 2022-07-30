#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check(string cipher);
void convert(char test, string cipher);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (check(argv[1]) == 1)
    {
        printf("Error: Invalid Cipher\n");
        return 1;
    }

    string take = get_string("plaintext:  ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(take); i < n; i++)
    {
        convert(take[i], argv[1]);
    }
    printf("\n");
    return 0;
}

int check(string cipher)
{
    int test[26] = { 0 };
    for (int i = 0, n = strlen(cipher); i < n; i++)
    {
        char temp = tolower(cipher[i]);
        if (temp < 'a' || temp > 'z')
        {
            return 1;
        }
        else if (test[temp - 97] == 1)
        {
            return 1;
        }
        test[temp - 97] = 1;
    }
    return 0;
}

void convert(char test, string cipher)
{
    if ('a' <= test  && test <= 'z')
    {
        printf("%c", tolower(cipher[test - 97]));
    }
    else if ('A' <= test && test <= 'Z')
    {
        printf("%c", toupper(cipher[test - 65]));
    }
    else
    {
        printf("%c", test);
    }
}
