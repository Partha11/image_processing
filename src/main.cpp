#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <complex>
#include <GL/glut.h>
#include "algorithm/algorithm.hpp"
#include "image/image.hpp"

using namespace std;

using ul = unsigned long;
using ull = unsigned long long;

vector<vector<double>> magnitudes;

void display();

int main(int argc, char **argv) {

    glutInit(&argc, argv);

    Image image("files/generated.pgm");
    Algorithm algorithm;

    magnitudes = algorithm.dft(image);

    glutInitWindowSize(512, 512);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow("Magnitude Spectrum");

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

void display() {
    
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, static_cast<int>(magnitudes.size()), 0, static_cast<int>(magnitudes[0].size()));

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    double maxMagnitude = 0.0;

    for (int i = 0; i < magnitudes.size(); i++) {

        for (auto magnitude: magnitudes[i]) {

            maxMagnitude = std::max(maxMagnitude, magnitude);
        }
    }

    glBegin(GL_POINTS);
    
    for (int i = 0; i < magnitudes.size(); i++) {

        for (int j = 0; j < magnitudes[i].size(); j++) {

            auto magnitude = magnitudes[i][j];
            auto normalized = static_cast<float>(magnitude / maxMagnitude);

            glColor3f(normalized, normalized, normalized);
            glVertex2i(j, static_cast<int>(magnitudes[i].size()) - i);
        }
    }

    glEnd();
    glutSwapBuffers();
}