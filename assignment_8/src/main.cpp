#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "glib.h"
using namespace std;

void input(double &x, double &y, double &alpha, double &length)
{
    printf("Enter starting co-ordinate: ");
    scanf("%lf %lf", &x, &y);
    printf("Enter rotation and length : ");
    scanf("%lf %lf", &alpha, &length);
}

void drawShape(void)
{
    double x, y, alpha, length;
    double _x, _y;
    int cnt = 0;

    input(x, y, alpha, length);

    _x = x;
    _y = y;

    while (cnt != 3)
    {
        glib::koch_curve(_x, _y, length, alpha, 1, _x, _y);
        alpha += 120;
        cnt++;
    }
}

int main(int argc, char **argv)
{
    glib::init(argc, argv);
    glib::display(drawShape);

    return 0;
}
