#include "raio.h"


Raio::Raio(Ponto3f pp, Vetor3f vv){

	this->P0 = pp;
	this->v  = vv.getVersor();
}

Ponto3f Raio::getPonto(float t){

	Ponto3f p = ((this->v*t) + this->P0);

	return p;
}
		

