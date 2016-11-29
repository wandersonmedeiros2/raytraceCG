#include"esfera.h"
Esfera::Esfera(Ponto3f cc, float rr){

	this->Pc = cc;
	this->r = rr;
	this->t1 = 0;
	this->t2 = 0;
	this->material.ka = 0;
	this->material.kd = 0;
	this->material.ks = 0;
	this->material.n = 1;
	this->material.cor(1,1,1);
}

Esfera::Esfera(Ponto3f cc, float rr, Material mm){

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

Vetor3f Esfera::normal(Ponto3f P){

	return Vetor3f( ((2*P.x) - (2*Pc.x)), 
				  ((2*P.y) - (2*Pc.y)),
				  ((2*P.z) - (2*Pc.z))
				);

}
