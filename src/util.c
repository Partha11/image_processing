#include "util.h"

int compare(char *first, char *second) {

    while (*first == *second) {

        if (*first == '\0' || *second == '\0') {

            break;
        }

        first++;
        second++;
    }

    return (*first == '\0' && *second == '\0') ? 1 : 0;
}