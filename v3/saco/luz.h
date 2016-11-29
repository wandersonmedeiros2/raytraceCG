#include "cor.h"

#ifndef LUZ_H
#define LUZ_H

class _Luz{

	public:
		Cor3f cor;
		Ponto3f P;

		_Luz(Ponto3f pp,Cor3f cc);

};

typedef _Luz Luz;

#endif