#ifndef FORMAT_HPP
#define FORMAT_HPP

#include <iostream>
#include <string>

class Format {
    public:
        static const std::string PPM;
        static const std::string PGM;
        static std::string getHeader(std::string format);
};

#endif