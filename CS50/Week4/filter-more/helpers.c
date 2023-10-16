#include "helpers.h"
#include <stdlib.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i =0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3;
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE image_copy[width];
        for (int j = 0; j < width; j++)
        {
            image_copy[j] = image[i][j];
        }
        for (int j = 0; j < width; j++)
        {
            image[i][j] = image_copy[width - 1 - j];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image_copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int upper_bound;
            int lower_bound;
            int left_bound;
            int right_bound;
            if ((i - 1) < 0)
            {
                upper_bound = i;
            }
            else
            {
                upper_bound = (i - 1);
            }
            if ((j - 1) < 0)
            {
                left_bound = j;
            }
            else
            {
                left_bound = (j - 1);
            }
            if ((i + 1) >= height)
            {
                lower_bound = i;
            }
            else
            {
                lower_bound = (i + 1);
            }
            if ((j + 1) >= width)
            {
                right_bound = j;
            }
            else
            {
                right_bound = (j + 1);
            }

            BYTE sum[3];
            sum[0] = 0x00;
            sum[1] = 0x00;
            sum[2] = 0x00;
            int count = 0;
            for (int m = upper_bound; m <= lower_bound; m++)
            {
                for (int n = left_bound; n <= right_bound; n++)
                {
                    count++;
                    sum[0] += (image_copy[m][n].rgbtRed);
                    sum[1] += (image_copy[m][n].rgbtGreen);
                    sum[2] += (image_copy[m][n].rgbtBlue);
                }
            }
            image[i][j].rgbtRed = sum[0] / count;
            image[i][j].rgbtGreen = sum[1] / count;
            image[i][j].rgbtBlue = sum[2] / count;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
