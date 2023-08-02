#include <stdio.h>
#include <stdlib.h>
#include "file_util.h"

void saveHistogram(const char* filename, int* histogram) {
    
    FILE* file = fopen(filename, "w");
    
    if (file == NULL) {

        printf("Error: Unable to create the file.\n");
        return;
    }

    for (int i = 0; i < 256; i++) {
        
        fprintf(file, "%d %d\n", i, histogram[i]);
    }

    fclose(file);
}

Image *read(const char *name, Image *image) {

    char buffer[16];
    int color;

    FILE *file;

    file = fopen(name, "rb");

    if (!file) {

        printf("File not found '%s'\n", name);
        exit(1);
    }

    if (!fgets(buffer, sizeof(buffer), file)) {
        
        printf("Can\'t read file '%s'\n", name);
        exit(1);
    }

    if ((buffer[0] != PPM && buffer[1] != '6')) {

        printf("Invalid image format\n");
        exit(1);
    }

    image = (Image *)malloc(sizeof(Image));

    if (image == NULL) {

        printf("Could not allocate memory.\n");
        exit(1);
    }

    skipComments(file);

    if (fscanf(file, "%d %d", &image->x, &image->y) != 2) {

        printf("Can't read image resolution data\n");
        exit(1);
    }

    if (buffer[0] != PPM && fscanf(file, "%d", &color) != 1) {

        printf("Invalid rgb data\n");
        exit(1);
    }

    image->data = (Pixel *)malloc(image->x * image->y * sizeof(Pixel));

    if (image->data == NULL) {

        printf("Could not allocate memory for pixels.\n");
        exit(1);
    }

    for (int i = 0; i < image->x * image->y; i++) {

        image->data[i].r = fgetc(file);
        image->data[i].g = fgetc(file);
        image->data[i].b = fgetc(file);
    }

    fclose(file);

    return image;
}

void write(const char *name, Image *image) {

    FILE *file;

    file = fopen(name, "wb");

    if (!file) {

        printf("Can\'t open file '%s'\n", name);
        exit(1);
    }

    fprintf(file, "P6\n# Testing Image Modification\n%d %d\n%d\n", image->x, image->y, RGB_COLOR);

    for (int i = 0; i < image->x * image->y; i++) {
        
        fputc(image->data[i].r, file);
        fputc(image->data[i].g, file);
        fputc(image->data[i].b, file);
    }

    // fwrite(image->data, (3 * image->x), image->y, file);
    fclose(file);
}

void skipComments(FILE *file) {

    int ch = fgetc(file);

    while (ch == '#') {

        while (ch != '\n' && ch != EOF) {

            ch = fgetc(file);
        }

        ch = fgetc(file);
    }

    fseek(file, -1, SEEK_CUR);
}