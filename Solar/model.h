#ifndef MODEL_H
#define MODEL_H

#define NUM_PLANETS 3

typedef struct {

    // Position
    double x, y;
    // Velocity
    double vx, vy;
    // Acceleration
    double ax, ay;
    // Angle
    double a;
    // Angular velocity
    double w;
    // Mass
    double m;

} Object;

void model_init();
void model_update();

#endif
