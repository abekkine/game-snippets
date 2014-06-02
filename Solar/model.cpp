#include <stdio.h>
#include <math.h>

#include "model.h"

extern unsigned int step_mode;
extern unsigned int step_go;

double G = 1.0;
Object sun;
Object planet[1];
double dt = 0.1;
extern int selected_planet;

void model_init() {

    // Initialize sun.
    sun.x = 0.0;
    sun.y = 0.0;
    sun.m = 1000.0;
    sun.vx = 0.0;
    sun.vy = 0.0;
    sun.ax = 0.0;
    sun.ay = 0.0;
    sun.a = 0.0;
    sun.w = 3.0;

    // Initialize planets.
    // Planet #0
    planet[0].x = 100.0;
    planet[0].y = 0.0;
    planet[0].m = 10.0;
    planet[0].vx = 0.0;
    planet[0].vy = -3.0;
    planet[0].ax = 0.0;
    planet[0].ay = 0.0;
    planet[0].a = 0.0;
    planet[0].w = 2.5;

    // Planet #1
    planet[1].x = 200.0;
    planet[1].y = 0.0;
    planet[1].m = 10.0;
    planet[1].vx = 0.0;
    planet[1].vy = -2.0;
    planet[1].ax = 0.0;
    planet[1].ay = 0.0;
    planet[1].a = 30.0;
    planet[1].w = 8.0;

    // Planet #2
    planet[2].x = -300.0;
    planet[2].y = 0.0;
    planet[2].m = 10.0;
    planet[2].vx = 0.0;
    planet[2].vy = 2.0;
    planet[2].ax = 0.0;
    planet[2].ay = 0.0;
    planet[2].a = 50.0;
    planet[2].w = 1.0;
}

void model_update() {

    if( step_mode ) {
        if( step_go == 0 )
            return;
        else
            step_go = 0;
    }

    double dx, dy, r2, r, r3;

    for(int i=0; i<NUM_PLANETS; i++) {
        dx = sun.x - planet[i].x;
        dy = sun.y - planet[i].y;
        r2 = dx*dx + dy*dy;
        r = sqrt( r2 );
        r3 = r2 * r;
        // compute accelerations to sun.
        planet[i].ax = G * sun.m * dx / r3;
        planet[i].ay = G * sun.m * dy / r3;

        // compute velocity change...
        planet[i].vx += planet[i].ax * dt;
        planet[i].vy += planet[i].ay * dt;

        // compute position change...
        planet[i].x += planet[i].vx * dt;
        planet[i].y += planet[i].vy * dt;

        // update angle
        planet[i].a += planet[i].w * dt;

        if( i==selected_planet ) {
            double angle;
            angle = atan2(dy, dx) * 180 / M_PI;
            if( angle < 0.0 && angle >= -180.0 ) {
                angle += 360.0;
            }             
            //printf("a(% 3.0f)\n", angle);
        } 
    }
}
