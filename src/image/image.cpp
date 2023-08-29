#include "image/image.hpp"
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

Image::Image(const std::string &path) {

    if (!path.empty()) {

        this->read(path);
    }
}

void Image::read(const std::string &path) {

    std::ifstream file(path, std::ios::binary);

    if (!file.is_open()) {

        std::cout << "Can't open file!" << std::endl;
        exit(1);
    }

    char buffer[3];

    file.read(buffer, 2);
    buffer[2] = '\0';

    header = buffer;

    if (header == "P5") {

        format = Format::PGM;

    } else if (header == "P6") {

        format = Format::PPM;

    } else {

        std::cout << "Invalid file format!!" << std::endl;
        exit(1);
    }

    // char space;

    file >> dimension.width >> dimension.height >> maxColor;

    file >> std::noskipws;
    file >> std::skipws;

    if (format == Format::PPM) {

        for (int i = 0; i < dimension.width; i++) {

            std::vector<Pixel> pixel;

            for (int j = 0; j < dimension.height; j++) {

                Pixel p;

                file.read((char *)&p.r, sizeof(p.r));
                file.read((char *)&p.g, sizeof(p.g));
                file.read((char *)&p.b, sizeof(p.b));

                pixel.push_back(p);
            }

            pixels.push_back(pixel);
        }

    } else {

        for (int i = 0; i < dimension.width; i++) {

            std::vector<Pixel> pixel;

            for (int j = 0; j < dimension.height; j++) {

                Pixel p;

                file.read((char *)&p.r, sizeof(p.r));
                pixel.push_back(p);
            }

            pixels.push_back(pixel);
        }
    }

    file.close();
}

void Image::write(const std::string &path) {

    std::ofstream file(path, std::ios::binary);

    file << header << std::endl;
    file << dimension.width << " " << dimension.height << std::endl;
    file << maxColor << std::endl;

    if (format == Format::PPM) {

        for (int i = 0; i < dimension.width; i++) {

            for (int j = 0; j < dimension.height; j++) {

                file.write((char *)&this->pixels[i][j].r, sizeof(this->pixels[i][j].r));
                file.write((char *)&this->pixels[i][j].g, sizeof(this->pixels[i][j].g));
                file.write((char *)&this->pixels[i][j].b, sizeof(this->pixels[i][j].b));
            }
        }

    } else {

        for (int i = 0; i < dimension.width; i++) {

            for (int j = 0; j < dimension.height; j++) {

                file.write((char *)&this->pixels[i][j].r, sizeof(this->pixels[i][j].r));
            }
        }
    }

    file.close();
}

void Image::generate(Dimension dimension, std::string format) {

    this->maxColor = 255;
    this->format = format;
    this->dimension = dimension;

    this->header = Format::getHeader(format);

    int radius = 50;
    int centerX = this->dimension.width / 2;
    int centerY = this->dimension.height / 2;

    for (int i = 0; i < this->dimension.width; i++) {

        std::vector<Pixel> pixel;

        for (int j = 0; j < this->dimension.height; j++) {
 
            unsigned char r = '0';
            unsigned char g = '0';
            unsigned char b = '0';

            double distance = std::sqrt(std::pow(i - centerX, 2) + std::pow(j - centerY, 2));

            if (distance <= radius) {

                pixel.push_back(Pixel(255, 255, 255));

            } else {

                pixel.push_back(Pixel(r, g, b));
            }
        }

        pixels.push_back(pixel);
    }
}