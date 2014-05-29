#include <GL/glut.h>

#include "render.h"
#include "model.h"

extern double G;
extern Object sun;
extern Object planet[1];
extern int selected_planet;

void render() {

    glPointSize(2.0);
    glBegin(GL_POINTS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2d(sun.x, sun.y);
        for(int i=0; i<NUM_PLANETS; i++) {
            if( i==selected_planet ) {
                glColor3f(1.0, 0.0, 0.0);
            }
            else {
                glColor3f(1.0, 1.0, 1.0);
            }
            glVertex2d(planet[i].x, planet[i].y);
        }
    glEnd();
}

