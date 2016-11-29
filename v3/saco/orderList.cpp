#include "orderList.h"
#include <cstdio>

using namespace std;

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
