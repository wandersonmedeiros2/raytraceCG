#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <GL/gl.h>

using namespace std;

#ifndef SISTEMA_H
#define SISTEMA_H



class Astros{

	private:
		//Usado para calcular o raio
		double calcularRaio();
	
	public:
		Astros* astroCentral;
		int numPCir; 
		int numDCir;
		double distOrb;
		double min;
		double max;
		double raio;
		double angOrb;
		double day;
	    char* t;
		int qtdSatelites;
		Astros** satelites;
		Astros(double aMin, double aMax, int aQtdSatelites, int aOrbita,Astros* aAstroCentral);
		void render();
		virtual void criarSatelites() = 0;	
};



class Lua : public Astros
{
	public:
		Lua(int aOrbita,Astros* aAstroCentral);	
		void criarSatelites();	

};


class Planeta : public Astros
{
	public:
		Planeta(int aQtdLuas,int aOrbita,Astros* aAstroCentral);
		void criarSatelites();	
		void render();	
};



class PlanetaGas : public Astros
{
	public:
		PlanetaGas(int aQtdLuas,int aOrbita,Astros* aAstroCentral);
		void criarSatelites();
	
};

class Strela : public Astros
{

	public:
		Strela(int aQtdPlanetas);
		void criarSatelites();
		void render();
	
};

class Sistema
{
	protected:
		Strela* estrela;

	public:

		
	//public Lua, public Planeta, public PlanetaGas, public Strela
	Sistema();
	void setSistema();
	void getSistema(double angOrb, double day);
	void getSistema();
};

#endif
