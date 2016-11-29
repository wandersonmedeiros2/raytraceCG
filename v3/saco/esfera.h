#include"objeto.h"
#include"material.h"


class Esfera : public IObjeto{

	public:

		//centro da esfera
		Ponto3f Pc;
		//raio da esfera
		float r;

		Esfera(Ponto3f cc, float rr);

		Esfera(Ponto3f cc, float rr, Material mm);


		bool intersect(Raio ray);

		Vetor3f normal(Ponto3f P);

};
