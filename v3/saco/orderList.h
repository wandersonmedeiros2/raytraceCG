

#ifndef ORDERLIST_H
#define ORDERLIST_H
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
