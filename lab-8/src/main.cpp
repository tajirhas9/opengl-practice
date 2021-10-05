#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>
#include "glib.h"
using namespace std;

void koch_curve(double x, double y,double len,double alpha, int n)
{
    if(n > 0)
    {
        len = len / 3;
        koch_curve(x, y, len, alpha, n - 1);
        x = x + len * cos(alpha);
        y = y + len * sin(alpha);
        koch_curve(x, y, len, alpha - 60, n - 1);
        x = x + len * cos(alpha - 60);
        y = y + len * sin(alpha - 60);
        koch_curve(x, y, len, alpha + 60, n - 1);
        x = x + len * cos(alpha + 60);
        y = y + len * sin(alpha + 60);
        koch_curve(x, y, len, alpha, n - 1);
    }
    else glib::drawLineDDA(geo::Point(x,y), geo::Point(x + len * cos(alpha), y + len * sin(alpha)));
}

void input(double &x, double &y,double &len,double &alpha, int &n) {
    cout << "Enter starting co-ordinate: ";
    cin >> x >> y;
    cout << "Enter alpha, length and order : ";
    cin >> alpha >> len >> n;
}

void drawShape() {
    double x, y, len, alpha;
    int n;
    input(x,y,len,alpha,n);
    koch_curve(x,y,len,alpha, n);
}
int main(int argc, char **argv)
{

    glib::init(argc, argv);
    glib::display(drawShape);
    return 0;
}