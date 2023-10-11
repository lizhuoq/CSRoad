#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long number = get_long("Number: ");
    long remain_digits = number;
    int size = 0;
    int first_digit;
    int second_digit;
    int checksum = 0;

    while (remain_digits > 0)
    {
        int digit = remain_digits % 10;
        remain_digits = remain_digits / 10;
        if (size > 0)
        {
            second_digit = first_digit;
        }
        first_digit = digit;
        if (size % 2 == 0)
        {
            checksum += digit;
        }
        else
        {
            checksum += (digit * 2 / 10 + digit * 2 % 10);
        }
        size++;
    }

    if (checksum % 10 != 0)
    {
        printf("INVALID\n");
    }

    else if (size == 15 && first_digit == 3 && (second_digit == 4 || second_digit == 7))
    {
        printf("AMEX\n");
    }

    else if (size == 16 && first_digit == 5 && (second_digit >= 1 && second_digit <= 5))
    {
        printf("MASTERCARD\n");
    }

    else if ((size == 13 || size == 16) && first_digit == 4)
    {
        printf("VISA\n");
    }

    else
    {
        printf("INVALID\n");
    }
}