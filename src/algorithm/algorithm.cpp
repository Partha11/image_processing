#include <iostream>
#include <complex>
#include <cmath>
#include "algorithm/algorithm.hpp"

std::vector<std::vector<double>> Algorithm::dft(Image image) {

    std::cout << "dft" << std::endl;
    std::cout << image.dimension.width << " " << image.dimension.height << std::endl;

    std::vector<std::vector<double>> magnitudes(image.dimension.width, std::vector<double>(image.dimension.height, 0.0));

    for (int i = 0; i < image.dimension.height; i++) {
        
        for (int j = 0; j < image.dimension.width; j++) {

            std::complex<double> sum = 0.0;

            for (int k = 0; k < image.dimension.height; k++) {
        
                for (int l = 0; l < image.dimension.width; l++) {

                    double angle = 2 * M_PI * (((i * k) / (double) image.dimension.height) + ((j * l) / (double) image.dimension.width));
                    sum += std::complex<double>(image.pixels[k][l].r * cos(angle), -(image.pixels[k][l].r * sin(angle)));
                }
            }

            double magnitude = sqrt(sum.real() * sum.real() + sum.imag() * sum.imag());
            magnitudes[i][j] = 20 * log(magnitude);
        }
    }

    int halfRows = image.dimension.height / 2;
    int halfCols = image.dimension.width / 2;

    for (int i = 0; i < halfRows; i++) {
        
        for (int j = 0; j < halfCols; j++) {

            std::swap(magnitudes[i][j], magnitudes[i + halfRows][j + halfCols]);
            std::swap(magnitudes[i][j + halfCols], magnitudes[i + halfRows][j]);
        }
    }

    return magnitudes;
}