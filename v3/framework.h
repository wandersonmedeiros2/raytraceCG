#include "vetor.cpp"


#ifndef FRAMEWORK_H
#define FRAMEWORK_H

using namespace std;

template<typename T>
class Cor
{
	public:
		T R; //RED
		T G; //GREEN
		T B; //BLUE
		Cor() : R(T(0)),G(T(0)),B(T(0)) {}
		Cor(T rr, T gg, T bb) : R(rr),G(gg),B(bb) {}
};

typedef struct Cor<int> Cor3i;
typedef struct Cor<float> Cor3f;


struct _Material{

	float ka; //ambiente 
	float kd; //difuso 
	float ks; //especular
	float n; //especularidade
	Cor3f cor; //cor material
};

typedef struct _Material Material;


class Raio {

	public:

		// ponto inicial
		Vetor3f P0;
		//versor que guia a direcao do raio
		Vetor3f v;

		Raio(Vetor3f pp, Vetor3f vv);

		Vetor3f getPonto(float t);
		
};

class _Luz{

	public:
		Cor3f cor;
		Vetor3f P;

		_Luz(Vetor3f pp,Cor3f cc);

};

typedef _Luz Luz;


class IObjeto{

	public:
		float t1 ;
		float t2 ;	
		Material material;
		virtual bool intersect(Raio ray) = 0;
		virtual Vetor3f normal(Vetor3f P) = 0;
		Vetor3f normal(float t,Raio ray);
		Cor3f phong(Vetor3f P0,Vetor3f P,int qtdLig,Luz* luzes);
		void setMaterial(IObjeto &obj, Material &m);
		
		~IObjeto(){}

};


class Esfera : public IObjeto{

	public:

		//centro da esfera
		Vetor3f Pc;
		//raio da esfera
		float r;
		
		Esfera();

		Esfera(Vetor3f cc, float rr);

		Esfera(Vetor3f cc, float rr, Material mm);


		bool intersect(Raio ray);

		Vetor3f normal(Vetor3f P);

};



struct NoList {

	int key;
	float valor;
	float valor2;
	NoList* prox;

};

class ListaOrdenada{

	private:

		struct  NoList* ail;
		struct  NoList* t;

		void buscaValor(float aValor,NoList** ant,NoList** pont);

		void buscaKey(int aKey,NoList** ant,NoList** pont);

	public:

		int size;

		ListaOrdenada();

		void inserir(int key, float aValor);

		void inserir(int key, float aValor, float aValor2);

		void remover(int key, float* aValor);

		void remover(float* aValor,int* aKey);

		void remover(float* aValor,float* aValor2,int* aKey);

		void clear();

		void printLista();
		
};


#endif
