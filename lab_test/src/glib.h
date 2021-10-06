/**
 * @author:                     Syed Tajir Hasnain
 * @date:                       06/10/2021
 * @project_details:            A GLUT utils header file
 * @supported_operations:       1. initializes GLUT
 *                              2. draw line
 *                              3. draw circle
 *                              4. C Curve Algorithm
 *                              5. Flood fill
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
    class Color
    {
    public:
        float r, g, b;

        friend bool operator==(const Color &c1, const Color &c2)
        {
            return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b);
        }
    };

    Color get_pixel(GLint x, GLint y)
    {
        Color color;
        glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
        return color;
    }

    void init(int argc, char **argv)
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(500, 500);
        glutInitWindowPosition(100, 100);
        glutCreateWindow("Lab Test");
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

    void drawCircleMidPoint(geo::Point c, double r)
    {
        double x, y, p;

        x = 0, y = r;
        p = 1 - r;

        glBegin(GL_POINTS);

        while (x <= y)
        {
            glVertex2f(c.x + x, c.y + y);
            glVertex2f(c.x + y, c.y + x);
            glVertex2f(c.x - x, c.y + y);
            glVertex2f(c.x - y, c.y + x);
            glVertex2f(c.x + x, c.y - y);
            glVertex2f(c.x + y, c.y - x);
            glVertex2f(c.x - x, c.y - y);
            glVertex2f(c.x - y, c.y - x);

            if (p < 0)
            {
                p += 2 * x + 3;
                x++;
            }
            else
            {
                p += 2 * (x - y) + 5;
                x++, y--;
            }
        }

        glEnd();
    }

    // c curve
    void c_curve(geo::Point a, double length, double alpha, int n, geo::Point &_a)
    {
        if (n > 0)
        {
            int extra = 36;
            length = length / sqrt(2.0);
            c_curve(a, length, alpha + extra, n - 1, _a);
            a.x += length * cos((alpha + extra) * M_PI / 180);
            a.y += length * sin((alpha + extra) * M_PI / 180);
            c_curve(a, length, alpha - extra, n - 1, _a);
        }

        else
        {
            glBegin(GL_LINES);
            glVertex2d(a.x, a.y);

            _a.x = a.x + (length * cos(alpha * M_PI / 180));
            _a.y = a.y + (length * sin(alpha * M_PI / 180));
            glVertex2d(a.x + (length * cos(alpha * M_PI / 180)), a.y + (length * sin(alpha * M_PI / 180)));

            glEnd();
        }
    }

    void flood(int x, int y, Color old_col, Color new_col, Color paint_color)
    {
        Color color;
        color = get_pixel(x, y);

        if (color == new_col)
            return;
        if (color == old_col)
        {
            glBegin(GL_POINTS);
            glColor3f(paint_color.r, paint_color.g, paint_color.b);
            glVertex2i(x, y);
            glEnd();
            glFlush();

            flood(x + 1, y, old_col, new_col, paint_color);

            flood(x - 1, y, old_col, new_col, paint_color);

            flood(x, y + 1, old_col, new_col, paint_color);

            flood(x, y - 1, old_col, new_col, paint_color);
            return;
        }

        return;
    }

    // make sure to flush everytime
    inline void close()
    {
        glFlush();
    }
}