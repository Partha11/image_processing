#ifndef DIMENSION_HPP
#define DIMENSION_HPP

class Dimension {
    public:
        int width;
        int height;
        Dimension() = default;
        Dimension(int w, int h): width(w), height(h) {}
};

#endif