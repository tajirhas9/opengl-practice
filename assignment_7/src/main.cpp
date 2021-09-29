#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<bits/stdc++.h>
#include <vector>
#include "glib.h"
using namespace std;

void input(geo::Point &x, double &alpha, double &length) 
{
    cout << "Enter starting co-ordinate: ";
    cin >> x;
    cout << "Enter rotation and length : ";
    cin >> alpha >> length;
}

void drawShape()
{

    int cnt2 = 0;
    vector<int> a(3) , b(3);
    double alpha, length;
    geo::Point x, _x;

    input(x, alpha, length);

    int cnt = 0;
    glib::c_curve(x, length, alpha, 1, cnt2, a,b,_x);
    while(cnt != 4)
    {
        alpha += 72;
        glib::c_curve(_x, length, alpha, 1, cnt2, a,b,_x);
        cnt++;
    }
    glib::gasket(a[0] , b[0], a[1], b[1], a[2], b[2], 1);

    glib::close();
}

void init(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0,0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

int main(int argc, char** argv){

    
    glib::init(argc, argv);
    glib::display(drawShape);
    return 0;
}