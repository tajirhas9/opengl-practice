#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

float xs, ys, alp, len;
float xcheck, ycheck;

void c_curve(float x, float y, float lent, float alpha, int n)
{
    if(n>0)
    {
        int extra = 36;
        lent = lent/sqrt(2.0);
        c_curve(x, y, lent, alpha+extra, n-1);
        x += lent*cos((alpha+extra) * M_PI/180);
        y += lent*sin((alpha+extra) * M_PI/180);
        c_curve(x,y, lent, alpha-extra, n-1);
    }

    else
    {
        glBegin(GL_LINES);
        glVertex2d(x, y);
        xcheck = x + (lent*cos(alpha * M_PI/180));
        ycheck = y + (lent*sin(alpha * M_PI/180));
        glVertex2d(x + (lent*cos(alpha * M_PI/180)), y+(lent*sin(alpha * M_PI/180)));
        glEnd();
        glFlush();
    }
}

void display(void)
{
    int cnt = 0;
    c_curve(xs ,ys, len, alp, 1);
    while(cnt != 4)
    {
        alp += 72;
        c_curve(xcheck ,ycheck, len, alp, 1);
        cnt++;
    }
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

    printf("Enter starting co-ordinate: ");
    scanf("%f %f", &xs, &ys);
    printf("Enter rotation and length : ");
    scanf("%f %f", &alp, &len);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

return 0;
}
