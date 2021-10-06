#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include "glib.h"
using namespace std;

void Init()
{
    glClearColor(1.0, 1.0, 1.0, 0);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 640, 0, 480);
}

void drawStar()
{
    geo::Point a = geo::Point(260,160);
    geo::Point _a;
    double alpha = 0, length = 103;

    // Draw the rectangle
    int cnt = 0;
    glib::c_curve(a, length, alpha, 1, _a);
    while (cnt != 4)
    {
        alpha += 72;
        glib::c_curve(_a, length, alpha, 1, _a);
        cnt++;
    }

    glib::Color old_col = {1.0, 1.0, 1.0};
    glib::Color new_col = {0.0, 0.0, 0.0};
    glib::Color paint_color = {1.0, 1.0, 0.0};
    glib::flood(280,200, old_col, new_col, paint_color);
}

void draw_polygon(geo::Point c, double r) {
    // get the points

    std::vector<geo::Point> points;

    double numberOfCorners = 5.0;
    double angle = 0.0;
    double startAngle = M_PI_2;

    angle = startAngle;

    while( angle - startAngle < 2*M_PI ) {

        double x = r * cos(angle) + c.x; // transform polar coordinates to XY
        double y = r * sin(angle) + c.y;
        geo::Point point = geo::Point( x, y);
        points.push_back(point);

        double angleIncrease = (2.0*M_PI)/numberOfCorners;
        angle += angleIncrease;
    }

    for(int i = 0, j = 1; i < 5; ++i, j = (j+1)%5) {
        glBegin(GL_LINES);
        glVertex2i(points[i].x, points[i].y);
        glVertex2i(points[j].x, points[j].y);
        glEnd(); 
    }
}


void draw()
{
    //to clear the buffer
    glClear(GL_COLOR_BUFFER_BIT);
    
    
    glColor3f(1.0, 0.0, 0.0);
    glib::drawCircleMidPoint(geo::Point(320,240), 100);
    glColor3f(0.0, 0.0, 1.0);
    draw_polygon(geo::Point(320,240), 100);
    glColor3f(0.0, 0.0, 0.0);
    drawStar();

    glFlush();
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Lab Test");
    glutDisplayFunc(draw);
    Init();
    glutMainLoop();
}