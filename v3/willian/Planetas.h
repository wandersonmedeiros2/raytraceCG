#include "math.h"

class DataTamanho
{
public:
	int numPCir = 20; 
	int numDCir = 16;

	double Lua[2]     ={   0.05   ,   0.10   };
	double Plan[2]    ={   0.15   ,   0.25   };
	double PlanGas[2] ={   0.30   ,   0.50   };
	double Strela[2]  ={   0.70   ,   1.20   };
};

class Astros
{
public:
	double Raio;
	double distOrb = 0;
	double angOrb = 0;

	double Random(double min,double max){
		if(min > max){
			double A;
			A=min;
			min=max;
			max=A;
		}
		return ( ((double)rand()/(double)(RAND_MAX))*(max-min) )+max;
	};

};

class Lua : public Astros, public DataTamanho
{
public:
	void setLua(){
		Raio = Random(DataTamanho::Lua[0],DataTamanho::Lua[1]);
	};
	void getLua(){
		glutWireSphere(Raio,DataTamanho::numPCir,DataTamanho::numDCir);
	};
};

class Planeta : public Astros, public DataTamanho
{
public:
	void setPlan(){
		Raio = Random(DataTamanho::Plan[0],DataTamanho::Plan[1]);
	};
	void getPlan(){
		glutWireSphere(Raio,DataTamanho::numPCir,DataTamanho::numDCir);
	};
};

class PlanetaGas : public Astros, public DataTamanho
{
public:
	void setPlanGas(){
		Raio = Random(DataTamanho::PlanGas[0],DataTamanho::PlanGas[1]);
	};
	void getPlanGas(){
		glutWireSphere(Raio,DataTamanho::numPCir,DataTamanho::numDCir);
	};
};

class Strela : public Astros, public DataTamanho
{
public:
	void setStrela(){
		Raio = Random(DataTamanho::Strela[0],DataTamanho::Strela[1]);
	};
	void getStrela(){
		glutWireSphere(Raio,DataTamanho::numPCir,DataTamanho::numDCir);
	};
};

class Sistema: public Lua, public Planeta, public PlanetaGas, public Strela
{
public:
	void setSistema(){
		setLua();
		setPlan();
		setPlanGas();
		setStrela();
	};
	void getSistema(){
		getLua();
		getPlan();
		getPlanGas();
		getStrela();
	};
};
/*
class Planetas
{
public:
	int numPCir = 20; 
	int numDCir = 16;

	DataTamanho Astros;


	double Random(double min,double max){
		if(min > max){
			double A;
			A=min;
			min=max;
			max=A;
		}
		return ( ((double)rand()/(double)(RAND_MAX))*(max-min) )+max;
	};


	void Lua(){
		glutWireSphere(Random(Astros.Lua[0],Astros.Lua[1]),numPCir, numDCir);
	};
};
*/