#include <cstdio>
#include <cstdlib>  
#include <cstring>
#include <iostream>
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glut.h>
#include "raytracing.h"
	
#define WIDTH  800
#define HEIGTH  600

using namespace std;

void keyboard (unsigned char key, int x, int y);


//posição do obvervador
float X = 0;
float Y = -15;
float Z = 30;

float Zp0 = -46;

//posição da luz
float Xl = -30  ;
float Yl = -120;
float Zl = 5;

Material ma;

float* data = new float[(WIDTH*HEIGTH)*3];

void display();

int main (int argc, char* argv[]){

	ma.ka = atof(argv[1]); //ambiente
	ma.kd = atof(argv[2]); // difuso
	ma.ks = atof(argv[3]); // specula
	ma.n  = atof(argv[4]); // speculariade do material;

	ma.cor = Cor3f(1.0,0.2,1.0);

	char* titulo = "RayTracing";
	
	glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGTH);
    glutCreateWindow(titulo);

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glutMainLoop();

  
	return 0;

} 

void display(){

		//Luzes
	
	int qtdLuezes = 1;

	//ponto da luz
	Vetor3f Pluz(Xl,Yl,Zl);
	//Arranjo de luzes
	Luz** luzes 	= new Luz*[qtdLuezes];
	luzes[0] 		= new Luz(Pluz,Cor3f(1.0,1.0,1.0));
	
	//ponto do observador
	Vetor3f P0(X,Y,Z);  

	//objetos
	//quantidade de objetos da cena
	int qtdObj = 1;

	//arranjo de objetos
	IObjeto** objetos = new IObjeto*[qtdObj];

	//objeto 1

	float r = 8  ;	

  //Cor do objeto
  //ma.cor = Cor3f(0.5,0.5,0.5);

	objetos[0] = new Esfera(Vetor3f(0,-15,0),r,ma);


	data = raytracing(qtdLuezes, luzes,qtdObj, objetos,P0,Zp0, HEIGTH,WIDTH);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawPixels(WIDTH,HEIGTH,GL_RGB,GL_FLOAT,data);

    glutSwapBuffers();

}

void keyboard (unsigned char key, int x, int y)
{
   float inc = 10;
   switch (key) {
      case 't':
         //t=t+20;
         glutPostRedisplay();
         break;
      case 27:
      	exit(0);
      	break;
//w
    	case 'w': 
    		Zl += inc;
    		glutPostRedisplay();
    		break;
    	case 'W': 
    		Zl -= inc;
    		glutPostRedisplay();
    		break;

    	//d
    	case 'd': 
    		Xl += inc;
    		glutPostRedisplay();
    		break;
    	case 'D': 
    		Xl -= inc;
    		glutPostRedisplay();
    		break;
    	//a
    	case 'a': 
    		Yl += inc;
    		glutPostRedisplay();
    		break;
    	case 'A': 
    		Yl -= inc;
    		glutPostRedisplay();
    		break;
      case 'r': 
        Xl = 30;
        Yl = -20;
        Zl = 5;
        X = 0;
        Y = -15;
        Z = 19;
        glutPostRedisplay();
        break;


      default:
         break;
   }
}
