#include "vetor.h"
#include "ponto.h"

#ifndef RAIO_H
#define RAIO_H

class Raio {

	public:

		// ponto inicial
		Ponto3f P0;
		//versor que guia a direcao do raio
		Vetor3f v;

		Raio(Ponto3f pp, Vetor3f vv);

		Ponto3f getPonto(float t);
		
};

#endif