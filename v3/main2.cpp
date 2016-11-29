#include <cstdio>
#include <cstdlib>  
#include <cstring>
#include <iostream>
//#include "framework.h"
#include "raytracing.h"

using namespace std;


int main (int argc, char* argv[]){


	 Vetor3f v(1.0,0.0,0.0);
	 Vetor3f v2(0.0,1.0,0.0);
	
	 Vetor3f v3;
	 v3 = (v + v2);

	cout << v2.x << endl;
	cout << v2.y << endl;
	cout << v2.z << endl;
  
	cout << v3.x << endl;
	cout << v3.y << endl;
	cout << v3.z << endl;

	// Raio r(p,v3);
	
	// cout << r.v.x << endl;
	// cout << r.v.y << endl;
	// cout << r.v.z << endl;
	

	// ListaOrdenada ord();

	// ord.inserir(1, 3);
	// ord.inserir(3, 2);




	return 0;

} 

