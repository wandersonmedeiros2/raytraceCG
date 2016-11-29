#include"vetor.h"


VetorException::VetorException(char* aMSg)	{
			this->msg = aMSg;
		
}

const char*VetorException::what() const throw(){

	return msg;

}

template<typename T>
Vetor<T> Vetor<T>::operator*(const float &c){

		return Vetor<T>(this->x * c,this->y * c,this->z * c);
}



template<typename T>
Vetor<T> Vetor<T>::operator*(const Vetor<T> &v){

	return Vetor<T>( ((this->y * v.z) - (this->z * v.y)) 
					 , ((this->x * v.z) - (this->z * v.x)) ,
					 ((this->x * v.y) - (this->y * v.x)) 
				  );
}


template<typename T>
Vetor<T> Vetor<T>::operator*=(const Vetor<T> &v){

	 Vetor<T> d( ((this->y * v.z) - (this->z * v.y)) 
					 , ((this->x * v.z) - (this->z * v.x)) ,
					 ((this->x * v.y) - (this->y * v.x)) 
				  );

	 this->x = d.x;
	 this->y = d.y;
	 this->z = d.z;
	 return *this;
}



template<typename T>
Vetor<T> Vetor<T>::operator*=(const float &c){

	 x *= c;
	 y *= c;;
	 z *= c;;
	 return *this;
}



template<typename T>
Vetor<T> Vetor<T>::operator-(const Vetor<T> &v){

	return Vetor<T>(this->x - v.x,this->y - v.y,this->z - v.z);
}


template<typename T>
Vetor<T> Vetor<T>::operator-(){

	return Vetor<T>( -this->x, -this->y ,-this->z);
}

template<typename T>
Vetor<T> Vetor<T>::operator-(const T &c){

	throw VetorException("Operador não aplicável");

}


template<typename T>
Vetor<T> Vetor<T>::operator-=(const Vetor<T> &v){

	x -=  v.x;
	y -= v.y;
	z -= v.z;
	return *this;
}



template<typename T>
Vetor<T> Vetor<T>::operator-=(const T &c){

	throw VetorException("Operador não aplicável");
}	

template<typename T>
Vetor<T> Vetor<T>::operator+(const Vetor<T> &v){

	return Vetor<T>(this->x + v.x,this->y + v.y,this->z + v.z);
}


template<typename T>
Vetor<T> Vetor<T>::operator+(const T &c){

	throw VetorException("Operador não aplicável");

}


template<typename T>
Vetor<T> Vetor<T>::operator+=(const Vetor<T> &v){

	x +=  v.x;
	y += v.y;
	z += v.z;
	return *this;
}


template<typename T>
Vetor<T> Vetor<T>::operator+=(const T &c){

	throw VetorException("Operador não aplicável");
}


template<typename T>
Vetor<T> Vetor<T>::operator/(const T &c){

	throw VetorException("Operador não aplicável");

}		
		
template<typename T>
Vetor<T> Vetor<T>::operator/=(const T &c){

	throw VetorException("Operador não aplicável");
}		


template<typename T>
float Vetor<T>::escalar(const Vetor<T> &v){

	return ((this->x * v.x) + (this->y * v.y) + (this->z * v.z));

}

template<typename T>
float Vetor<T>::modulo(){

	return sqrt(pow(this->x,2.0) + pow(this->y,2.0) + pow(this->z,2.0));

}


template<typename T>
Vetor<float> Vetor<T>::getVersor(){
	
	Vetor<float> vu;
	float mm = this->modulo();	
		
	vu.x = (this->x/mm);
	vu.y = (this->y/mm);
	vu.z = (this->z/mm);
	
	return vu;
}


float angulo(Vetor3f v1,Vetor3f v2){

	Vetor<float>  vu1 = v1.getVersor();
	Vetor<float>  vu2 = v2.getVersor();

	float cosTeta = (vu1.escalar(vu2));
	
	return acos(cosTeta);
	return 0;

}

