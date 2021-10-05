/**
 * @author:                     Syed Tajir Hasnain
 * @date:                       05/10/2021
 * @project_details:            A GLUT utils header file
 * @supported_operations:       1. initializes GLUT
 *                              2. Koch Curve
*/

#include <GL/glut.h>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "geometry.h"

namespace glib
{
    /**
     * 
     * @utility: Initializes GLUT library
     * @params: takes the params supplied in the main() function
     * 
    */
    void init(int argc, char **argv)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("");
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0, 0, 0, 0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(-100, 100, -100, 100);
    }
    /**
     * @utility: takes the drawing callback and executes it
     */
    void display(void (*callback)(void))
    {
        glutDisplayFunc(callback);
        glutMainLoop();
    }

    /**
     * @algorithm: Koch Curve Algorithm
    */

    void koch_curve(double x, double y, double lent, double alpha, int n, double &_x, double &_y )
    {
        if (n > 0)
        {
            lent = lent / 3;
            koch_curve(x, y, lent, alpha, n - 1, _x, _y);
            x += lent * cos(alpha * M_PI / 180);
            y += lent * sin(alpha * M_PI / 180);
            koch_curve(x, y, lent, alpha - 60, n - 1, _x, _y);
            x += lent * cos((alpha - 60) * M_PI / 180);
            y += lent * sin((alpha - 60) * M_PI / 180);
            koch_curve(x, y, lent, alpha + 60, n - 1, _x, _y);
            x += lent * cos((alpha + 60) * M_PI / 180);
            y += lent * sin((alpha + 60) * M_PI / 180);
            koch_curve(x, y, lent, alpha, n - 1, _x, _y);
        }

        else
        {
            glBegin(GL_LINES);
            glVertex2f(x, y);
            _x = x + (lent * cos(alpha * M_PI / 180));
            _y = y + (lent * sin(alpha * M_PI / 180));
            glVertex2f(x + (lent * cos(alpha * M_PI / 180)), y + (lent * sin(alpha * M_PI / 180)));
            glEnd();
            glFlush();
        }
    }


    // make sure to flush everytime
    inline void close()
    {
        glFlush();
    }
}