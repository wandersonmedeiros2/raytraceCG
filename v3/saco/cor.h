
#ifndef COR_H
#define COR_H

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

#endif
