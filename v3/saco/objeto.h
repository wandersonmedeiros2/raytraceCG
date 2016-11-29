#include"raio.h"
#include"material.h"
#include"luz.h"
#include"vetor.h"


#ifndef OBJETO_H
#define OBJETO_H

class IObjeto{

	public:
		float t1 ;
		float t2 ;	
		Material material;
		virtual bool intersect(Raio ray) = 0;
		virtual Vetor3f normal(Ponto3f P) = 0;
		Vetor3f normal(float t,Raio ray);
		Cor3f phong(Ponto3f P0,Ponto3f P,int qtdLig,Luz* luzes);
		void setMaterial(IObjeto &obj, Material &m);
		
		~IObjeto(){}

};

#endif
