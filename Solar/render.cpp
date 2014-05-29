#include <math.h>
#include <GL/glut.h>

#include "render.h"
#include "model.h"

extern double G;
extern Object sun;
extern Object planet[1];
extern int selected_planet;
extern int pov_planet;

void render() {

    glPushMatrix();
    glLoadIdentity();

    if( pov_planet ) {

        glTranslated( -planet[selected_planet].x, -planet[selected_planet].y, 0.0 );
        //glRotated(0.0, 0.0, 0.0, 1.0);
    }

    glColor3f(1.0, 1.0, 1.0);
    drawPlanet(sun.x, sun.y, true);
    for(int i=0; i<NUM_PLANETS; i++) {
        if( i==selected_planet ) {
            glColor3f(1.0, 0.0, 0.0);
        }
        else {
            glColor3f(1.0, 1.0, 1.0);
        }
        drawPlanet(planet[i].x, planet[i].y, false);
    }

    glPopMatrix();
}

void drawPlanet(double x, double y, bool sun) {

    const double R = 10.0;
    double a, px, py;
    
    if( sun ) {
        glBegin(GL_POLYGON);
    }
    else {
        glBegin(GL_LINE_LOOP);
    }
    for(a=0.0; a<2.0*M_PI; a+=0.1) {
        px = x + R * cos( a );
        py = y + R * sin( a );

        glVertex2d(px, py);
    }
    glEnd();

    // Place a point at 0 degree.
    if( sun ) {
        glColor3f(0.0, 0.0, 0.0);
        glPointSize(2.0);
    }
    else {
        glPointSize(1.0);
    }
    glBegin(GL_POINTS);
        glVertex2d(x + 0.5*R, y);
    glEnd();

    // Place a line at 90 degree
    if( ! sun ) {
        glBegin(GL_LINES);
            glVertex2d(x, y+R);
            glVertex2d(x, y+1.5*R);
        glEnd();
    }
}
