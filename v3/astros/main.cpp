//g++ main.cpp -o main -lglut -lGLU -lGL -lm -std=c++11

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "sistema.cpp"


static int t = 0;

void init(void);
void display(void);
void reshape (int w, int h);
void keyboard (unsigned char key, int x, int y);

Sistema sis;

int main (int argc, char* argv[]){


   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}

void init(void)
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);

   sis.setSistema();

}

void display(void)
{

   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);
   glPushMatrix();

   sis.getSistema(t);

   glPopMatrix();
   glutSwapBuffers();
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 300.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (1.0, 20.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 't':
         t=t+20;
         glutPostRedisplay();
         break;
      case 'r':
         sis.setSistema();
         glutPostRedisplay();
         break;
      case 27:
      	exit(0);
      	break;
      default:
         break;
   }
}
