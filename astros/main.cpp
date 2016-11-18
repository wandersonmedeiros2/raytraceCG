#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "sistema.h"


static int year = 0, day = 0, lum =0, t = 0;

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
   
   /*glColor3f (1.0, 1.0, 0.0);//amarelo
   glutWireSphere(1.0, 20, 16);   // draw sun 

   glRotatef ((GLfloat) year, 0.0, 1.0, 0.0);
   glTranslatef (2.0, 0.0, 0.0);
   glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
   glColor3f (0.0, 0.0, 0.6);//azul
   glutWireSphere(0.2, 10, 8);    // draw smaller planet */
   
   sis.getSistema(year,day);

   /*glRotatef ((GLfloat) day, 0.0, 1.0, 0.0);
   glTranslatef (0.5, 0.0, 0.0);
   //glRotatef ((GLfloat) lum, 0.0, 1.0, 0.0);//rodar a lua!?
   glColor3f (0.5, 0.5, 0.5);//cinza
   glutWireSphere(0.1, 10, 8); // lua adicionada

   glPopMatrix();
   
   glPushMatrix();

   glRotatef ((GLfloat) lum, 0.0, 1.0, 0.0);
   glTranslatef (1.2, 0.0, 0.0);
   glColor3f (1.0, 0.5, 0.0);//laranja
   glutWireSphere(0.1, 10, 8);// lua adicionada

   */
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
      case 'l':
         day = (day + 20);
         glutPostRedisplay();
         break;
      case 'L':
         day = (day - 20);
         glutPostRedisplay();
         break;
      case 'y':
         year = (year + 15);
         glutPostRedisplay();
         break;
      case 'Y':
         year = (year - 15);
         glutPostRedisplay();
         break;
      case 't':
         year = (year + 15);
         day = (day + 20);
         glutPostRedisplay();
         break;
      case 'R':
         sis.setSistema();
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