#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, file);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(header) == 0)
    {
        printf("Invalid WAV Format\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    BYTE buffer[block_size];
    fseek(file, 0, SEEK_END);

    long audio_size = ftell(file) - sizeof(WAVHEADER);
    int audio_block = (int) audio_size / block_size;

    for (int i = audio_block - 1; i >= 0; i--)
    {
        fseek(file, sizeof(WAVHEADER) + i * block_size, 0);
        fread(buffer, block_size, 1, file);
        fwrite(buffer, block_size, 1, output);
    }

    fclose(file);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    BYTE check[] = {'W', 'A', 'V', 'E'};
    for (int i = 0; i < 4; i++)
    {
        if (header.format[i] != check[i])
        {
            return 0;
        }
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    WORD bytesPerSample = header.bitsPerSample / 8;
    return (header.numChannels * bytesPerSample);
}