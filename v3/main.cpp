//g++ main.cpp -o main -lglut -lGLU -lGL -lm -std=c++11

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "sistema.cpp"

//ray tracing
#define WIDTH  800
#define HEIGTH  600

float Zp0 = -46;
float* data = new float[(WIDTH*HEIGTH)*3];

//coordenadas do obsevador
float X = 0;
float Y = -5;
float Z = 5;



static int t = 0;
void ray(); 
void init(void);
void display(void);
void keyboard (unsigned char key, int x, int y);

Sistema sis;

int main (int argc, char* argv[]){

   char* titulo = "RayTracing";
   
   glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGTH);
    glutCreateWindow(titulo);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);  

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    init ();
    glutMainLoop();

   return 0;
}

void init(void)
{

   sis.setSistema();

}

void display(void)
{

   sis.getSistema(t);
   ray();

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   glDrawPixels(WIDTH,HEIGTH,GL_RGB,GL_FLOAT,data);

   glutSwapBuffers();
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
      case 'w':
         Z += 1;
         break;
      case 27:
      	exit(0);
      	break;
      default:
         break;
   }
}


void ray(){

      //Luzes
   
   int qtdLuezes = 1;

   //ponto da luz
   Vetor3f Pluz(20,0,5);
   //Arranjo de luzes
   Luz** luzes    = new Luz*[qtdLuezes];
   luzes[0]       = new Luz(Pluz,Cor3f(1.0,1.0,1.0));
   // luzes[1]       = new Luz(Vetor3f(0,0,0),Cor3f(1.0,1.0,1.0));
  
   
   //ponto do observador
   Vetor3f P0(X,Y,Z);  

   //objetos
   //quantidade de objetos da cena
   int qtdObj = 5 ;

   //arranjo de objetos
   IObjeto** objetos = new IObjeto*[qtdObj];


  //Cor do objeto
  //ma.cor = Cor3f(0.5,0.5,0.5);

   //objetos[0] = sis.estrela;
   sis.getAstros(objetos);

   cout<<"Ray" <<endl;
   data = raytracing(qtdLuezes, luzes,qtdObj, objetos,P0,Zp0, HEIGTH,WIDTH);


}