#ifndef FILE_UTIL_H
#define FILE_UTIL_H

#include <stdio.h>

#define RGB_COLOR 255

typedef struct {

    unsigned char r;
    unsigned char g;
    unsigned char b;

} Pixel;

typedef struct {

    int x;
    int y;

    Pixel *data;

} Image;

enum Format {

    PPM = 'P', PGM = 'G'
};

Image *read(const char *name, Image *image);
void write(const char *name, Image *image);

void skipComments(FILE *file);

void saveHistogram(const char *filename, int *histogram);

#endif