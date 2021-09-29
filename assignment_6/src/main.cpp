#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "glib.h"
using namespace std;

void input(geo::Point &a, double &alpha, double &length)
{
    cout << "Enter starting co-ordinate: ";
    cin >> a;
    cout << "Enter rotation and length : ";
    cin >> alpha >> length;
}

void drawShape(void)
{
    geo::Point a, _a;
    double alpha, length;

    // Draw the rectangle
    input(a, alpha, length);
    cout << a << " " << alpha << " " << length << endl;
    int cnt = 0;
    glib::c_curve(a, length, alpha, 1, _a);
    while (cnt != 4)
    {
        alpha += 72;
        glib::c_curve(_a, length, alpha, 1, _a);
        cnt++;
    }

    glib::close();
}

int main(int argc, char **argv)
{
    glib::init(argc, argv);
    glib::display(drawShape);

    return 0;
}