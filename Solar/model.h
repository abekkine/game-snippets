#ifndef MODEL_H
#define MODEL_H

#define NUM_PLANETS 3

typedef struct {

    double x, y;
    double vx, vy;
    double ax, ay;
    double m;

} Object;

void model_init();
void model_update();

#endif
