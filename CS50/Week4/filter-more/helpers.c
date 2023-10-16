#include "helpers.h"
#include <math.h>
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

            WORD sumRed = 0;
            WORD sumGreen = 0;
            WORD sumBlue = 0;
            int count = 0;
            for (int m = upper_bound; m <= lower_bound; m++)
            {
                for (int n = left_bound; n <= right_bound; n++)
                {
                    count++;
                    sumRed += (image_copy[m][n].rgbtRed);
                    sumGreen += (image_copy[m][n].rgbtGreen);
                    sumBlue += (image_copy[m][n].rgbtBlue);
                }
            }
            image[i][j].rgbtRed = sumRed / count;
            image[i][j].rgbtGreen = sumGreen / count;
            image[i][j].rgbtBlue = sumBlue / count;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    RGBTRIPLE image_copy[height + 2][width + 2];
    for (int i = 0; i < height + 2; i++)
    {
        for (int j = 0; j < width + 2; j++)
        {
            if (i == 0 || i == (height + 1) || j == 0 || j == (width + 1))
            {
                image_copy[i][j].rgbtBlue = 0;
                image_copy[i][j].rgbtGreen = 0;
                image_copy[i][j].rgbtRed = 0;
            }
            else
            {
                image_copy[i][j] = image[i - 1][j - 1];
            }
        }
    }


    for (int i = 1; i < height + 1; i++)
    {
        for (int j = 1; j < width + 1; j++)
        {
            WORD sumRed = 0;
            WORD sumGreen = 0;
            WORD sumBlue = 0;

            for (int m = (i - 1); m <= i + 1; m++)
            {
                for (int n = (j - 1); n <= (j + 1); n++)
                {
                    sumRed += image_copy[m][n];
                    sumGreen += image_copy[m][n];
                    sumBlue += image_copy[m][n];
                }
            }

            
        }
    }


    return;
}
