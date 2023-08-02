#include <stdio.h>
#include <stdlib.h>
#include "image_reader.h"

unsigned char* readImage(const char* filename, int* width, int* height, int* maxVal, int* isPPM) {
    
    FILE* file = fopen(filename, "rb");

    if (file == NULL) {
    
        printf("Error: Unable to open the file.\n");
        return NULL;
    }

    char format[3];
    fscanf(file, "%s", format);
    
    if (format[0] == 'P' && format[1] == '6') {
    
        *isPPM = 1;
    
    } else if (format[0] == 'P' && format[1] == '5') {
    
        *isPPM = 0;
    
    } else {
    
        printf("Error: Unsupported file format.\n");
        return NULL;
    }

    fscanf(file, "%d %d", width, height);
    fscanf(file, "%d", maxVal);
    fgetc(file);

    int dataSize = (*width) * (*height);
    unsigned char* data = (unsigned char*)malloc(dataSize * sizeof(unsigned char));

    fread(data, sizeof(unsigned char), dataSize, file);
    fclose(file);

    return data;
}