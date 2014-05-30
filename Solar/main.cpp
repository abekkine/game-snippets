#include <GL/glut.h>

#include "render.h"
#include "model.h"

unsigned int step_mode = 0;
unsigned int step_go = 0;
unsigned int drop_tail = 0;
int selected_planet = 0;
int pov_planet = 0;
GLfloat light_position[4];

void idle() {

	// Background tasks.
    model_update();
}

void display(void) {

    if( ! drop_tail ) {
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

	render();

	glutSwapBuffers();
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {

	// Process standard keys.
	x = x;
	y = y;
	switch(key) {
		case 27:
        case 'q':
			exit(0);
			break;

        case 't':
            drop_tail ^= 1;
            break;

        case 's':
            step_mode ^= 1;
            break;

        case 'v':
            pov_planet ^= 1;
            break;

        case 'p':
            selected_planet++;
            selected_planet %= NUM_PLANETS;
            break;

        case 32:
            step_go = 1;
            break;
	}
}

void special(int key, int x, int y) {

	// TODO : To process special keys.
	key = key;
	x = x;
	y = y;
}

void reshape(int width, int height) {

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.375, 0.375, 0.0);
}

void visibility(int visible) {

	// TODO : For visibility related processing needs...
	visible = visible;
}

void motion(int x, int y) {

	// TODO : For mouse motion handling...
	x = x;
	y = y;
}

void mouse(int button, int state, int x, int y) {

	// TODO : For mouse button & motion handling...
	button = button;
	state = state;
	x = x;
	y = y;
}

void init(void) {

	// Simple lighting setup.
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat mat_shininess[] = { 50 };
	light_position[0] = 0.0;
	light_position[1] = 0.0;
	light_position[2] = 0.0;
	light_position[3] = 1.0;

	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	glColorMaterial(GL_FRONT_AND_BACK, GL_DIFFUSE);
	glEnable(GL_COLOR_MATERIAL);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutReshapeFunc(reshape);
	glutVisibilityFunc(visibility);
	glutIdleFunc(idle);
	glutPassiveMotionFunc(motion);
	glutMotionFunc(motion);
	glutMouseFunc(mouse);

    model_init();
}

int main(int argc, char** argv) {

	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("Glut Window for SVG Rendering");

	init();

	glutMainLoop();

	return 0;
}
