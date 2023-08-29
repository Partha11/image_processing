#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "image/image.hpp"
#include <vector>

class Algorithm {
    public:
        std::vector<std::vector<double>> dft(Image image);
};

#endif