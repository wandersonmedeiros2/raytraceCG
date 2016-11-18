#include "sistema.h"

Astros::Astros(double aMin, double aMax, int aQtdSatelites, int aOrbita, Astros* aAstroCentral){

	this->numPCir = 20; 
	this->numDCir = 16;

    this->astroCentral = aAstroCentral;
    
    this->max = aMax;
	this->min = aMin;

	this->qtdSatelites = aQtdSatelites;

	if(this->qtdSatelites > 0)
		this->satelites = new Astros*[this->qtdSatelites];
	else
		this->satelites = NULL;
		
	this->raio = calcularRaio();

	///*

	if(this->astroCentral != NULL)
		this->distOrb  = (this->astroCentral->raio * 2) * aOrbita;

}



double Astros::calcularRaio(){

	if(min > max){
		double A;
		A=this->min;
		this->min = this->max;
		this->max=A;
	}
	return ( ((double)rand()/(double)(RAND_MAX))*(this->max-this->min) )+this->max;

}


void Astros::render(){

	double y = ((this->angOrb/this->distOrb));
		if (y > 360)
			y = y - 360;

	double d = ((this->day/this->distOrb));

		if (d > 360)
			d = d - 360;
	
	glPushMatrix();
	glRotatef ((GLfloat) y , 0.0, 1.0, 0.0);
	glTranslatef (this->distOrb, 0.0, 0.0);
	glRotatef ((GLfloat) d, 0.0, 1.0, 0.0);
	glColor3f (0.0, 1.0, 0.6);//azul
	glutWireSphere(this->raio,this->numPCir,this->numDCir);
	//*/
	cout<< "render astro: " << this->t << endl;

	if(this->qtdSatelites > 0){
		for(int i = 0; i < this->qtdSatelites; i++){
			this->satelites[i]->render();
		}
	}

	glPopMatrix();

}



void Planeta::render(){

	for(int i = 0; i< this->qtdSatelites;i++)
	{
		this->satelites[i]->angOrb = angOrb;
		this->satelites[i]->day  = day;
	}

	Astros::render();

}




Lua::Lua(int aOrbita,Astros* aAstroCentral) : Astros(0.05,0.10,0,aOrbita,aAstroCentral) {

	this->criarSatelites();
	this->t = "Lua"; 
	cout<< "Criou " << this->t << endl;
}

void Lua::criarSatelites(){
	cout<< "Lua não tem satelites"  << endl;
}


Planeta::Planeta(int aQtdLuas,int aOrbita,Astros* aAstroCentral): Astros(0.15,0.25,aQtdLuas,aOrbita,aAstroCentral){

	this->criarSatelites();
	this->t = "Planeta";
	cout<< "Criou " << this->t <<endl;
}


void Planeta::criarSatelites(){

	cout << "Criando Luas" << endl;
	if(this->qtdSatelites > 0){

		for(int i = 0; i < this->qtdSatelites; i++){
			this->satelites[i] = new Lua(i + 1,this);
		}
	}
}


PlanetaGas::PlanetaGas(int aQtdLuas,int aOrbita,Astros* aAstroCentral):Astros(0.30,0.50,aQtdLuas,aOrbita,aAstroCentral){

	this->criarSatelites();
	this->t = "Planeta gas";
	cout<< "Criou " << this->t <<endl;
}

void PlanetaGas::criarSatelites(){

	cout << "Criando Luas" << endl;
	if(this->qtdSatelites > 0){

		for(int i = 0; i < this->qtdSatelites; i++){
			this->satelites[i] = new Lua(i + 1,this);
		}
	}
}

Strela::Strela(int aQtdPlanetas) : Astros(0.70,1.20,aQtdPlanetas,0,NULL){

	this->criarSatelites();
	cout<< "Criou estrela" << endl;
	this->t = "Strela";

}


void Strela::criarSatelites(){

	cout << "Criando planetas" << endl;
	//incializa os planetas
	if(this->qtdSatelites > 0){

   		//glColor3f (0.0, 1.0, 0.6);//azul
		this->satelites[0] = new Planeta(0,1,this);
		this->satelites[1] = new Planeta(1,2,this);
		this->satelites[2] = new PlanetaGas(3,5,this);
		this->satelites[3] = new PlanetaGas(4,8	,this);

	}


}


void Strela::render(){

	glColor3f (1.0, 1.0, 0.0);//amarelo
	glutWireSphere(this->raio,this->numPCir,this->numDCir);
	cout<< "render astro: " << this->t << endl;

	if(this->qtdSatelites > 0){
		for(int i = 0; i < this->qtdSatelites; i++)
			this->satelites[i]->render();
	}

}


Sistema::Sistema(){

	cout << "Criou sistema" << endl;

}


void Sistema::setSistema(){

	cout<< "Executando setSistema " << endl;
	//inicializar estrelas
	this->estrela = new Strela(4);

}


void Sistema::getSistema(double angOrb, double day){

	for(int i = 0; i< this->estrela->qtdSatelites;i++)
	{
		this->estrela->satelites[i]->angOrb = angOrb;
		this->estrela->satelites[i]->day  = day;
	}
	
	this->estrela->render();

}
