#include "framework.h"	


////////////// RAIO //////////////////////////

Raio::Raio(Vetor3f pp, Vetor3f vv){

	this->P0 = pp;
	this->v  = vv.getVersor();
}

Vetor3f Raio::getPonto(float t){

	Vetor3f p = ((this->v*t) + this->P0);

	return p;
}


////////////// LUZ //////////////////////////
_Luz::_Luz(Vetor3f pp,Cor3f cc){

	this->P = pp;
	this->cor = cc;

}


////////////// OBJETO //////////////////////////

Vetor3f IObjeto::normal(float t,Raio ray){

			Vetor3f pn = (ray.getPonto(t));
			return normal(pn);
}

void IObjeto::setMaterial(IObjeto &obj, Material &m){

	obj.material = m;

}

		
		
Cor3f IObjeto::phong(Vetor3f P0,Vetor3f P,int qtdLig,Luz* luzes){

			Cor3f I(0,0,0);
			float fatt = 1;

	
			I.R = material.ka * material.cor.R; //Ia.Ka.Cd
			I.G = material.ka * material.cor.G; //Ia.Ka.Cd
			I.B = material.ka * material.cor.B; //Ia.Ka.Cd


			//vetor distancia
			Vetor3f d = (P,P0);
			float modD = d.modulo();
			//fatt = (1/(modD * modD));
		
			//normal ao ponto
			Vetor3f N = normal(P);
			N = N.getVersor();

			for(int i = 0; i< qtdLig;i++){
				
				//vetor que vai do ponto de interceção até a luz
				Vetor3f pl = (luzes[i].P - P);
				Vetor3f V = (P0 - P);
				V = V.getVersor();
				

				//normal ao ponto
				Vetor3f N = normal(P);

				float angNpl = angulo(N,pl.getVersor());
				float angVN = angulo(N,V);

				Vetor3f R(0,0,0);

				//fatt = 1/(pl.escalar(pl));

				//difusa
				float cosPpl = angulo(pl.getVersor(),P.getVersor());
				I.R += (luzes[i].cor.R * material.kd * material.cor.R * cosPpl) * fatt;
				I.G += (luzes[i].cor.G * material.kd * material.cor.G * cosPpl) * fatt;
				I.B += (luzes[i].cor.B * material.kd * material.cor.B * cosPpl) * fatt;

				//especular
				float cosVR = pow(cos(angNpl - angVN),material.n);

				I.R += (luzes[i].cor.R * material.ks * material.cor.R * cosVR) * fatt;
				I.G += (luzes[i].cor.G * material.ks * material.cor.G * cosVR) * fatt;
				I.B += (luzes[i].cor.B * material.ks * material.cor.B * cosVR) * fatt;

			}
				
				// I.R += (material.ks * material.cor.R);
				// I.G += (material.ks * material.cor.G);
				// I.B += (material.ks * material.cor.B);							

			return I;

}
		

////////////// ESFERA //////////////////////////		
Esfera::Esfera(){

}


Esfera::Esfera(Vetor3f cc, float rr){

	this->Pc = cc;
	this->r = rr;
	this->t1 = 0;
	this->t2 = 0;
	this->material.ka = 0;
	this->material.kd = 0;
	this->material.ks = 0;
	this->material.n = 1;
	this->material.cor = Cor3f(1.0,1.0,1.0);
}

Esfera::Esfera(Vetor3f cc, float rr, Material mm){

	this->Pc = cc;
	this->r = rr;
	this->t1 = 0;
	this->t2 = 0;
	this->material = mm;
}


bool Esfera::intersect(Raio ray){

	//distancia de um ponto ao centro da esfera
	float A = ray.v.escalar(ray.v);

	float B = 2*(ray.v.escalar(ray.P0) - ray.v.escalar(this->Pc));

	float C = ray.P0.escalar(ray.P0) - (2*(ray.P0.escalar(this->Pc)) + this->r * this->r) ;

	float D = ((B*B) - (4*(A * C)));

	if(D <= 0){
		return false;
	}

	t1 = ((-B) - sqrt(D))/(2*A);
	t2 = ((-B) + sqrt(D))/(2*A);
	return true;
	
}

Vetor3f Esfera::normal(Vetor3f P){

	return Vetor3f( ((2*P.x) - (2*Pc.x)), 
				  ((2*P.y) - (2*Pc.y)),
				  ((2*P.z) - (2*Pc.z))
				);

}

////////////// LISTA ORDENADA //////////////////////////


ListaOrdenada::ListaOrdenada(){

	this->size = 0;
	this->ail = new NoList();
	this->ail->prox = NULL;
	this->ail->valor = -1;
	this->t = NULL;

}		

void ListaOrdenada::buscaValor(float aValor,NoList** ant,NoList** pont){
			
	NoList* ptr = this->ail->prox; 			
	*ant = this->ail;
	*pont = NULL;

	while(ptr != NULL){
		if(ptr->valor < aValor){
			*ant = ptr;
			ptr = ptr->prox;
		}
		else{
			if(ptr->valor == aValor){
				*pont = ptr;
			}
			ptr = NULL;
		}

	}
}


void ListaOrdenada::inserir(int key, float aValor){

	NoList* res;
	NoList* ant;

	buscaValor(aValor,&ant,&res);

	if(res == NULL){
			
		NoList* novo = new NoList();

		novo->key = key;
		novo->valor = aValor;
		novo->valor2 = 0;
		novo->prox = ant->prox;
		ant->prox = novo;
		this->size++;
	}			
}	


void ListaOrdenada::inserir(int key, float aValor, float aValor2){

	NoList* res;
	NoList* ant;

	buscaValor(aValor,&ant,&res);

	if(res == NULL){
			
		NoList* novo = new NoList();

		novo->key = key;
		novo->valor = aValor;
		novo->valor2 = aValor2;
		novo->prox = ant->prox;
		ant->prox = novo;
		this->size++;
	}
			
}

void ListaOrdenada::remover(int key, float* aValor){

	NoList* res;
	NoList* ant;
	
	buscaKey(key,&ant,&res);
	if(res != NULL){
		*aValor = res->valor;
		ant->prox = res->prox;
		delete(res);
		this->size --;
	}

}

void ListaOrdenada::remover(float* aValor,int* aKey){
			
	NoList* res = NULL;
	res = this->ail->prox;

	if(res != NULL){
		*aValor = res->valor;
		*aKey = res->key;
		this->ail->prox = this->ail->prox->prox;
		delete(res);
		this->size --;
	}

}

void ListaOrdenada::remover(float* aValor,float* aValor2,int* aKey){
			
	NoList* res = NULL;
	res = this->ail->prox;

	if(res != NULL){
		*aValor = res->valor;
		*aKey = res->key;
		*aValor2 = res->valor2;
		this->ail->prox = this->ail->prox->prox;
		delete(res);
		this->size --;
	}

}

void ListaOrdenada::clear(){
	int k;
	float t;

	while(this->size > 0){
		remover(&t,&k);
	}

}		

void ListaOrdenada::printLista(){

	NoList* ptr = this->ail->prox; 			

	while(ptr != NULL){

		printf("(%d,%f)->", ptr->key,ptr->valor);
	    ptr = ptr->prox;	
	}
	printf("\n"); 

}

void ListaOrdenada::buscaKey(int aKey,NoList** ant,NoList** pont){
			
	NoList* ptr = this->ail->prox; 			
	*ant = this->ail;
	*pont = NULL;

	while(ptr != NULL){
		if(ptr->key == aKey){
			*pont = ptr;
			ptr = NULL;
		}
		else
			ptr = ptr->prox;	
	}
}
	
