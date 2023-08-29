#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>
#include "pixel/pixel.hpp"
#include "format/format.hpp"
#include "dimension/dimension.hpp"

class Image {
    public:
        int maxColor;
        std::string header;
        std::string format;
        std::vector<std::vector<Pixel>> pixels;
        Dimension dimension;
        Image() = default;
        Image(const std::string &path);
        void read(const std::string &path);
        void write(const std::string &path);
        void generate(Dimension dimension, std::string format);
};

#endif