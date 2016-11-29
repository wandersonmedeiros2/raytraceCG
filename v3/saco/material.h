#include"cor.h"


#ifndef MATERIAL_H
#define MATERIAL_H
struct _Material{

	float ka; //ambiente 
	float kd; //difuso 
	float ks; //especular
	float n; //especularidade
	Cor3f cor; //cor material
};

typedef struct _Material Material;

#endif