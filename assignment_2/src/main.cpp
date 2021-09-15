/**
 * @author:                     Syed Tajir Hasnain
 * @date:                       15/09/2021
 * @assignment_no:              2
 * @assignment_title:           Draw a shape using DDA and Bresenham’s circle Algorithm.
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

void inputCircle(geo::Point &c, double &r)
{
    std::cout << "center: ";
    std::cin >> c;

    std::cout << "radius: ";
    std::cin >> r;
}

void drawShape(void)
{
    geo::Point a, b, c, d, center;
    double radius;

    // Draw the rectangle
    inputRectangle(a, b, c, d);
    glib::drawLineDDA(a, b);
    glib::drawLineDDA(b, c);
    glib::drawLineDDA(c, d);
    glib::drawLineDDA(d, a);

    // Draw the circle
    inputCircle(center, radius);
    glib::drawCircleBresenham(center, radius);

    glib::close();
}

int main(int argc, char **argv)
{
    glib::init(argc, argv);

    glib::display(drawShape);

    return 0;
}