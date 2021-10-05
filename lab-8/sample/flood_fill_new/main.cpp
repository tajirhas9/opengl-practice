#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <bits/stdc++.h>
#include <wingdi.h>
using namespace std;

int xs, ys, maj, minor;
int xline, yline;

struct Color
{
    GLfloat r;
    GLfloat g;
    GLfloat b;
};

Color getpix(GLint x, GLint y)
{
    Color color;
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
    return color;
}

void flood_fill(float x, float y, Color fill_col, Color orig_col)
{
    Color check;
    check = getpix(x, y);
    if (check.r == orig_col.r && check.g == orig_col.g && check.b == orig_col.b)
    {
        glBegin(GL_POINTS);
        glColor3f(fill_col.r, fill_col.g, fill_col.b);
        glVertex2f(x, y);
        glEnd();
        flood_fill(x + 1, y, fill_col, orig_col);
        flood_fill(x, y + 1, fill_col, orig_col);
        flood_fill(x - 1, y, fill_col, orig_col);
        flood_fill(x, y - 1, fill_col, orig_col);
    }
    glFlush();
}

/*void line(int x11, int z11, int x22, int y22)
{
    int i, xmin, ymin, xmax, ymax, inc1, d, inc2;
    float m, dy, dx;
    dx = x22-x11;
    dx = abs(dx);
    dy = y22-z11;
    dy = abs(dy);
    m = dy/dx;
    if(m<1)
    {
        inc1= 2*dy;
        d= inc1-dx;
        inc2= 2* (dy-dx);
        xmin = min(x11, x22);
        xmax = max(x11, x22);
        if(xmin==x11)
        {
            ymin=z11;
        }
        else if(xmin==x22)
        {
            ymin=y22;
        }
        glBegin(GL_POINTS);
        for(i=xmin; i<=xmax; i++)
        {
            glVertex2i(xmin,ymin);
            xmin++;
            if(d<0)
                d+= inc1;
            else if(d>=0)
            {
                d+= inc2;
                ymin+= 1;
            }
        }
    }
    if(m>=1)
    {
        inc1= 2*dx;
        d = inc1 - dy;
        inc2= 2* (dx-dy);
        ymin = min(z11,y22);
        ymax = max(z11,y22);
        if(ymin==z11)
        {
            xmin=x11;
        }
        else if(ymin==y22)
        {
            xmin=x22;
        }
        glBegin(GL_POINTS);
        for(i = ymin; i<=ymax; i++)
        {
            glVertex2i(xmin,ymin);
            ymin++;
            if(d<0)
                d+= inc1;
            else
            {
                xmin+= 1;
                d+= inc2;
            }

        }
    }
    glEnd();
    glFlush();
}
*/

void display(void)
{
    /*int x =0, p, aa, bb, aa2, bb2, fx = 0, fy, y=minor;
    int xvalue[10000];
    aa = maj * maj;
    bb = minor*minor;
    aa2 = 2*aa;
    bb2 = 2*bb;
    fy = aa2*minor;

    p= bb- (aa*minor) + (0.25*aa);
    while(fx<fy)
    {
        glBegin(GL_POINTS);
        glVertex2i(xs + x, ys + y);
        glVertex2i(xs - x, ys + y);
        glVertex2i(xs - x, ys - y);
        glVertex2i(xs + x, ys - y);
        glEnd();
        x++;
        fx+= bb2;
        if(p<0)
            p+= fx+bb;
        else
        {
            y--;
            fy-=aa2;
            p+=fx+bb-fy;
        }
        xvalue[x] = y;
    }

    xline = x - (x/4);
    yline = xvalue[xline];
    line(xs + xline, ys + yline, xs - xline, ys + yline);
    line(xs - xline, ys + yline, xs - xline, ys - yline);
    line(xs - xline, ys - yline, xs + xline, ys - yline);
    line(xs + xline, ys + yline, xs + xline, ys - yline);

    p = (bb*(x+0.5)*(x+0.5)) + (aa*(y-1)*(y-1)) - (aa*bb);
    while(y>0)
    {
        glBegin(GL_POINTS);
        glVertex2i(xs + x, ys + y);
        glVertex2i(xs - x, ys + y);
        glVertex2i(xs - x, ys - y);
        glVertex2i(xs + x, ys - y);
        glEnd();
        y--;
        fy-= aa2;
        if(p>=0)
            p-=fy+aa;
        else
        {
            x++;
            fx+=bb2;
            p+=fx-fy+aa;
        }

    }*/

    float xflood, yflood;
    xflood = xs;
    yflood = ys;
    Color a, target;
    a = getpix(xflood, yflood);
    target.r = 0;
    target.g = 0;
    target.b = 255;
    cout << a.r << a.g << a.b;
    flood_fill(xflood, yflood, target, a);
    glFlush();
}

void init(void)
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 500);
}
int main(int argc, char **argv)
{

    printf("Enter centre co-ordinate: ");
    scanf("%d%d", &xs, &ys);
    printf("Enter major axis and minor axis: ");
    scanf("%d %d", &maj, &minor);
    xs = xs + 250;
    ys = ys + 250;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
