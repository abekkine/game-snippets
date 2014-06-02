#include <math.h>
#include <GL/glut.h>

#include "render.h"
#include "model.h"

extern double G;
extern Object sun;
extern Object planet[1];
extern int selected_planet;
extern int pov_planet;
extern GLfloat light_position[4];

void render() {

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    if( pov_planet ) {
        // Apply reverse transforms to obtain point of view according to selected planet.
        glRotated(planet[selected_planet].a, 0.0, 0.0, -1.0);
        glTranslated( -planet[selected_planet].x, -planet[selected_planet].y, 0.0 );
    }

    // Needed to refresh light position after matrix operations.
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glDisable(GL_LIGHTING);
    glColor3f(1.0, 1.0, 1.0);
    drawPlanet(sun.x, sun.y, sun.a, true);
    glEnable(GL_LIGHTING);

    for(int i=0; i<NUM_PLANETS; i++) {
        if( i==selected_planet ) {
            glColor3f(1.0, 0.0, 0.0);
        }
        else {
            glColor3f(1.0, 1.0, 1.0);
        }
        drawPlanet(planet[i].x, planet[i].y, planet[i].a, false);
    }

    glPopMatrix();
}

void drawPlanet(double x, double y, double angle, bool sun) {

    const double R = 10.0;
    double a, px, py;
  
    glMatrixMode(GL_MODELVIEW); 
    glPushMatrix();

    glTranslated(x, y, 0.0);
    // Rotate planet/sun, etc.
    glRotated(angle, 0.0, 0.0, 1.0);
    angle = angle;
 
    if( sun ) {
        glBegin(GL_POLYGON);
    }
    else {
        glBegin(GL_LINE_LOOP);
    }
    for(a=0.0; a<2.0*M_PI; a+=0.1) {
        px = R * cos( a );
        py = R * sin( a );

        glNormal3d(px/R, py/R, 0.0);
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
        glNormal3d(1.0, 0.0, 0.0);
        glVertex2d(0.5*R, 0.0);
    glEnd();

    // Place a line at 90 degree
    if( ! sun ) {
        glBegin(GL_LINES);
            glNormal3d(0.0, 1.0, 0.0);
            glVertex2d(0.0, R);
            glNormal3d(0.0, 1.0, 0.0);
            glVertex2d(0.0, 1.5*R);
        glEnd();
    }

    glPopMatrix();
}
