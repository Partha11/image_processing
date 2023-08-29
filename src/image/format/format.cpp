#include "image/format/format.hpp"

const std::string Format::PPM = "ppm";
const std::string Format::PGM = "pgm";

std::string Format::getHeader(std::string format) {

    return format == PGM ? "P5" : "P6";
}