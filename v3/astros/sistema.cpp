#include "sistema.h"


//Parte do astro:
//------------------------------------------------------------------------------
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

	if(this->astroCentral != NULL){
		this->distOrb  = (this->astroCentral->raio * 2) * aOrbita;
		this->angOrb = 1 / this->distOrb;
	}
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

	glPushMatrix();
	glRotatef (this->tempo*this->angOrb, 0.0, 1.0, 0.0);//rotação
	glTranslatef (this->distOrb, 0.0, 0.0);
	cout<<"distOrb: "<< this->distOrb<<" angOrb: "<<angOrb<<" Tempo: "<<this->tempo<<endl;
	//glRotatef (/*(GLfloat) d*/0, 0.0, 1.0, 0.0);//Para que isso? Rodar o planeta? Junto a lua em fila!
	glColor3f (0.0, 1.0, 0.6);//azul
	glutWireSphere(this->raio,this->numPCir,this->numDCir);

	if(this->qtdSatelites > 0){//Quando é que o satelite deixou de ser um astro?
		for(int i = 0; i < this->qtdSatelites; i++){
			this->satelites[i]->render();
		}
	}

	glPopMatrix();
}


//Parte do planeta:
//------------------------------------------------------------------------------

void Planeta::render(){

	/*for(int i = 0; i< this->qtdSatelites;i++){//isto não funciona!
		this->satelites[i]->angOrb = angOrb;
		this->satelites[i]->tempo  = tempo;
	}*/

	Astros::render();
}

Planeta::Planeta(int aQtdLuas,int aOrbita,Astros* aAstroCentral): Astros(0.15,0.25,aQtdLuas,aOrbita,aAstroCentral){
	this->criarSatelites();
}

void Planeta::criarSatelites(){
	if(this->qtdSatelites > 0){
		for(int i = 0; i < this->qtdSatelites; i++){
			this->satelites[i] = new Lua(i + 1,this);
		}
	}
}

//Parte do PlanetaGas:
//------------------------------------------------------------------------------

PlanetaGas::PlanetaGas(int aQtdLuas,int aOrbita,Astros* aAstroCentral):Astros(0.30,0.50,aQtdLuas,aOrbita,aAstroCentral){
	this->criarSatelites();
}

void PlanetaGas::criarSatelites(){
	if(this->qtdSatelites > 0){
		for(int i = 0; i < this->qtdSatelites; i++){
			this->satelites[i] = new Lua(i + 1,this);
		}
	}
}


//Parte da lua:
//------------------------------------------------------------------------------
Lua::Lua(int aOrbita,Astros* aAstroCentral) : Astros(0.05,0.10,0,aOrbita,aAstroCentral) {
	this->criarSatelites();
}

void Lua::criarSatelites(){
}


//Parte da estrela:
//------------------------------------------------------------------------------
Strela::Strela(int aQtdPlanetas) : Astros(0.70,1.20,aQtdPlanetas,0,NULL){
	this->criarSatelites();
}

void Strela::criarSatelites(){
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

	if(this->qtdSatelites > 0){
		for(int i = 0; i < this->qtdSatelites; i++)
			this->satelites[i]->render();
	}
}

//do sistema:
//------------------------------------------------------------------------------

Sistema::Sistema(){
}

void Sistema::setSistema(){
	//inicializar estrelas
	this->estrela = new Strela(4);
}

void Sistema::getSistema(double tempo){
	for(int i = 0; i< this->estrela->qtdSatelites;i++){
		this->estrela->satelites[i]->tempo  = tempo;
		for(int j=0;j<this->estrela->satelites[i]->qtdSatelites;j++){
			//this->estrela->satelites[i]->satelites[j]=tempo;//deveria funcionar mas ha uma falta de implementação!
			cout<<"Falta atualizar o tempo. Dado:["<<i<<" "<<j<<"]."<<endl;
		}
	}
	//Presiso gets internos!

	this->estrela->render();
}
