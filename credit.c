#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long card = get_long("Number: ");
    long temp = card;
    int digits = 0;
    int first_two;
    while (temp != 0)
    {
        temp /= 10;
        digits++;
        if (10 <= temp && temp < 100)
        {
            first_two = temp;
        }
    }

    temp = card / 10;
    int sum = 0;
    for (int i = 2; i <= digits; i += 2)
    {
        int num = temp % 10;
        num *= 2;
        if (num >= 10)
        {
            sum += num / 10;
            sum += num % 10;
        }
        else
        {
            sum += num;
        }
        temp /= 100;
    }

    temp = card;
    for (int i = 0; i < digits; i += 2)
    {
        int num = temp % 10;
        sum += num;
        temp /= 100;
    }
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (digits == 16 && (51 <= first_two && 55 >= first_two))
    {
        printf("MASTERCARD\n");
    }
    else if (digits == 15 && (34 == first_two || 37 == first_two))
    {
        printf("AMEX\n");
    }
    else if ((digits == 13 || digits == 16) && 4 == first_two / 10)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
