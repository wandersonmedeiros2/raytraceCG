#include "framework.cpp"

#ifndef RAYTRACING_H
#define RAYTRACING_H

float minDist( Raio ray, IObjeto *obj){

	Vetor3f d( ray.getPonto(obj->t1),ray.P0);
	float m1 = d.modulo();
	d = Vetor3f(ray.getPonto(obj->t2),ray.P0);
	float m2 = d.modulo();

	if(m1 <= m2)
		return m1;
	else
		return m2;
} 

float minDist( Raio ray, IObjeto *obj,float *t){

	Vetor3f d(ray.getPonto(obj->t1),ray.P0);
	float m1 = d.modulo();
	d = Vetor3f((ray.getPonto(obj->t2)),ray.P0);
	float m2 = d.modulo();

	if(m1 <= m2){
		*t = obj->t1;
		return m1; 
	}
	else{
		*t = obj->t2;
		return m2;
	}
}



float* raytracing(int luzc,Luz* luzv[],int objc, IObjeto* objv[],Vetor3f pobserver,int Zp0,int heigth, int width){

	ListaOrdenada lo;

	float* data = new float[(heigth*width)*3];

	//tela
	Cor3f im[heigth][width];


	//cor de fundo
	Cor3f fundo(0.2,0.2,0.2);

	//tela de visualização
	int min_w = pobserver.x - width/2;
	int max_w = pobserver.x + width	/2;
	int min_h = pobserver.y - heigth/2;
	int max_h = pobserver.y + heigth/2;
	int reg_w = -min_w;
	int reg_h = -min_h;


	//ponto de interseção
	float t0;
	for(int l = min_h; l < max_h; l++) {
		
		for(int c = min_w; c < max_w; c++) {
			
			//lança raio
			Vetor3f v = Vetor3f(l,c,pobserver.z - Zp0);
			Raio ray (pobserver,v);

			//verifica se o ha intercessão
			for(int k = 0; k < objc; k++){ 
	
				if(objv[k]->intersect(ray)){
					float d = minDist(ray,objv[k],&t0);
					lo.inserir(k,d,t0);

				}
					
			}
	
			int ky; float d; 
			if(lo.size > 0){
				lo.remover(&d,&t0,&ky);
				//cout << "ky" << ky <<endl;
				if(ky > -1)
					im[l+reg_h][c+reg_w] = objv[ky]->phong(pobserver,ray.getPonto(t0),luzc,*luzv);
				}
				else{
					im[l+reg_h][c+reg_w] = fundo;
				}

				lo.clear();
			}     
		}
			
		int dt = -1;
		for(int l = min_h; l < max_h; l++) {
			for(int c = min_w; c < max_w; c++) {
				Cor3f cor = im[l+reg_h][c+reg_w];
				dt++;
				data[dt] = cor.R;
				dt++;
				data[dt] = cor.G;
				dt++;
				data[dt] = cor.B;
			}
		}

		return data;
}

#endif