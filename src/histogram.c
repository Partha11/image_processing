#include <stdio.h>
#include <stdlib.h>
#include "histogram.h"

void generateHistogram(Image *image) {
 
    int dataSize = image->x * image->y;
    int histogram[256] = {0};

    for (int i = 0; i < dataSize; i++) {

        unsigned char intensity = (image->data[i].r + image->data[i].g + image->data[i].b) / 3;
        histogram[intensity]++;
    }

    FILE* file = fopen("/home/partha/Codes/Cpp/DU/Image_Processing/histogram.txt", "w");
    
    if (file == NULL) {
    
        printf("Unable to open histogram file\n");
        exit(1);
    }

    for (int i = 0; i < 256; i++) {
    
        fprintf(file, "%d: %d\n", i, histogram[i]);
    }

    fclose(file);
}