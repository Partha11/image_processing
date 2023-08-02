#include <stdio.h>
#include <stdlib.h>
#include "histogram.h"
#include "file_util.h"

int main() {

    Image *image;

    image = read("/home/partha/Codes/Cpp/DU/Image_Processing/sample.ppm", image);

    generateHistogram(image);

    write("/home/partha/Codes/Cpp/DU/Image_Processing/sample_image_mod.ppm", image);

    free(image);

    // const char* iFile = "image.pgm";
    // const char* oFile = "histo.txt";

    // int width, height, maxVal, isPPM;
    // unsigned char* imageData = readImage(iFile, &width, &height, &maxVal, &isPPM);

    // int histogram[256];
    // generateHistogram(imageData, width, height, histogram, isPPM);

    // saveHistogram(oFile, histogram);

    // free(imageData);

    // printf("Histogram generated successfully.\n");

    return 0;
}