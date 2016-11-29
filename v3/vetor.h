#include <cmath> 
#include <exception>

#ifndef VETOR_H	
#define VETOR_H

using namespace std;

class VetorException: public exception
{
	private:
		char* msg;
	public:
		VetorException(char* aMSg);
  		virtual const char* what() const throw();
};



template<typename T>
class Vetor {

	public:
		T x,y,z;
		Vetor() : x(T(0)),y(T(0)),z(T(0)) {}
		Vetor(T xx) : x(xx),y(xx),z(xx) {}
		Vetor(T xx, T yy, T zz) : x(xx),y(yy),z(zz) {}
		Vetor(Vetor<T> v1, Vetor<T> v2) : x(v2.x - v1.x),y(v2.y - v1.y),z(v2.z - v1.z) {}
		

		Vetor<T> operator*(const float &c);

		Vetor<T> operator*(const Vetor<T> &v);

		Vetor<T> operator*=(const Vetor<T> &v);

		Vetor<T> operator*=(const float &c);

		Vetor<T> operator-(const Vetor<T> &v);

		Vetor<T> operator-();

		Vetor<T> operator-(const T &c);

		Vetor<T> operator-=(const Vetor<T> &v);

		Vetor<T> operator-=(const T &c);

		Vetor<T> operator+(const Vetor<T> &v);

		Vetor<T> operator+(const T &c);

		Vetor<T> operator+=(const Vetor<T> &v);

		Vetor<T> operator+=(const T &c);

		Vetor<T> operator/(const T &c);

		Vetor<T> operator/=(const T &c);

		float escalar(const Vetor<T> &v);
		
		float modulo();

		Vetor<float> getVersor();

};


typedef Vetor<float> Vetor3f;
typedef Vetor<int> Vetor3i;

float angulo(Vetor3f v1,Vetor3f v2);

//#include"vetor.cpp"


#endif
