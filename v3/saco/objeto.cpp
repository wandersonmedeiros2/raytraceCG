#include"objeto.h"

Vetor3f IObjeto::normal(float t,Raio ray){

			Ponto3f pn = (ray.getPonto(t));
			return normal(pn);
}

void IObjeto::setMaterial(IObjeto &obj, Material &m){

	obj.material = m;

}

		
		
Cor3f IObjeto::phong(Ponto3f P0,Ponto3f P,int qtdLig,Luz* luzes){

	//P0 - ponto do observado
  //P - ponto de intersessão

	Cor3f I(0,0,0);
	float fatt = 1;


	for(int i = 0; i< qtdLig;i++){

		//Luz Ambiente
		I.R = material.ka * luzes[i].cor.R; //Ia.Ka.Cd
		I.G = material.ka * luzes[i].cor.G; //Ia.Ka.Cd
		I.B = material.ka * luzes[i].cor.B; //Ia.Ka.Cd

		//vetor distancia
		Vetor3f d = (P,P0);
		float modD = d.modulo();
		//fatt = (1/(modD * modD));
		
		//normal ao ponto
		Vetor3f N = normal(P);
		N = N.getVersor();

		
		//vetor que vai do ponto de interceção até a luz 
		Vetor3f L(P,luzes[i].P);
		Vetor3f R(0,0,0);

	
		float cosTheta = N.escalar(L);

		R = ((2 * (N * (N.escalar(L)))) - L);
		float cosPhi = (R.escalar(N));


		

		
		I.R += (fatt * luzes[i].cor.R)  * ( (material.kd * cosTheta) + 	(material.ks * (pot(cosPhi,material.n)) )	);


		//difusa
		//float cosTheta =	 P.cosAngle(pl);
/*
		I.R += (luzes[i].cor.R * material.kd * cosTheta) * fatt;
		I.G += (luzes[i].cor.G * material.kd * cosTheta) * fatt;
		I.B += (luzes[i].cor.B * material.kd * cosTheta) * fatt;

		//especular
		//float cosVR = pow(cos(angNpl - angVN),material.n);
		
		
		

		I.R += (luzes[i].cor.R * material.ks * material.cor.R * cosPhi) * fatt;
		I.G += (luzes[i].cor.G * material.ks * material.cor.G * cosPhi) * fatt;
		I.B += (luzes[i].cor.B * material.ks * material.cor.B * cosPhi) * fatt;

*/

	}

		
		
		
	return I;

}
		

