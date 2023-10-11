#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int n_start;
    do
    {
        n_start = get_int("Start size: ");
    }
    while (n_start < 9);

    // TODO: Prompt for end size
    int n_end;
    do
    {
        n_end = get_int("End size: ");
    }
    while (n_end < n_start);

    // TODO: Calculate number of years until we reach threshold
    int year = 0;
    int new_population = 0;
    int current_population = n_start;

    while (new_population < (n_end - n_start))
    {
        new_population += (current_population / 3 - current_population / 4);
        current_population = n_start + new_population;
        year++;
    }

    // TODO: Print number of years
    printf("Years: %i\n", year);
}
