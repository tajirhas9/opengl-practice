/**
 * @author:                     Syed Tajir Hasnain
 * @date:                       15/09/2021
 * @lab_no:                     3
 * @assignment_title:           Draw an ellipse using DDA and Bresenham’s circle Algorithm.
 * 
 * @ps:                         1. `class Point` is declared in the "geometry.h" header file under `geo` namespace
 *                              2. DDA algorithm is implemented inside "glib.h" header file under `glib` namespace
 * 
 * @procedure:                  1. initialize glut with glib::init() function
 *                              2. input the 4 points [a,b,c,d] of the rectangle.
 *                              3. draw the line from a to b
 *                              4. draw line from b to c
 *                              5. draw line from c to d
 *                              6. draw line from d to a
 *                              7. end drawing and flush.
*/

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "glib.h"

void inputRectangle(geo::Point &a,
                    geo::Point &b,
                    geo::Point &c,
                    geo::Point &d)
{

    std::cout << "point a: ";
    std::cin >> a;

    std::cout << "point b: ";
    std::cin >> b;

    std::cout << "point c: ";
    std::cin >> c;

    std::cout << "point d: ";
    std::cin >> d;
}

void inputEllipse(geo::Point &c, double &a, double &b)
{
    std::cout << "center: ";
    std::cin >> c;

    std::cout << "major axis: ";
    std::cin >> a;

    std::cout << "minor axis: ";
    std::cin >> b;
}

void drawShape(void)
{
    geo::Point center;
    double a,b;

    // Draw the circle
    inputEllipse(center, a, b);
    glib::drawEllipseMidpoint(center, a, b);

    glib::close();
}

int main(int argc, char **argv)
{
    glib::init(argc, argv);

    glib::display(drawShape);

    return 0;
}