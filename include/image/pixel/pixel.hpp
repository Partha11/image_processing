#ifndef PIXEL_H
#define PIXEL_H

class Pixel {
    public:
        unsigned char r;
        unsigned char g;
        unsigned char b;
        Pixel() = default;
        Pixel(unsigned char r) : r(r) {}
        Pixel(unsigned char r, unsigned char g): r(r), g(g) {}
        Pixel(unsigned char r, unsigned char g, unsigned char b): r(r), g(g), b(b) {}
};

#endif